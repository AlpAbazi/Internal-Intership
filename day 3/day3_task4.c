#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA;
    double *pB;

    printf("Shkruani nje vlere per int: ");
    scanf("%d", &a);

    printf("Shkruani nje vlere per double: ");
    scanf("%lf", &b);

    // Lidhja e pointerave me adresat
    pA = &a;
    pB = &b;

    printf("\n--- VLERAT FILLESTARE ---\n");
    printf("a (direkt) = %d\n", a);
    printf("Adresa e a = %p\n", pA);
    printf("a permes pointer = %d\n", *pA);

    printf("\nb (direkt) = %.2lf\n", b);
    printf("Adresa e b = %p\n", pB);
    printf("b permes pointer = %.2lf\n", *pB);

    // Ruaj vleren e vjeter
    int oldA = a;

    // Ndryshimi permes pointer
    *pA = *pA + 10;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a para ndryshimit = %d\n", oldA);
    printf("a pas ndryshimit = %d\n", a);

    // Kontroll me if/else
    if (a > oldA) {
        printf("Vlera eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera eshte zvogeluar.\n");
    } else {
        printf("Vlera ka mbetur e njejte.\n");
    }

    if (a >= 0 && a <= 50) {
        printf("Vlera eshte ne intervalin [0, 50].\n");
    } else {
        printf("Vlera eshte jashte intervalit [0, 50].\n");
    }

    return 0;
}
