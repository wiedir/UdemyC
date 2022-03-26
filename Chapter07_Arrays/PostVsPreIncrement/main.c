#include <stdio.h>

void my_function(int val)
{
    printf("%d\n", val);
}

int main()
{
    int i = 0;

    // Post-Increment
    printf("%d\n", i++);

    // Pre-Increment
    printf("%d\n", ++i);

    int j = 0;

    // Post-Increment
    my_function(j++);

    // Pre-Increment
    my_function(++j);

    return 0;
}
