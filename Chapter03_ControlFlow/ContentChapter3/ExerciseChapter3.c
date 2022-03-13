#include <stdio.h>

int main()
{
    unsigned int input;
    unsigned int result;

    printf("Please enter a valid unsigned integer!\n");
    scanf("%u", &input);

    result = input % 3;

    if (result == 0)
    {
        printf("The number you entered is div. by 3!\n");
    }
    else
    {
        printf("The number you entered is not div. by 3!\n");
        printf("The remainder of the operation is: %u", result);
    }


    return 0;
}
