#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = (int *)malloc(sizeof(int));
    *a = 10;
    printf("%d\n", *a);
    free(a);
    a = NULL;

    if (a != NULL)
    {
        printf("%d\n", *a);
    }

    return 0;
}
