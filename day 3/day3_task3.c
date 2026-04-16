#include <stdio.h>

int main() {
    int start, end;
    int countDiv3 = 0, countDiv5Not3 = 0;
    int sumDiv3 = 0, sumDiv5Not3 = 0;

    printf("Jep fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Jep fundin e intervalit: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        } else if (i % 5 == 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    printf("\n--- Rezultatet ---\n");
    printf("Intervali: [%d, %d]\n", start, end);

    printf("Numra qe pjesetohen me 3: %d\n", countDiv3);
    printf("Shuma e numrave qe pjesetohen me 3: %d\n", sumDiv3);

    printf("Numra qe pjesetohen me 5 por jo me 3: %d\n", countDiv5Not3);
    printf("Shuma e numrave qe pjesetohen me 5 por jo me 3: %d\n", sumDiv5Not3);

    if (sumDiv3 > sumDiv5Not3) {
        printf("Shuma e pare eshte me e madhe.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("Shuma e dyte eshte me e madhe.\n");
    } else {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}
