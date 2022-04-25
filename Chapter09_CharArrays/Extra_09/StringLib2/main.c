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
    char copy[50] = {'\0'};

    printf("string_starts_with 'jan': %d\n", string_starts_with(text, "jan"));
    printf("string_ends_with 'anek': %d\n", string_ends_with(text, "anek"));

    printf("string_starts_with 'an': %d\n", string_starts_with(text, "an"));
    printf("string_ends_with 'ane': %d\n", string_ends_with(text, "ane"));

    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "jan "));
    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "an "));

    return 0;
}


bool string_starts_with(char *string, char *substr)
{
    if ((string == NULL) || (substr == NULL))
    {
        return false;
    }

    char *current_subchar = substr;
    char *current_char = string;

    while (*current_subchar != '\0')
    {
        if ((*current_char != *current_subchar) || (*current_char == '\0'))
        {
            return false;
        }

        current_char++;
        current_subchar++;
    }

    return true;
}

bool string_ends_with(char *string, char *substr)
{
    if ((string == NULL) || (substr == NULL))
    {
        return false;
    }

    char *current_subchar = substr;
    int subi = 0;
    char *current_char = string;
    int i = 0;

    while (*current_subchar != '\0')
    {
        current_subchar++;
        subi++;
    }

    while (*current_char != '\0')
    {
        current_char++;
        i++;
    }

    current_subchar--;
    subi--;
    current_char--;
    i--;

    while (subi >= 0)
    {
        if ((*current_char != *current_subchar) || (i < 0))
        {
            return false;
        }

        current_subchar--;
        current_char--;
        i--;
        subi--;
    }

    return true;
}

char *string_find_first_not_of(char *string, char *substr)
{
    bool is_in = string_starts_with(string, substr);

    if (is_in)
    {
        return *string;
    }

    return NULL;
}
