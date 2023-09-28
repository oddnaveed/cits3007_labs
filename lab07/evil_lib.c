#include <stdio.h>

void useful_func(int s)
{
    // we could now run arbitrary code and cause damage.
    printf("Malicious things -- bwahaha!\n");
}