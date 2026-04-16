#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA = &a;
    double *pB = &b;

    printf("Shkruaj nje numer int: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer double: ");
    scanf("%lf", &b);

    printf("\n--- Vlerat fillestare ---\n");
    printf("a = %d\n", a);
    printf("b = %.2lf\n", b);

    printf("\n--- Adresat ---\n");
    printf("Adresa e a: %p\n", pA);
    printf("Adresa e b: %p\n", pB);

    printf("\n--- Vlerat permes pointerave ---\n");
    printf("*pA = %d\n", *pA);
    printf("*pB = %.2lf\n", *pB);

    int oldA = a;

    // ndryshim permes pointer-it
    *pA = *pA + 10;

    printf("\n--- Pas ndryshimit ---\n");
    printf("a para: %d\n", oldA);
    printf("a pas: %d\n", a);

    // kontrolli me if/else
    if (a > oldA) {
        printf("Vlera eshte rritur\n");
    } else if (a < oldA) {
        printf("Vlera eshte zvogeluar\n");
    } else {
        printf("Vlera eshte e njejte\n");
    }

    if (a >= 0 && a <= 100) {
        printf("Vlera eshte ne intervalin 0-100\n");
    }

    return 0;
}