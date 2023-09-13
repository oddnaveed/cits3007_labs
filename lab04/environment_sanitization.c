#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

// extern char **environ;

void print_env(int argc, char *argv[], char *envp[])
{
    for (int i=0; envp[i]!=NULL; i++)
    {
        printf("%s\n", envp[i]);
    }
}

int main(int argc, char *argv[], char *envp[])
{
    print_env(argc, argv, envp);
    return 0;
}