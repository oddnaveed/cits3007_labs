#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main()
{
    char **old_environ = environ;

    char *OLD_PATH = getenv("PATH");
    if (!OLD_PATH)
    {
        fprintf(stderr, "couldn't get value for PATH!");
        exit(EXIT_FAILURE);
    }

    clearenv();

    printf("current environ: %p\n\n", (void *)environ);
    printf("old environ: %p\n\n", (void *)old_environ);
    printf("old PATH: %s\n", OLD_PATH);
}
