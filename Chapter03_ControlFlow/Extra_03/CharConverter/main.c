#include <stdbool.h>
#include <stdio.h>

int main()
{
    char character;
    char convert;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    // is numeric
    bool is_numeric = false;
    if ((character >='0') && (character <= '9'))
    {
        is_numeric = true;
        printf("Value is numeric character!\n");
    }

    // is upper case
    bool is_upper = false;
    if ((character >= 'A') && (character <= 'Z'))
    {
        is_upper = true;
        printf("Value is upper case character!\n");
    }

    // is lower case
    bool is_lower = false;
    if ((character >= 'a') && (character <= 'z'))
    {
        is_lower = true;
        printf("Value is lower case character!\n");
    }

    // is alpha
    if (is_upper || is_lower)
    {
        printf("Value is alpha character!\n");
    }

    // is alpha numeric
    if (is_upper || is_lower || is_numeric)
    {
        printf("Value is alpha numeric character!\n");
    }
    else
    {
        printf("Value is special character!\n");
    }

    // to upper case
    if (is_upper)
    {
        printf("Upper case value is: %c\n", character);
    }
    else if (is_lower)
    {
        convert = character - 32;
        printf("Upper case value is: %c\n", convert);
    }

    // to lower case
    if (is_lower)
    {
        printf("Lower case value is: %c\n", character);
    }
    else if (is_upper)
    {
        convert = character + 32;
        printf("Lower case value is: %c\n", convert);
    }

    return 0;
}
