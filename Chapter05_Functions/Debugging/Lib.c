#include <stdio.h>

#include "Lib.h"

int getNumberFromUser()
{
    int number_from_user; //0x00: 12

    printf("Pls enter a interger number!\n");
    scanf("%d", &number_from_user);

    return number_from_user; // return 12;
}


int max(int number_a, int number_b)
{
    if (number_a > number_b)
    {
        return number_a;
    }
    else if (number_b > number_a)
    {
        return number_b;
    }
    else
    {
        return 0;
    }
}


int min(int number_a, int number_b)
{
    if (number_a < number_b)
    {
        return number_a;
    }
    else if (number_b < number_a)
    {
        return number_b;
    }
    else
    {
        return 0;
    }
}


float mean(int number_a, int number_b)
{
    return (number_a + number_b) / 2.0f;
}
