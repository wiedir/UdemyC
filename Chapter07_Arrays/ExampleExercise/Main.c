#include <stdbool.h>
#include <stdio.h>

#include "Lib.h"

#define LENGTH 1000

void exercise(int *array, unsigned int *length)
{
    int user_in = 0;

    for (unsigned int i = 0; i < *length; i++)
    {
        printf("Please enter integer number > 0 (<= 0 stops input process): ");
        scanf("%d", &user_in);

        if (user_in > 0)
        {
            array[i] = user_in;
        }
        else
        {
            *length = i;
            return;
        }
    }

    return;
}

int main()
{
    int user_array[LENGTH] = {0};
    unsigned int end_length = LENGTH;

    exercise(user_array, &end_length);

    printf("User-Array:\n");
    for (unsigned int i = 0; i < end_length; i++)
    {
        printf("%d ", user_array[i]);
    }
    printf("\n");

    int min_user_array = minArray(user_array, end_length);
    int max_user_array = maxArray(user_array, end_length);

    printf("Min: %d\n", min_user_array);
    printf("Max: %d\n", max_user_array);

    return 0;
}
