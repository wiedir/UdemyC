#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void iota(int32_t *array, size_t length, int32_t start_value);

int32_t *inclusive_scan(int32_t *array, size_t length);

int main()
{
    int32_t array[8] = {0};
    size_t length = 8;

    iota(array, length, 0);
    print_int32_array(array, length);

    int32_t *inc_scan_values = inclusive_scan(array, length);
    printf("inclusive_scan: \n");
    print_int32_array(inc_scan_values, length);

    free(inc_scan_values);
    inc_scan_values = NULL;

    return 0;
}


void iota(int32_t *array, size_t length, int32_t start_value)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = start_value + i;
    }

    return;
}


int32_t *inclusive_scan(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        printf("Empty Array entered!");
        return 0;
    }

    int32_t *result = (int32_t *)malloc(length * sizeof(int32_t));

    result[0] = array[0];

    for (size_t i = 1; i < length; i++)
    {
        result[i] = array[i] + result[i - 1];
    }

    return result;
}
