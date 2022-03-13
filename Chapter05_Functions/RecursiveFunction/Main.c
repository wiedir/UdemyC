#include <stdio.h>

// Globale Variablen Deklaration
int a = 1;

void func()
{
    // lokale Funktions-Variablen Deklaration
    int b = 2;

    printf("(FUNC) a = %d\n", a);
    printf("(FUNC) b = %d\n", b);
}


int main()
{
    // lokale Hauptprog-Variablen Deklaration
    int c = 3;

    func();

    printf("(MAIN) a = %d\n", a);
    printf("(MAIN) c = %d\n", c);

    return 0;
}
