#include <float.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    // declaration of variables
    unsigned int age_years, age_days, age_hours;
    unsigned int age_minutes, age_seconds;

    // user input of age in years
    printf("Please enter your age in years: ");
    scanf("%u", &age_years);

    // calculation of age units
    age_days = age_years * 365u;
    age_hours = age_days * 24u;
    age_minutes = age_hours * 60u;
    age_seconds = age_minutes * 60u;

    // print out results
    printf("You are living since %u days\n", age_days);
    printf("You are living since %u hours\n", age_hours);
    printf("You are living since %u minutes\n", age_minutes);
    printf("You are living since %u seconds\n", age_seconds);

    return 0;
}
