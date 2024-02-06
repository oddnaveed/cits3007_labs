#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

// int main()
// {
//     char **old_environ = environ;

//     char *OLD_PATH = getenv("PATH");
//     if (!OLD_PATH)
//     {
//         fprintf(stderr, "couldn't get value for PATH!");
//         exit(EXIT_FAILURE);
//     }

//     clearenv();

//     printf("current environ: %p\n\n", (void *)environ);
//     printf("old environ: %p\n\n", (void *)old_environ);
//     printf("old PATH: %s\n", OLD_PATH);
// }

void sanitize_env()
{
    char **old_environ = environ;

    // get old PATH & PWD
    char *PATH = getenv("PATH");
    if (!PATH)
    {
        fprintf(stderr, "couldn't get value for PATH!");
        exit(EXIT_FAILURE);
    }
    char *PWD = getenv("PWD");
    if (!PWD)
    {
        fprintf(stderr, "couldn't get value for PATH!");
        exit(EXIT_FAILURE);
    }

    // get old COLORTERM if exists
    char *COLORTERM = getenv("COLORTERM");

    // get old COLUMNS: if COLUMNS exists, set it to 40; else, set COLUMNS to 60
    char *COLUMNS = getenv("COLUMNS");
    // if(COLUMNS!=NULL) COLUMNS = "40";
    // else COLUMNS = "60";
    COLUMNS = (COLUMNS!=NULL) ? "40" : "60";

    if(clearenv()!=0){
        fprintf(stderr, "failed to clear the environment variables");
        exit(EXIT_FAILURE);
    }

    // retain PATH & PWD
    if (setenv("PATH", PATH, 1) != 0 || setenv("PWD", PWD, 1) != 0 || setenv("COLUMNS", COLUMNS, 1) != 0)
    {
        fprintf(stderr, "failed to set the environment value!");
        exit(EXIT_FAILURE);
    }

    // retain COLORTERM if exists
    if (COLORTERM)
    {
        if (setenv("COLORTERM", COLORTERM, 1) != 0)
        {
            fprintf(stderr, "failed to set the environment value!");
            exit(EXIT_FAILURE);
        }
    }

    // printf("current environ: %p\n", (void *)environ);
    // printf("old environ: %p\n", (void *)old_environ);
    // printf("old PATH: %s\n", PATH);
    // printf("old PWD: %s\n", PWD);
    // printf("old COLORTERM: %s\n", COLORTERM);
    // printf("old COLUMNS: %s\n", COLUMNS);
}

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
    sanitize_env();
    print_env();

    return 0;
}