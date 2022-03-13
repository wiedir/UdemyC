#include <stdio.h>

int main()
{
    // Rectangle Example
    // 1.) Read the values for a, b from the user
    // 2.) Compute the perimeter and area of the rectangle
    // 3.) Print the computed values to the console

    // Declaration of variables
    float a, b;
    float peri, area;

    // step 1.)
    printf("Input of rectangle side a: ");
    scanf("%f", &a);
    printf("\nInput of rectangle side b: ");
    scanf("%f", &b);

    // step 2.)
    peri = 2 * (a + b);
    area = a * b;

    // step 3.)
    printf("The perimeter value is: %f and the area is: %f\n", peri, area);


    return 0;
}
