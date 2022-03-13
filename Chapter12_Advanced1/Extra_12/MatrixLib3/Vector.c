#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Vector *createVector(const size_t length, const float value)
{
    Vector *result = (Vector *)malloc(sizeof(Vector));

    if (result == NULL)
    {
        return NULL;
    }

    float *data = (float *)malloc(length * sizeof(float));

    if (data == NULL)
    {
        free(result);
        return NULL;
    }

    for (size_t i = 0; i < length; i++)
    {
        data[i] = value;
    }


    result->data = data;
    result->length = length;

    return result;
}

Vector *freeVector(Vector *vector)
{
    if (vector == NULL)
    {
        return NULL;
    }

    if (vector->data != NULL)
    {
        free(vector->data);
        vector->data = NULL;
    }

    free(vector);

    return NULL;
}

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printVector(const Vector *vector)
{
    if (vector->data == NULL)
    {
        return;
    }

    printf("[");

    for (size_t i = 0; i < vector->length - 1; i++)
    {
        printf("%f, ", vector->data[i]);
    }

    printf("%f]\n\n", vector->data[vector->length - 1]);
}

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Vector *addVector(const Vector *vec1, const Vector *vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return NULL;
    }

    Vector *result = createVector(vec1->length, 0.0);

    for (size_t i = 0; i < vec1->length; i++)
    {
        result->data[i] = vec1->data[i] + vec2->data[i];
    }

    return result;
}

Vector *subVector(const Vector *vec1, const Vector *vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return NULL;
    }


    Vector *result = createVector(vec1->length, 0.0);

    for (size_t i = 0; i < vec1->length; i++)
    {
        result->data[i] = vec1->data[i] - vec2->data[i];
    }

    return result;
}

float multiplyVector(const Vector *vec1, const Vector *vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return 0.0f;
    }

    float result = 0.0f;

    for (size_t i = 0; i < vec1->length; i++)
    {
        result += vec1->data[i] * vec2->data[i];
    }

    return result;
}

Vector *multiplyVectorByScalar(const Vector *vec, const float scalar)
{
    if (vec == NULL)
    {
        return NULL;
    }

    Vector *result = createVector(vec->length, 0.0);

    for (size_t i = 0; i < vec->length; i++)
    {
        result->data[i] = vec->data[i] * scalar;
    }

    return result;
}

Vector *divideVectorByScalar(const Vector *vec, const float scalar)
{
    if ((vec == NULL) || (scalar == 0.0f))
    {
        return NULL;
    }

    Vector *result = createVector(vec->length, 0.0);

    for (size_t i = 0; i < vec->length; i++)
    {
        result->data[i] = vec->data[i] / scalar;
    }

    return result;
}

float meanVector(const Vector *vector)
{
    float sum = 0.0f;

    for (size_t i = 0; i < vector->length; i++)
    {
        sum += vector->data[i];
    }

    return (float)(sum) / (float)(vector->length);
}

float minVector(const Vector *vector)
{
    if (vector->length == 0)
    {
        return FLT_MAX;
    }

    float current_min = vector->data[0];

    for (size_t i = 1; i < vector->length; i++)
    {
        if (vector->data[i] < current_min)
        {
            current_min = vector->data[i];
        }
    }

    return current_min;
}

float maxVector(const Vector *vector)
{
    if (vector->length == 0)
    {
        return FLT_MIN;
    }

    float current_max = vector->data[0];

    for (size_t i = 1; i < vector->length; i++)
    {
        if (vector->data[i] > current_max)
        {
            current_max = vector->data[i];
        }
    }

    return current_max;
}
