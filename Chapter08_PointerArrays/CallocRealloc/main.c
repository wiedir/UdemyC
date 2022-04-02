#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Malloc
    int length = 6;
    int *arr1 = (int *)malloc(length * sizeof(int));

    printf("\n");
    for (int i = 0; i < length; i++)
    {
        arr1[i] = i;
        printf("%d\n", arr1[i]);
    }


    // Calloc
    length = 6;
    int *arr = (int *)calloc(length, sizeof(int));

    printf("\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", arr[i]);
    }

    // Realloc
    length = 10;
    arr = (int *)realloc(arr, length * sizeof(int));

    printf("\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
