#include <stdio.h>
#include <stdbool.h>

int main()
{
    int pyramide;
    bool valid = false;

    while (!valid)
    {
        printf("Enter number of lines for the pyramide [1 - 50]: ");
        scanf("%d", &pyramide);
        if ((pyramide >= 1) && (pyramide <= 50))
        {
            valid = true;
        }
    }

    for (int z = 0; z < pyramide; z++)
    {
        for (int s = 0; s <= z; s++)
        {
            printf("1");
        }
        printf("\n");
    }

    for (int z = pyramide - 1; z >= 0; z--)
    {
        for (int s = z; s >= 0; s--)
        {
            printf("1");
        }
        printf("\n");
    }


   return 0;
}
