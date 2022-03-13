#include <stdio.h>

int main()
{
    int a = 22;
    int b = 42;

    _Bool comparison;

    comparison = a > b;
    printf("a > b = %d\n", comparison);

    comparison = a < b;
    printf("a < b = %d\n", comparison);

    comparison = a == b;
    printf("a = b = %d\n", comparison);

    comparison = a != b;
    printf("a != b = %d\n", comparison);

    comparison = a >= b;
    printf("a >= b = %d\n", comparison);

    comparison = a <= b;
    printf("a <= b = %d\n", comparison);

    return 0;
}
