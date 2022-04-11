#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **createFriendsBook(unsigned int number_friends)
{
    char **friends = (char **)malloc(number_friends * sizeof(char *));

    if (friends == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < number_friends; i++)
    {
        friends[i] = (char *)malloc(20 * sizeof(char));
    }

    return friends;
}


char **freeFriendsBook(char **friends, unsigned int num_friends)
{
    for (unsigned int i = 0; i < num_friends; i++)
    {
        free(friends[i]);
    }

    free(friends);
    return NULL;
}


void own_strcat(char *string1, char *string2)
{
    if ((string1 == NULL) || (string2 == NULL))
    {
        return;
    }

    while (*string1 != '\0')
    {
        string1++;
    }

    while (*string2 != '\0')
    {
        *string1 = *string2;
        string1++;
        string2++;
    }

    *string1 = '\0';

    return;
}


int main()
{
    unsigned int number_friends = 4;
    char **friends = createFriendsBook(number_friends);

    strncpy(friends[0], "Dirk Wieberneit", 20);
    strncpy(friends[1], "Peter Lustig Senior", 20);
    strncpy(friends[2], "Harry Hirsch", 20);
    strncpy(friends[3], "Peter Lustig Senior", 21);

    strncat(friends[0], " Dr.", 5);

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    printf("\nOwn Concatenate Function: \n");

    own_strcat(friends[2], " Junior");

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    friends = freeFriendsBook(friends, number_friends);

    return 0;
}
