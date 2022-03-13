#include <stdio.h>


int main()
{
    char character_A = 'A';

    printf("Var-Wert lautet: %d\n", character_A);
    printf("Var-Wert als char lautet: %c\n", character_A);

    char character_Z = character_A + 25;
    printf("Var-Wert lautet: %d\n", character_Z);
    printf("Var-Wert als char lautet: %c\n", character_Z);

    return 0;
}
