// #include <stdio.h>
// #include <stdlib.h>

// // enum weekday
// // {
// //     MON,
// //     TUE,
// //     WED,
// //     THU,
// //     FRI
// // };

// // void display_inspirational_message(enum weekday d)
// // {
// //     switch (d)
// //     {
// //     case MON:
// //         printf("Too much Monday, not enough coffee :(\n");
// //         break;
// //     case TUE:
// //         printf("Mmm, taco Tuesday\n");
// //         break;
// //     case WED:
// //         printf("Whoa-oh, we're halfway there...\n");
// //         break;
// //     case THU:
// //         printf("Almost the weekend\n");
// //         break;
// //     case FRI:
// //         printf("TGIF\n");
// //         break;
// //     default:
// //         fprintf(stderr, "AWOOOGAH! ABORT! ABORT!\n");
// //         abort();
// //     }
// // }

// // #define W 10
// // #define W 21
// // #define H 5

// int main()
// {
//     // for (enum weekday d = MON; d <= FRI; d++)
//     // {
//     //     printf("%d: ", d);
//     // display_inspirational_message(99);
//     // }
//     // char a_string[] = "dog rat cat";
//     // int length = sizeof(a_string);
//     // printf("size of char is %d\n", sizeof(char));
//     // printf("size of short is %ld\n", sizeof(short));
//     printf("size of long is %ld\n", sizeof(long));
//     // printf("w is %d", W);
//     // printf("length of string is %d\n", length);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int return_num()
// {
//     static int n = 1;
//     n += 1;
//     return n;
// }

// int main()
// {
//     auto int o;
//     for (auto size_t i = 0; i < 5; i++)
//     {
//         o = return_num();
//     }
//     printf("%d\n", o);
//     return 0;
// }

// Is the following a valid C11 program ?

#include <stdlib.h>
#include <stdio.h>

int buf[1024];

int main()
{
    buf[1024];
    printf("%s\n", "hello");
    return 0;
}