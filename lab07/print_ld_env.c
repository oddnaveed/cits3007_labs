#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char **argv)
{
    uid_t real_uid = getuid();

    uid_t effective_uid = geteuid();

    printf("real user id:%d\n", (int) real_uid);
    printf("effective user id:%d\n", (int) effective_uid);


    printf("some environment variables:\n");
    for (char **var = environ; *var != NULL; var++)
    {
        if (strncmp(*var, "LD", 2) == 0)
        {
            printf("var %s\n", *var);
        }
    }
}