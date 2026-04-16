#include <stdio.h>

int main() {
    int start, end;
    int i;

    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;
    int total = 0;

    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem! Fillimi nuk mund te jete me i madh se fundi.\n");
        return 0;
    }

    for (i = start; i <= end; i++) {
        total++;

        if (i % 2 == 0) {
            countEven++;
            sumEven += i;
        } else {
            countOdd++;
            sumOdd += i;
        }
    }

    printf("\n--- Rezultatet ---\n");
    printf("Intervali: %d - %d\n", start, end);
    printf("Totali i numrave: %d\n", total);

    printf("Numra çift: %d\n", countEven);
    printf("Shuma e numrave Cift: %d\n", sumEven);

    printf("Numra tek: %d\n", countOdd);
    printf("Shuma e numrave tek: %d\n", sumOdd);

    if (countEven > countOdd) {
        printf("Ka me shume numra cift.\n");
    } else if (countOdd > countEven) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numrat cift dhe tek jane te barabarte.\n");
    }

    return 0;
}