#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    int *data;
    unsigned int length;
};

typedef struct Vector Vector;

int *createArray(unsigned int length, int value)
{
    int *data = (int *)malloc(length * sizeof(int));

    if (NULL == data)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < length; i++)
    {
        data[i] = value;
    }

    return data;
}

int *freeArray(int *array)
{
    if (NULL != array)
    {
        free(array);
    }

    return NULL;
}


float meanVector(Vector *vector)
{
    int sum = 0;

    for (unsigned int i = 0; i < vector->length; i++)
    {
        sum += vector->data[i];
    }

    return (float)(sum) / (float)(vector->length);
}

int minVector(Vector *vector)
{
    if (vector->length == 0)
    {
        return INT32_MIN;
    }

    int current_min = vector->data[0];

    for (unsigned int i = 1; i < vector->length; i++)
    {
        if (vector->data[i] < current_min)
        {
            current_min = vector->data[i];
        }
    }

    return current_min;
}

int maxVector(Vector *vector)
{
    if (vector->length == 0)
    {
        return INT32_MIN;
    }

    int current_max = vector->data[0];

    for (unsigned int i = 1; i < vector->length; i++)
    {
        if (vector->data[i] > current_max)
        {
            current_max = vector->data[i];
        }
    }

    return current_max;
}

void printVector(Vector *vector)
{
    if (NULL == vector->data)
    {
        return;
    }

    for (unsigned int i = 0; i < vector->length; i++)
    {
        printf("%d\n", vector->data[i]);
    }
}

int main()
{
    Vector v1 = {.data = createArray(3, 1), .length = 3};
    v1.data[0] = -10;
    v1.data[1] = 2;
    v1.data[2] = 100;

    printVector(&v1);

    int max_v1 = maxVector(&v1);
    int min_v1 = minVector(&v1);
    float mean_v1 = meanVector(&v1);

    printf("Max: %d\n", max_v1);
    printf("Min: %d\n", min_v1);
    printf("Mean: %f\n", mean_v1);

    return 0;
}
