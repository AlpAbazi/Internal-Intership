#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA;
    double *pB;

    printf("Shkruani nje numer integer: ");
    scanf("%d", &a);

    printf("Shkruani nje numer double: ");
    scanf("%lf", &b);

    pA = &a;
    pB = &b;

    printf("\n--- VLERAT FILLESTARE ---\n");
    printf("a = %d, adresa e a = %p, vlera permes pointer = %d\n", a, pA, *pA);
    printf("b = %.2lf, adresa e b = %p, vlera permes pointer = %.2lf\n", b, pB, *pB);

    int oldA = a;
    double oldB = b;

    *pA = *pA + 10;
    *pB = *pB * 2;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a = %d, vlera permes pointer = %d\n", a, *pA);
    printf("b = %.2lf, vlera permes pointer = %.2lf\n", b, *pB);

    printf("\n--- ANALIZA PER a ---\n");
    if (a > oldA) {
        printf("Vlera e a eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera e a eshte zvogeluar.\n");
    } else {
        printf("Vlera e a ka mbetur e njejte.\n");
    }

    printf("\n--- ANALIZA PER b ---\n");
    if (b > 0 && b < 100) {
        printf("b ndodhet ne intervalin (0, 100).\n");
    } else if (b <= 0) {
        printf("b eshte zero ose negative.\n");
    } else {
        printf("b eshte me e madhe se 100.\n");
    }

    return 0;
}