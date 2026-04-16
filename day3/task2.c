#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Input
    printf("Shkruaj fillimin: ");
    scanf("%d", &start);

    printf("Shkruaj fundin: ");
    scanf("%d", &end);

    // Kontroll validiteti
    if(start > end) {
        printf("Interval nuk eshte valid!\n");
        return 0;
    }

    // Loop
    for(int i = start; i <= end; i++) {
        if(i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);
    printf("Total numra: %d\n", (end - start + 1));

    printf("Numra çift: %d | Shuma: %d\n", evenCount, evenSum);
    printf("Numra tek: %d | Shuma: %d\n", oddCount, oddSum);

    if(evenCount > oddCount) {
        printf("Ka me shume numra çift\n");
    }
    else if(oddCount > evenCount) {
        printf("Ka me shume numra tek\n");
    }
    else {
        printf("Jane te barabarte\n");
    }

    return 0;
}
