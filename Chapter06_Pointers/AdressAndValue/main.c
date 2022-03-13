#include <stdio.h>

int main()
{
    int my_value = 1337;

    // &: liefert Memory Adresse

    printf("Value of my_value: %d\n", my_value);
    printf("Memory address of my_value: %p\n", &my_value);


    return 0;
}
