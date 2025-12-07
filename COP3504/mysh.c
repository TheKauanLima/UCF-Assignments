#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <unistd.h>    // fork()
#include <stdlib.h>    // exit()
#include <inttypes.h>  // intmax_t
#include <sys/wait.h>  // wait()
#include <string.h>    // strcspn(), strtok
#include <errno.h>     // ECHILD
#include <fcntl.h>     // O_RDONLY, open

#include "tokens.h"

#include "util.h"

#include "lex.c"

/* Parser lookahead */
token_t lookahead;

/* The lookahead's lexeme */
char *lexeme;

/* Consume one token from the lexer. */
void consume();

/* Command-line parser. */
void parse();

/* Command interpreter. */
void run_commands();

static void parse_start(void);
static void parse_pipes(void);
static void parse_command_nonterminal(void);
static void parse_program(command_t *cmd);
static void parse_redirects(command_t *cmd);


void consume()
{
    lookahead = yylex();
    lexeme = copystr(yytext);
}

int main(int argc, char **argv)
{
    parse();
    run_commands();
    free_commands();
    return 0;
}

void parse()
{
    consume();

    if (lookahead == END_OF_LINE)
        return;

    parse_start();
}

static void parse_start(void)
{
    parse_pipes();
    ensure(lookahead, END_OF_LINE);
}

static void parse_pipes(void)
{
    parse_command_nonterminal();

    while (lookahead == PIPE)
    {
        consume();
        parse_command_nonterminal();
    }
}

static void parse_command_nonterminal(void)
{
    command_t *cmd = add_command();
    parse_program(cmd);
    parse_redirects(cmd);
}

static void fatal_syscall(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

static void parse_program(command_t *cmd)
{
    int argc = 0;

    ensure(lookahead, STRING);
    cmd->argv[argc++] = lexeme;
    consume();

    while (lookahead == STRING)
    {
        if (argc >= MAX_ARGS - 1)
            fatal_syscall("too many arguments");

        cmd->argv[argc++] = lexeme;
        consume();
    }

    cmd->argv[argc] = NULL;
}

static void parse_redirects(command_t *cmd)
{
    if (lookahead == REDIRECT_IN)
    {
        consume();
        ensure(lookahead, STRING);
        cmd->in = lexeme;
        consume();
    }

    if (lookahead == REDIRECT_OUT)
    {
        consume();
        ensure(lookahead, STRING);
        cmd->out = lexeme;
        consume();
    }
}

static void setup_redirect_in(const char *filename)
{
    if (filename == NULL)
        return;

    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        fatal_syscall("open (input)");

    if (dup2(fd, STDIN_FILENO) < 0)
    {
        close(fd);
        fatal_syscall("dup2 (input)");
    }

    close(fd);
}

static void setup_redirect_out(const char *filename)
{
    if (filename == NULL)
        return;

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        fatal_syscall("open (output)");

    if (dup2(fd, STDOUT_FILENO) < 0)
    {
        close(fd);
        fatal_syscall("dup2 (output)");
    }

    close(fd);
}

static void wait_for_children(void)
{
    do
    {
        while (wait(NULL) > 0);
    } while (errno != ECHILD);
}

void run_commands()
{
    if (first_command == NULL)
        return;

    command_t *cmd1 = first_command;
    command_t *cmd2 = cmd1->next;

    if (!cmd2)
    {
        pid_t pid;
        switch (pid = fork())
        {
            case -1:
                fatal_syscall("fork");
                break;
            case 0:
                if (cmd1->in != NULL)
                    setup_redirect_in(cmd1->in);
                if (cmd1->out != NULL)
                    setup_redirect_out(cmd1->out);

                execvp(cmd1->argv[0], cmd1->argv);
                perror("execvp");
                _exit(EXIT_FAILURE);
                break;
            default:
                break;
        }

        wait_for_children();
        return;
    }

    if (cmd2->next)
        fatal_syscall("Only up to one pipe between two commands is supported");

    int pipefd[2];
    if (pipe(pipefd) == -1)
        fatal_syscall("pipe");

    pid_t pid1;
    switch (pid1 = fork())
    {
        case -1:
            fatal_syscall("fork");
            break;
        case 0:
            if (cmd1->in)
                setup_redirect_in(cmd1->in);

            if (dup2(pipefd[1], STDOUT_FILENO) == -1)
                fatal_syscall("dup2");

            close(pipefd[0]);
            close(pipefd[1]);

            execvp(cmd1->argv[0], cmd1->argv);
            perror("execvp");
            _exit(EXIT_FAILURE);
            break;
        default:
            break;
    }

    pid_t pid2;
    switch (pid2 = fork())
    {
        case -1:
            fatal_syscall("fork");
            break;
        case 0:
            if (cmd2->out)
                setup_redirect_out(cmd2->out);

            if (dup2(pipefd[0], STDIN_FILENO) == -1)
                fatal_syscall("dup2");

            close(pipefd[0]);
            close(pipefd[1]);

            execvp(cmd2->argv[0], cmd2->argv);
            perror("execvp");
            _exit(EXIT_FAILURE);
            break;
        default:
            break;
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait_for_children();
}