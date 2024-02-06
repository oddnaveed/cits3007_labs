#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    uid_t euid = geteuid();
    

    printf("FIXING, currrent effective user ID is %d\n", euid);
    // printf("DOING SOMETHING MALICIOUS, with effective user ID %d\n", euid);
}