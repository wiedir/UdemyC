#include <stdio.h>

int main()
{
    int M[2][3] = { {1, 0, 1}, {0, 1, 2} };

    int matrix_size = sizeof(M);
    printf("%u\n", matrix_size);

    int num_cols = sizeof(M[0]) / sizeof(int);
    printf("%u\n", num_cols);

    int num_rows = matrix_size / (num_cols * sizeof(int));
    printf("%u\n", num_rows);


    return 0;
}
