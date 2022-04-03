#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name1[] = {'D', 'i', 'r', 'k', '\0'};
    char name2[5] = {'D', 'i', 'r', 'k', '\0'};
    char name3[] = "Dirk";
    char name4[32] = {'\0'};

    char *name5 = (char *)malloc(32 * sizeof(char));
    name5[0] = 'D';
    name5[1] = 'i';
    name5[2] = 'r';
    name5[3] = 'k';
    name5[4] = '\0';

    for (unsigned int i = 0; i < 5; i++)
    {
        printf("%c", name5[i]);
    }
    printf("\n");

    printf("%s\n", name1);
    printf("%s\n", name2);
    printf("%s\n", name3);
    printf("%s\n", name4);
    printf("%s\n", name5);

    free(name5);
    name5 = NULL;

    return 0;
}
