#ifndef FUNCTIONSLIB_H
#define FUNCTIONSLIB_H

int *createArray(unsigned int length, int value);
void printArray(int *array, unsigned int length);
int *freeArray(int *array);
int **createMatrix(unsigned int num_rows, unsigned int num_cols, int value);
int **transposeMatrix(int **p_matrix, unsigned int num_rows, unsigned int num_cols);
void printMatrix(int **matrix, unsigned int num_rows, unsigned int num_cols);
int **freeMatrix(int **matrix, unsigned int num_rows);

#endif
