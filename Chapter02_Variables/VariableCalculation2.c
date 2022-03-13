#include <stdio.h>

int main()
{
    float a = 5.0f;
    float b = 2.0f;
    float c = 1.0f;

    // Addition
    c += b;
    printf("%f\n", c);

    // Subtraction
    c -= b;
    printf("%f\n", c);

    // Multiplication
    c *= b;
    printf("%f\n", c);

    // Division
    c /= b;
    printf("%f\n", c);

    // Inkrementieren
    b = b + 1;
    printf("%f\n", b);

    b--;
    printf("%f\n", b);

    return 0;
}
