#include <stdio.h>

int main() {
    int start, end;

    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    // Marrja e intervalit
    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    // Loop per analizim
    for (int i = start; i <= end; i++) {

        if (i % 2 == 0) {
            countEven++;
            sumEven += i;
        } else {
            countOdd++;
            sumOdd += i;
        }
    }

    int totalNumbers = end - start + 1;

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d, %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("\nNumra çift: %d\n", countEven);
    printf("Shuma e numrave çift: %d\n", sumEven);

    printf("\nNumra tek: %d\n", countOdd);
    printf("Shuma e numrave tek: %d\n", sumOdd);

    // Krahasimi
    if (countEven > countOdd) {
        printf("\nKa me shume numra çift.\n");
    } else if (countOdd > countEven) {
        printf("\nKa me shume numra tek.\n");
    } else {
        printf("\nNumri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}
