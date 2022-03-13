#include <stdio.h>

int main()
{
    int a;
    unsigned int b;
    float c;
    double d;

    printf("Please enter a value for variable a: ");
    scanf("%d", &a);

    printf("Please enter a value for variable b: ");
    scanf("%u", &b);

    printf("Please enter a value for variable c: ");
    scanf("%f", &c);

    printf("Please enter a value for variable d: ");
    scanf("%lf", &d);

    printf("The value a is: %d\n", a);
    printf("The value b is: %u\n", b);
    printf("The value c is: %f\n", c);
    printf("The value d is: %lf\n", d);

    return 0;
}
