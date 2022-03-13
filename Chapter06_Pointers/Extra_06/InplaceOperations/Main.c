#include <stdint.h>
#include <stdio.h>

void clamp_value(float *input, float min_value, float max_value)
{
    if (*input < min_value)
    {
        *input = min_value;
    }
    else if (*input > max_value)
    {
        *input = max_value;
    }
}

void round_value(float *input, int num_digits)
{
    int round = 0;

    for (int i = 1; i <= num_digits; i++)
    {
        *input = *input * 10;
    }
    round = *input;
    *input = round;

    for (int i = 1; i <= num_digits; i++)
    {
        *input = *input / 10;
    }
}

int main()
{
    float value = 1.123456f;

    clamp_value(&value, -2.0f, 2.0f);
    printf("%f\n", value);

    round_value(&value, 1);
    printf("%f\n", value);

    return 0;
}
