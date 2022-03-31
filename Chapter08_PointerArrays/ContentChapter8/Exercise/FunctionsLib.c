#include <stdio.h>
#include <stdlib.h>

#include <FunctionsLib.h>

int *createArray(unsigned int length, int value)
{
    int *array = (int *)malloc(length * sizeof(int));

    if (NULL == array)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < length; i++)
    {
        array[i] = value;
    }

    return array;
}


void printArray(int *array, unsigned int length)
{
    if (NULL == array)
    {
        return;
    }

    printf("| ");
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d | ", array[i]);
    }
    printf("\n");
}


int *freeArray(int *array)
{
    if (NULL != array)
    {
        free(array);
    }

    return NULL;
}


int **createMatrix(unsigned int num_rows, unsigned int num_cols, int value)
{
    int **matrix = (int **)malloc(num_rows * sizeof(int *));

    for (unsigned int i = 0; i < num_rows; i++)
    {
        matrix[i] = createArray(num_cols, value);
    }

    return matrix;
}


int **transposeMatrix(int **p_matrix, unsigned int num_rows, unsigned int num_cols)
{
    int **p_matrix_transpose = createMatrix(num_cols, num_rows, 0);

    for (unsigned int i = 0; i < num_cols; i++)
    {
        for (unsigned int j = 0; j < num_rows; j++)
        {
            p_matrix_transpose[i][j] = p_matrix[j][i];
        }
    }

    return p_matrix_transpose;
}


void printMatrix(int **matrix, unsigned int num_rows, unsigned int num_cols)
{
    if (NULL == matrix)
    {
        return;
    }

    for (unsigned int i = 0; i < num_rows; i++)
    {
        printArray(matrix[i], num_cols);
    }
}


int **freeMatrix(int **matrix, unsigned int num_rows)
{
    for (unsigned int i = 0; i < num_rows; i++)
    {
        matrix[i] = freeArray(matrix[i]);
    }

    free(matrix);
    return NULL;
}
