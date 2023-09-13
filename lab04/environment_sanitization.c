#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

extern char **environ;

void print_env()
{
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }

    // printf("size of char* is: %ld", sizeof(char));
}

int main()
{

    print_env();
    return 0;
}