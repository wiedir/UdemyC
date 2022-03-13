#include <limits.h>
#include <stdint.h>
#include <stdio.h>


int main()
{
    u_int64_t a1 = 0;
    u_int32_t b1 = 0;
    u_int16_t c1 = 0;
    u_int8_t d1 = 0;

    int64_t a2 = 0;
    int32_t b2 = 0;
    int16_t c2 = 0;
    int8_t d2 = 0;

    printf("%lu\n", a1);
    printf("%ld\n", a2);

    printf("%u\n", b1);
    printf("%d\n", b2);

    printf("%hu\n", c1);
    printf("%hd\n", c2);

    printf("%hhu\n", d1);
    printf("%hhd\n", d2);

    return 0;
}
