#include <fcntl.h>         // O_RDONLY, O_WRONLY, O_CREAT, open
#include <errno.h>         // errno
#include <stdio.h>         // perror, fprintf
#include <dirent.h>        // opendir, readdir, DIR, struct dirent
#include <stdlib.h>        // exit
#include <sys/stat.h>      // stat
#include <assert.h>        // assert
#include <string.h>        // string.h
#include <unistd.h>        // read, write, close
#include <stdbool.h>       // bool

static bool showLines = false;

static long countNewLines(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return -1;
    }
    long total = 0;
    char buf[8192];
    for (;;)
    {
        ssize_t n = read(fd, buf, sizeof(buf));
        if (n < 0) {
            close(fd);
            return -1;
        }
        if (n == 0) break;
        for (ssize_t i = 0; i < n; i++) {
            if (buf[i] == '\n') total++;
        }
    }
    close(fd);
    return total;
}

static void processPath(char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
        return;

    if (S_ISREG(st.st_mode))
    {
        if (showLines)
        {
            long lines = countNewLines(path);
            if (lines < 0)
                return;
            printf("%s\t%ld\n", path, lines);
        }
        else
        {
            printf("%s\n", path);
        }
        return;
    }

    if (S_ISDIR(st.st_mode))
    {
        printf("%s\n", path);

        DIR *dir = opendir(path);
        if (dir == NULL)
            return;

        struct dirent *de;
        while ((de = readdir(dir)) != NULL)
        {
            char* name = de->d_name;
            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
                continue;

            char *curpath = path;
            struct dirent *curdir = de;

            // len + separator + len + terminator
            int concatlen = strlen(curpath) + 1 + strlen(curdir->d_name) + 1;
            char *newpath = malloc(concatlen * sizeof(char));
            if (NULL == newpath) {
              perror("malloc");
              exit(EXIT_FAILURE);
            }
            snprintf(newpath, concatlen, "%s/%s", curpath, curdir->d_name);

            processPath(newpath);
            free(newpath);
        }
        closedir(dir);
        return;
    }
}

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        showLines = false;
        char *path = argv[1];
        return 0;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-l") != 0)
            exit(EXIT_FAILURE);
        showLines = true;
        char *path = argv[2];
        return 0;
    }
    else
        exit(EXIT_FAILURE);
}