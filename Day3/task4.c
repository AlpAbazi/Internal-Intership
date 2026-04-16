    int main() {
    int a;
    float b;

    int *pA;
    float *pB;

    printf("Shkruaj nje numer integer: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer float: ");
    scanf("%f", &b);

    // pointer assignment
    pA = &a;
    pB = &b;

    // para ndryshimit
    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("Adresa e a = %p\n", &a);
    printf("Vlera permes pointerit pA = %d\n", *pA);

    printf("\nb = %.2f\n", b);
    printf("Adresa e b = %p\n", &b);
    printf("Vlera permes pointerit pB = %.2f\n", *pB);

    // ndryshim permes pointerit
    *pA = *pA + 10;
    *pB = *pB + 5.5;

    // pas ndryshimit
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("b = %.2f\n", b);

    // kontrolli
    if (a > 50 && b > 50) {
        printf("Vlerat jane te medha.\n");
    } else if (a > 0 && b > 0) {
        printf("Vlerat jane pozitive.\n");
    } else if (a < 0 || b < 0) {
        printf("Ka vlera negative.\n");
    } else if (a == b) {
        printf("Vlerat jane te barabarta.\n");
    } else {
        printf("Gjendje e perzier.\n");
    }

    return 0;
}
