#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

bool array_equal(int32_t *array1, size_t length1, int32_t *array2, size_t length2);

void array_clamp(int32_t *array, size_t length, int32_t min_value, int32_t max_value);

void array_reverse(int32_t *array, size_t length);

void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value);

int main()
{
    int32_t array1[] = {-3, -2, -1, 0, 1, 2, 3};
    int32_t array2[] = {-3, -2, -1, 0, 1, 2, 3};
    size_t length = 7;

    printf("array_equal: %d\n", array_equal(array1, length, array2, length));

    array_clamp(array1, length, -1, 1);
    print_int32_array(array1, length);

    array_fill_n(array1, length, 5, -1337);
    print_int32_array(array1, length);

    array_reverse(array2, length);
    print_int32_array(array2, length);

    return 0;
}


bool array_equal(int32_t *array1, size_t length1, int32_t *array2, size_t length2)
{
    if ((array1 == NULL) || (array2 == NULL))
    {
        printf("Empty Array entered!");
        return false;
    }

    if (length1 != length2)
    {
        return false;
    }

    for (size_t i = 0; i < length1; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }

    return true;
}


void array_clamp(int32_t *array, size_t length, int32_t min_value, int32_t max_value)
{
    if (array == NULL)
    {
        printf("Empty Array entered!");
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < min_value)
        {
            array[i] = min_value;
        }
        else if (array[i] > max_value)
        {
            array[i] = max_value;
        }
    }

    return;
}


void array_reverse(int32_t *array, size_t length)
{
    int32_t buffer = 0;
    size_t j = 0;
    size_t half_length = length / 2;

    if (array == NULL)
    {
        printf("Empty Array entered!");
        return;
    }

    for (size_t i = 0; i < half_length; i++)
    {
        j = length - i - 1;
        buffer = array[i];
        array[i] = array[j];
        array[j] = buffer;
    }

    return;
}


void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value)
{
    if (array == NULL)
    {
        printf("Empty Array entered!");
        return;
    }

    if (n > length)
    {
        n = length;
    }

    for (size_t i = 0; i < n; i++)
    {
        array[i] = value;
    }

    return;
}
