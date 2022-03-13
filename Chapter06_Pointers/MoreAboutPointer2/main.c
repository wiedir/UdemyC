#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    int *p_d = &a;
    int *p_e = &b;
    int *p_f = &c;

    *p_d = (2 * (*p_e)) + (3 * (*p_f));   // a = 2 * b + 3 * c
    p_d = &b;
    p_f = &a;

    *p_e = *p_d + *p_f;           // b = 2 + a

    printf("%d\n", a);
    printf("%d\n", *p_d);
    printf("%d\n", *p_e);
    printf("%d\n", *p_f);


    return 0;
}
