// #include<stdio.h>
// #include<stddef.h>

// size_t strlen_new(const char *s)
// {
//     size_t i = 0;
//     while (s[i] !='\0')
//         i++;
//     return i;
// }

// int main(){
//     // size_t length = strlen_new("abc");
//     printf("length of string: %ld\n", sizeof(int));
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int *safe_multiply(int a, int b)
// {
//     // Convert integer a and b to two long long int to perform the multiplication
//     long long int product = (long long int)a * (long long int)b;

//     // Check if the product can fit into an int (not out of bound)
//     if (product > INT_MAX || product < INT_MIN)
//     {
//         return NULL;
//     }

//     // // Dynamically allocate memory for an int
//     // int *result = (int *)malloc(sizeof(int));
//     // if (!result)
//     // {
//     //     // Handle memory allocation failure
//     //     return NULL;
//     // }

//     // // Store the product in the allocated memory
//     // *result = (int)product;

//     // Return the pointer to the allocated memory
//     return (int)product;
// }

// int main()
// {
//     int result = safe_multiply(INT_MAX, 1);
//     if (result != NULL)
//     {
//         printf("Result: %d\n", result);
//         // free(result);
//     }
//     else
//     {
//         printf("Overflow occurred.\n");
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *safe_multiply(int a, int b)
{
    // Convert integer a and b to two long long int to perform the multiplication
    long long int product = (long long int)a * (long long int)b;

    // Check if the product can fit into an int (not out of bound)
    if (product > INT_MAX || product < INT_MIN)
    {
        return NULL;
    }

    // Dynamically allocate memory for an int
    int *result = (int *)malloc(sizeof(int));
    if (!result)
    {
        // Handle memory allocation failure
        return NULL;
    }

    // Store the product in the allocated memory
    *result = (int)product;

    // Return the pointer to the allocated memory
    return result;
}

int main()
{
    int *result = safe_multiply(INT_MAX, 1);
    if (result != NULL)
    {
        printf("Result: %d\n", *result);
        free(result);
    }
    else
    {
        printf("Overflow occurred.\n");
    }

    return 0;
}
