#include <stdio.h>

#define PI 3.14159f

int main()
{
    float r;

    printf("Bitte Kreis-Radius eingeben: ");
    scanf("%f", &r);

    if (r < 0.0)
    {
        printf("Falsche Zahleneingabe - bitte Programm wiederholen.");
    }
    else
    {
        float u = 2 * r * PI;
        float a = r * r * PI;

        printf("Kreisumfang beträgt: %f\n", u);
        printf("Kreisfläche beträgt: %f\n", a);
    }


    return 0;
}
