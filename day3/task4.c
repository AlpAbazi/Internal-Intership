#include <stdio.h>

int main() {
    int a, oldA;
    float b;
    int *pA;
    float *pB;

    printf("Shkruaj nje vlere int: ");
    scanf("%d", &a);

    printf("Shkruaj nje vlere float: ");
    scanf("%f", &b);

    pA = &a;
    pB = &b;

    oldA = a;

    printf("\n----- VLERAT FILLESTARE -----\n");
    printf("Vlera direkte e a: %d\n", a);
    printf("Adresa e a: %p\n", (void*)&a);
    printf("Vlera e a permes pointer-it: %d\n", *pA);

    printf("\nVlera direkte e b: %.2f\n", b);
    printf("Adresa e b: %p\n", (void*)&b);
    printf("Vlera e b permes pointer-it: %.2f\n", *pB);

    printf("\n----- NDRYSHIMI PERMES POINTER-IT -----\n");
    printf("Vlera e a para ndryshimit: %d\n", *pA);

    *pA = *pA + 10;

    printf("Vlera e a pas ndryshimit: %d\n", *pA);

    printf("\n----- ANALIZA FINALE -----\n");
    if (*pA > oldA) {
        printf("Vlera perfundimtare eshte rritur.\n");
    } else if (*pA < oldA) {
        printf("Vlera perfundimtare eshte zvogeluar.\n");
    } else {
        printf("Vlera perfundimtare ka mbetur e njejte.\n");
    }

    if (*pA >= 0 && *pA <= 50) {
        printf("Vlera perfundimtare hyn ne intervalin 0 deri 50.\n");
    } else {
        printf("Vlera perfundimtare eshte jashte intervalit 0 deri 50.\n");
    }

    return 0;
}
