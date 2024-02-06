#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    const size_t BUF_SIZE = 1024;
    char buf[BUF_SIZE];
    buf[0] = '\0';

    if (argc != 2)
    {
        printf("supply a file to read\n");
        exit(1);
    }

    strcat(buf, "cat ");
    strcat(buf, argv[1]);

    // sanitizing the environment variable
    char *path = getenv("PATH");

    if (!path)
    {
        fprintf(stderr, "couldn't get value for PATH!");
        exit(EXIT_FAILURE);
    }

    printf("path is: %s\n", path);

    if (path != "/home/vagrant/.vscode-server/bin/abd2f3db4bdb28f9e95536dfa84d8479f1eb312d/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin")
    {
        char *decent_path = "/home/vagrant/.vscode-server/bin/abd2f3db4bdb28f9e95536dfa84d8479f1eb312d/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";

        if (setenv("PATH", decent_path, 1) != 0)
        {
            fprintf(stderr, "failed to set the environment value!");
            exit(EXIT_FAILURE);
        }
    }

    system(buf);
    return 0;
}

/*
Note
While this program will work for simple cases, it can be prone to command injection if used with untrusted input, because a user can potentially provide a filename that includes shell special characters or additional commands to execute arbitrary commands.
It's recommended to validate and sanitize inputs to avoid security vulnerabilities.
To make the program safer, it would be better to open and read the file in the C program itself using file I/O functions (fopen(), fread(), etc.) instead of constructing a command to execute with system().
*/