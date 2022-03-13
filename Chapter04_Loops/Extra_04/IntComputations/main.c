#include <stdint.h>
#include <stdio.h>

int main()
{
    uint32_t number = 0;
    unsigned int num_digits = 0;
    unsigned int cross_sum = 0;
    unsigned int rest = 0;

    printf("Please enter a unsigned integer: ");
    scanf("%u", &number);

    // sum_of_digits
    for (unsigned int i = 1; i <= number; i *= 10)
    {
        num_digits++;
    }

    printf("sum_of_digits: %u\n", num_digits);

    // cross_sum
    for (unsigned int i = 1; i < num_digits; i++)
    {
        rest = number % 10;
        cross_sum += rest;
        number -= rest;
        number /= 10;
    }
    cross_sum += number;

    printf("cross_sum: %d\n", cross_sum);
}
