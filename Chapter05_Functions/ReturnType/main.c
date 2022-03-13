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

int getNumberFromUser()
{
    int number_from_user;

    printf("Please enter an integer number: ");
    scanf("%d", &number_from_user);

    return number_from_user;
}

int main()
{
    int user_number = getNumberFromUser();
    printEvenOrOdd(user_number);


    return 0;
}
