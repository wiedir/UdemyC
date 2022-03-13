#include <stdio.h>

int main()
{

    printf("<       ^       ^       ^       ^       >\n");

    for (int z = 1; z < 5; z++)
    {
        printf("<     ");
        for (int s = 1; s < 5; s++)
        {
            printf("(%d,%d)   ", z, s);
        }
        printf("  >\n");
    }

    printf("<       v       v       v       v       >\n");

    return 0;
}
