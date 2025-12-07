#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
    char* path = "my.out";
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0640);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int dupfd = dup2(fd, STDOUT_FILENO);
    if (dupfd == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    printf("This will be written to the file 'my.out'\n");

    close(fd);
    exit(EXIT_SUCCESS);
}