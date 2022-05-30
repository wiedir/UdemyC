#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool string_starts_with(char *string, char *substr);

bool string_ends_with(char *string, char *substr);

char *string_find_first_not_of(char *string, char *substr);

char *string_n_copy(char *dest, char *src, size_t count);

int main()
{
    char text[50] = "jan schaffranek";
    char copy[50] = "Leerer Text";

    printf("string_starts_with 'jan': %d\n", string_starts_with(text, "jan"));
    printf("string_ends_with 'anek': %d\n", string_ends_with(text, "anek"));

    printf("string_starts_with 'an': %d\n", string_starts_with(text, "an"));
    printf("string_ends_with 'ane': %d\n", string_ends_with(text, "ane"));

    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "jan sch"));
    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "an"));

    printf("string_n_copy: %s\n", string_n_copy(copy, text, 8));

    return 0;
}


bool string_starts_with(char *string, char *substr)
{
    if ((string == NULL) || (substr == NULL))
    {
        return false;
    }

    while (*substr != '\0')
    {
        if ((*string != *substr) || (*substr == '\0'))
        {
            return false;
        }

        substr++;
        string++;
    }

    return true;
}

bool string_ends_with(char *string, char *substr)
{
    if ((string == NULL) || (substr == NULL))
    {
        return false;
    }

    int subi = 0;
    int i = 0;

    while (*substr != '\0')
    {
        substr++;
        subi++;
    }

    while (*string != '\0')
    {
        string++;
        i++;
    }

    substr--;
    subi--;
    string--;
    i--;

    while (subi >= 0)
    {
        if ((*string != *substr) || (i < 0))
        {
            return false;
        }

        substr--;
        string--;
        i--;
        subi--;
    }

    return true;
}

char *string_find_first_not_of(char *string, char *substr)
{
    if ((string == NULL) || (substr == NULL))
    {
        return false;
    }

    while (*substr != '\0')
    {
        if ((*string != *substr) || (*string == '\0'))
        {
            return string;
        }

        string++;
        substr++;
    }

    return string;
}

char *string_n_copy(char *dest, char *src, size_t count)
{
    if ((src == NULL) || (dest == NULL) || (count == 0))
    {
        return NULL;
    }

    char *result = dest;

    size_t i = 0;

    while ((*src != '\0') && (i < count))
    {
        *dest = *src;
        dest++;
        src++;
        i++;
    }

    return result;
}
