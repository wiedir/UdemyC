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


int main()
{
    unsigned int number_friends = 3;
    char **friends = createFriendsBook(number_friends);

    strcpy(friends[0], "Dirk Wieberneit");
    strcpy(friends[1], "Peter Lustig");
    strcpy(friends[2], "Harry Hirsch");

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    friends = freeFriendsBook(friends, number_friends);

    return 0;
}
