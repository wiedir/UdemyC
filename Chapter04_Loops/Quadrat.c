#include <stdio.h>
#include <stdbool.h>


int main()
{
    // Declaration of variables
    float a;
    float peri, area;
    bool valid = false;

    // User Input
    do
    {
        printf("Input of quadrat side a: ");
        scanf("%f", &a);
        if (a <= 0)
        {
            printf("Invalid number for a!\n");
        }
        else
        {
            valid = true;
        }
    } while(!valid);

    // Calculation & Output
    peri = 4 * a;
    area = a * a;

    printf("The perimeter value is: %f and the area is: %f\n", peri, area);

  return 0;
}
