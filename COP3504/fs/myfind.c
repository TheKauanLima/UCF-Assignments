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

// Count '\n' characters in a file
static long countNewLines(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return -1;
    }
    long total = 0;
    char buf[8192]; // read buffer
    for (;;)
    {
        ssize_t n = read(fd, buf, sizeof(buf));
        if (n < 0) {
            close(fd);
            return -1;
        }
        if (n == 0) break;
        // count total new line characters
        for (ssize_t i = 0; i < n; i++) {
            if (buf[i] == '\n') total++;
        }
    }
    close(fd);
    return total;
}

// recursively process the path
static void processPath(char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) == -1)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // check if is a regular file
    if (S_ISREG(statbuf.st_mode))
    {
        if (showLines)
        {
            long lines = countNewLines(path);
            if (lines < 0)
                return;
            printf("%s\t%ld\n", path, lines);
        }
        else
            printf("%s\n", path);
        return;
    }

    // check if is a directory
    if (S_ISDIR(statbuf.st_mode))
    {
        printf("%s\n", path);

        DIR *dir = opendir(path);
        if (dir == NULL)
        {
            perror("opendir");
            exit(EXIT_FAILURE);
        }

        // read contents of directory
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            char* name = entry->d_name;
            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
                continue;

            char *curPath = path;
            struct dirent *curDir = entry;

            // len + separator + len + terminator
            int concatLen = strlen(curPath) + 1 + strlen(curDir->d_name) + 1;
            char *newPath = malloc(concatLen * sizeof(char));
            if (newPath == NULL) {
              perror("malloc");
              exit(EXIT_FAILURE);
            }
            snprintf(newPath, concatLen, "%s/%s", curPath, curDir->d_name);

            processPath(newPath);
            free(newPath);
        }
        closedir(dir);
        return;
    }
}

int main(int argc, char** argv)
{
    // ./myfind <path>
    if (argc == 2)
    {
        if (strcmp(argv[1], "-l") == 0)
            exit(EXIT_FAILURE);
        showLines = false;
        char *path = argv[1];
        processPath(path);
        return 0;
    }
    // ./myfind -l <path>
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-l") != 0)
            exit(EXIT_FAILURE);
        showLines = true;
        char *path = argv[2];
        processPath(path);
        return 0;
    }
    // any other usage
    else
        exit(EXIT_FAILURE);
}