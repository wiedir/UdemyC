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

unsigned int own_strncmp(char *string1, char *string2)
{
    if ((string1 == NULL) || (string2 == NULL))
    {
        return 0;
    }

    while ((*string1 != '\0') && (*string2 != '\0'))
    {
        if (*string1 != *string2)
        {
            return 0;
        }

        string1++;
        string2++;
    }

    if ((*string1 == '\0') && (*string2 == '\0'))
    {
        return 1;
    }

    return 0;
}


int main()
{
    unsigned int number_friends = 4;
    char **friends = createFriendsBook(number_friends);

    strncpy(friends[0], "Dirk Wieberneit", 20);
    strncpy(friends[1], "Peter Lustig Senior", 20);
    strncpy(friends[2], "Harry Hirsch", 20);
    strncpy(friends[3], "Peter Lustig Senior", 21);

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    unsigned int compare0 = strncmp(friends[0], friends[1], 20);
    unsigned int compare1 = strncmp(friends[0], friends[2], 20);
    unsigned int compare2 = strncmp(friends[1], friends[2], 20);
    unsigned int compare3 = strncmp(friends[1], friends[3], 12);

    printf("%d\n", compare0);
    printf("%d\n", compare1);
    printf("%d\n", compare2);
    printf("%d\n", compare3);

    printf("Own function compare:\n");

    unsigned int own_comp0 = own_strncmp(friends[0], friends[1]);
    unsigned int own_comp1 = own_strncmp(friends[0], friends[2]);
    unsigned int own_comp2 = own_strncmp(friends[1], friends[2]);
    unsigned int own_comp3 = own_strncmp(friends[1], friends[3]);

    printf("%d\n", own_comp0);
    printf("%d\n", own_comp1);
    printf("%d\n", own_comp2);
    printf("%d\n", own_comp3);

    friends = freeFriendsBook(friends, number_friends);

    return 0;
}
