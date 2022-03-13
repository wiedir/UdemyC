#include <stdio.h>
#include <stdint.h>

uint64_t factorial(uint8_t n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}



int main()
{
    uint8_t n = 0;

    printf("Calculate faculuty of: ");
    scanf("%hhu", &n);

    uint64_t n_faculuty = factorial(n);

    printf("%u! = %lu\n", n, n_faculuty);

    return 0;
}
