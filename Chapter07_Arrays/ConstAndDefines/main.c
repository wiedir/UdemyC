#include <stdio.h>

#define ARRAY_LENGTH 10


int main()
{
    // const int ARRAY_LENGTH = 10;  => nicht zulässig

    int array[ARRAY_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("[%d]: %d\n", i, array[i]);
    }


    return 0;
}
