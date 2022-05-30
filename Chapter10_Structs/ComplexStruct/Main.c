#include <stdio.h>

typedef enum FriendshipOrigin
{
    FRIENDSHIP_ORIGIN_SCHOOL,
    FRIENDSHIP_ORIGIN_FAMILY,
    FRIENDSHIP_ORIGIN_OTHER,
} FriendshipOrigin_t;

typedef struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Date_t;

typedef struct Friend
{
    char name[50];
    char prename[50];
    Date_t birthday;
    FriendshipOrigin_t origin;
} Friend_t;

void print_date(Date_t *date)
{
    printf("%u.%u.%u\n", date->day, date->month, date->year);
}

void print_friend(Friend_t *friend)
{
    printf("%s %s\n", friend->prename, friend->name);
    print_date(&friend->birthday);

    switch (friend->origin)
    {
    case FRIENDSHIP_ORIGIN_SCHOOL:
    {
        printf("I know him from school.\n\n");
        break;
    }
    case FRIENDSHIP_ORIGIN_FAMILY:
    {
        printf("I know him from my family.\n\n");
        break;
    }
    case FRIENDSHIP_ORIGIN_OTHER:
    {
        printf("I know him from somewhere else.\n\n");
        break;
    }
    }
}


int main()
{
    Friend_t jan = {.name = "Schaffranek",
                    .prename = "Jan",
                    .birthday = {.year = 1994U, .month = 2U, .day = 24U},
                    .origin = FRIENDSHIP_ORIGIN_FAMILY};
    Friend_t peter = {"Lustig", "Peter", {1962U, 2U, 4U}, FRIENDSHIP_ORIGIN_OTHER};
    Friend_t hans = {.name = "Meier",
                     .prename = "Hans",
                     .birthday.year = 1970U,
                     .birthday.month = 6U,
                     .birthday.day = 1U,
                     .origin = FRIENDSHIP_ORIGIN_SCHOOL};

    Friend_t friend_book[] = {jan, peter, hans};

    print_friend(&friend_book[0]);
    print_friend(&friend_book[1]);
    print_friend(&friend_book[2]);


    return 0;
}
