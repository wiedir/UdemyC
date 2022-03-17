#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

void unique_elements(int32_t *array, size_t length);

void remove_duplicates(int32_t *array, size_t *length);

void rotate_left(int32_t *array, size_t length);

void rotate_right(int32_t *array, size_t length);

int main()
{
    int32_t array[] = {1, 1, 2, 3, 4, 3, 3, 4, 4, 4, 5};
    size_t length = 11;

    printf("unique_elements: \n");
    unique_elements(array, length);

    remove_duplicates(array, &length);
    print_int32_array(array, length);

    rotate_left(array, length);
    print_int32_array(array, length);

    rotate_right(array, length);
    print_int32_array(array, length);

    return 0;
}


void unique_elements(int32_t *array, size_t length)
{
     if (array == NULL)
    {
        printf("Array is empty.");
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        bool unique = true;

        for (size_t j = 0; j < length; j++)
        {
            if ((array[i] == array[j]) && (i != j))
            {
                unique = false;
            }
        }
        if (unique)
        {
            printf("%d, ", array[i]);
        }
    }
    printf("\n");
    return;
}


void remove_duplicates(int32_t *array, size_t *length)
{
     if (array == NULL)
    {
        printf("Array is empty.");
        return;
    }

    size_t act_length = *length;

    for (size_t i = 0; i < act_length - 1; i++)
    {
        for (size_t j = i + 1; j < act_length; j++)
        {
            if (array[i] == array[j])
            {
                while (array[i] == array[j])
                {
                    for (size_t t = j; t < act_length -1; t++)
                    {
                        array[t] = array[t + 1];
                    }
                    act_length -= 1;
                }
            }
        }
    }

    *length = act_length;
    return;
}


void rotate_left(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        printf("Array is empty.");
        return;
    }

    int32_t buffer = array[0];

    for (size_t i = 0; i < length - 1; i++)
    {
       array[i] = array[i + 1];
    }
    array[length - 1] = buffer;

    return;
}


void rotate_right(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        printf("Array is empty.");
        return;
    }

    int32_t buffer = array[length - 1];

    for (size_t i = length - 1; i > 0; i--)
    {
       array[i] = array[i - 1];
    }
    array[0] = buffer;

    return;
}
