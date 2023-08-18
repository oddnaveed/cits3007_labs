#include <stdio.h>
#include <stdlib.h>

enum day
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

int main()
{
    enum day myday = MON;
    myday = 294967287;
    printf("%d\n", myday);
}
