#include <stdio.h>

int main()
{
    float x = -2.0F;
    float y = -3.0F;

    float z1 = (x * x) + (y * y) - (x * y) + 2.0f;
    float z2 = (x - y) * (x - y) * (x - y) - 3.0f;
    float z3 = ((2.0f * x * x * x) - (1.0f / 2.0f * x * x) - x + 4.0f) / y;

    printf("z1 = %f\n", z1);
    printf("z2 = %f\n", z2);
    printf("z3 = %f\n", z3);

    return 0;
}
