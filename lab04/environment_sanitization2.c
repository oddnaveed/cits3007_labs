#define _DEFAULT_SOURCE
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
}

int main()
{

    print_env();
    return 0;
}