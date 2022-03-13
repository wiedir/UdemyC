#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // calculate_pi
    uint32_t num_iterations = 1000000;
    double pi_calculated = 0.0;
    double pi = 3.14159265358979323846;

    for (uint32_t k = 0; k < num_iterations + 1; k++)
    {
        pi_calculated += (1.0 / (4.0 * k + 1.0)) - (1.0 / (4.0 * k + 3.0));
    }
    pi_calculated *= 4.0;

    printf("pi (calculated): %.16lf\n", pi_calculated);
    printf("pi (correct): %.16lf\n", pi);

    // print_dec_to_bin
    uint32_t number = 0;
    printf("Enter a positive decimal number: ");
    scanf("%u", &number);

    double bin_number = 0;
    double bin_temp = 0;
    int i = 0;
    bool stop = false;

    while (!stop)
    {
        if (pow(2, i) > number)
        {
            stop = true;
            i--;
        }
        else
        {
            i++;
        }
    }

    for (int k = i; k >= 0; k--)
    {
        bin_number *= 10;
        bin_temp = pow(2, k);
        if (bin_temp <= number)
        {
            bin_number += 1;
            number -= bin_temp;
        }
    }

    printf("Binary number: %.f\n", bin_number);

    //uint8_t dec = 142;

    return 0;
}
