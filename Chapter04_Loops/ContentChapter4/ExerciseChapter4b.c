#include <stdio.h>

int main()
{
    for (int z = 0; z < 6; z++)
    {
        for (int s = 0; s < 6; s++)
        {
            if (s == 0)
            {
                printf("<   ");
            }
            else if (s == 5)
            {
                printf(">\n");
            }
            else if (z == 0)
            {
                printf("  ^     ");
            }
            else if (z == 5)
            {
                printf("  v     ");
            }
            else
            {
                printf("(%d,%d)   ", z, s);
            }
        }
    }

    return 0;
}
