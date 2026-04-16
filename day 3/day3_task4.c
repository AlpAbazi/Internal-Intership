#include <stdio.h>

int main() {
    int a;
    float b;

    // Input
    printf("Shkruani nje numer integer: ");
    scanf("%d", &a);

    printf("Shkruani nje numer float: ");
    scanf("%f", &b);

    // Pointer-at
    int *pA = &a;
    float *pB = &b;

    // Ruajmë vlerat fillestare për krahasim
    int oldA = a;

    printf("\n--- VLERAT FILLESTARE ---\n");
    printf("a = %d\n", a);
    printf("Adresa e a = %p\n", &a);
    printf("Vlera e a permes pointer = %d\n", *pA);

    printf("\nb = %.2f\n", b);
    printf("Adresa e b = %p\n", &b);
    printf("Vlera e b permes pointer = %.2f\n", *pB);

    // Ndryshimi përmes pointer-it
    printf("\n--- NDRYSHIMI PERMES POINTER ---\n");
    *pA = *pA + 10;  // rrit vlerën e a me 10

    printf("Vlera e a para ndryshimit: %d\n", oldA);
    printf("Vlera e a pas ndryshimit: %d\n", a);

    // Kontrolli me if/else
    printf("\n--- ANALIZA ---\n");

    if (a > oldA) {
        printf("Vlera eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera eshte zvogeluar.\n");
    } else {
        printf("Vlera ka mbetur e njejte.\n");
    }

    // Kontroll intervali
    if (a >= 0 && a <= 100) {
        printf("Vlera eshte brenda intervalit [0, 100].\n");
    } else {
        printf("Vlera eshte jashte intervalit [0, 100].\n");
    }

    return 0;
}
