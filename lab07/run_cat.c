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

    system(buf);
    return 0;
}

/*
Note
While this program will work for simple cases, it can be prone to command injection if used with untrusted input, because a user can potentially provide a filename that includes shell special characters or additional commands to execute arbitrary commands.
It's recommended to validate and sanitize inputs to avoid security vulnerabilities.
To make the program safer, it would be better to open and read the file in the C program itself using file I/O functions (fopen(), fread(), etc.) instead of constructing a command to execute with system().
*/