#include <stdio.h>

typedef struct Friend
{
    char name[50];
    char prename[50];
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Friend_t;

// typedef struct Friend Friend_t;


void print_friend(Friend_t *friend)
{
    printf("%s %s\n", friend->prename, friend->name);
    printf("%u.%u.%u\n\n", friend->day, friend->month, friend->year);
}


int main()
{
    Friend_t jan = {.name = "Schaffranek", .prename = "Jan", .year = 1994U, .month = 2U, .day = 24U};
    Friend_t peter = {"Lustig", "Peter", 1962U, 2U, 4U};
    Friend_t hans = {.name = "Meier", .prename = "Hans", .year = 1970U, .month = 6U, .day = 1U};

    Friend_t friend_book[] = {jan, peter, hans};

    print_friend(&friend_book[0]);
    print_friend(&friend_book[1]);
    print_friend(&friend_book[2]);


    return 0;
}
