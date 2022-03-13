#include <stdio.h>


void printEvenOrOdd(int number)
{
    if ((number % 2) == 0)
    {
        printf("Number is even!\n");
    }
    else
    {
        printf("Number is odd!\n");
    }
}

int main()
{
    printEvenOrOdd(1);
    printEvenOrOdd(2);
    printEvenOrOdd(3);


    return 0;
}
