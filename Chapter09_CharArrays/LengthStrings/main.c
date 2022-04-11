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

size_t own_strlen(char *string)
{
    if (string == NULL)
    {
        return 0;
    }

    size_t i = 0;

    while (*string != '\0')
    {
        string++;
        i++;
    }

    return i;
}


int main()
{
    unsigned int number_friends = 3;
    char **friends = createFriendsBook(number_friends);

    strncpy(friends[0], "Dirk Wieberneit", 20);
    strncpy(friends[1], "Peter Lustig Senior", 20);
    strncpy(friends[2], "Harry Hirsch", 20);

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    long unsigned int length0 = strlen(friends[0]);
    long unsigned int length1 = strlen(friends[1]);
    long unsigned int length2 = strlen(friends[2]);

    printf("%lu\n", length0);
    printf("%lu\n", length1);
    printf("%lu\n", length2);

    size_t B_length0 = own_strlen(friends[0]);
    size_t B_length1 = own_strlen(friends[1]);
    size_t B_length2 = own_strlen(friends[2]);

    printf("Own function:\n");

    printf("%lu\n", B_length0);
    printf("%lu\n", B_length1);
    printf("%lu\n", B_length2);


    friends = freeFriendsBook(friends, number_friends);

    return 0;
}
