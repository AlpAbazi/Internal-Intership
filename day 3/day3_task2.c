#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalValues = 0;

    printf("Jep vleren fillestare te intervalit: ");
    scanf("%d", &start);

    printf("Jep vleren perfundimtare te intervalit: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        totalValues++;

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    printf("\n--- Rezultatet ---\n");
    printf("Intervali: [%d, %d]\n", start, end);
    printf("Totali i vlerave: %d\n", totalValues);
    printf("Numra cift: %d\n", evenCount);
    printf("Numra tek: %d\n", oddCount);
    printf("Shuma e numrave cift: %d\n", evenSum);
    printf("Shuma e numrave tek: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Kategoria me me shume numra: Cift\n");
    } else if (oddCount > evenCount) {
        printf("Kategoria me me shume numra: Tek\n");
    } else {
        printf("Te dy kategorite kane numer te barabarte elementesh.\n");
    }

    return 0;
}
