int main() {
    int num;
    double value;

    int *pNum = &num;
    double *pValue = &value;

    printf("Jep nje vlere int: ");
    scanf("%d", &num);

    printf("Jep nje vlere double: ");
    scanf("%lf", &value);

    int originalNum = num;
    double originalValue = value;

    printf("\n--- Vlerat fillestare ---\n");
    printf("num (direkt): %d\n", num);
    printf("Adresa e num: %p\n", (void*)&num);
    printf("Vlera e lexuar me pointer *pNum: %d\n", *pNum);

    printf("\nvalue (direkt): %.2lf\n", value);
    printf("Adresa e value: %p\n", (void*)&value);
    printf("Vlera e lexuar me pointer *pValue: %.2lf\n", *pValue);

    *pNum = *pNum + 10;
    *pValue = *pValue * 1.5;

    printf("\n--- Pas ndryshimit me pointer ---\n");
    printf("num para: %d | num pas: %d\n", originalNum, num);
    printf("value para: %.2lf | value pas: %.2lf\n", originalValue, value);

    printf("\n--- Kontrolli me if/else ---\n");

    if (num > originalNum) {
        printf("Vlera perfundimtare e num eshte rritur.\n");
    } else if (num < originalNum) {
        printf("Vlera perfundimtare e num eshte zvogeluar.\n");
    } else {
        printf("Vlera perfundimtare e num ka mbetur e njejte.\n");
    }

    if (value >= 0 && value <= 100) {
        printf("Vlera perfundimtare e value hyn ne intervalin [0, 100].\n");
    } else {
        printf("Vlera perfundimtare e value nuk hyn ne intervalin [0, 100].\n");
    }

    return 0;
}
