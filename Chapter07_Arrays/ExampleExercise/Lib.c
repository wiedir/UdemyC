#include <stdio.h>

#include "Lib.h"

float meanArray(int *array, unsigned int length)
{
    int sum = 0;

    for (unsigned int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return (float)(sum) / (float)(length);
}


int minArray(int *array, unsigned int length)
{
    int min = array[0];

    for (unsigned int i = 1; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}


int maxArray(int *array, unsigned int length)
{
    int max = array[0];

    for (unsigned int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}
