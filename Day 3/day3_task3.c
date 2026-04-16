#include <stdio.h>

int main() {
    int start, end;
    int i;

    int count3 = 0, sum3 = 0;
    int count5not3 = 0, sum5not3 = 0;

    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem! Fillimi nuk mund te jete me i madh se fundi.\n");
        return 0;
    }

    for (i = start; i <= end; i++) {

        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }

        if (i % 5 == 0 && i % 3 != 0) {
            count5not3++;
            sum5not3 += i;
        }
    }

    printf("\n--- Rezultatet ---\n");
    printf("Intervali: %d - %d\n", start, end);

    printf("\nKategoria 1 (pjesetohen me 3):\n");
    printf("Numri i elementeve: %d\n", count3);
    printf("Shuma: %d\n", sum3);

    printf("\nKategoria 2 (pjesetohen me 5 por jo me 3):\n");
    printf("Numri i elementeve: %d\n", count5not3);
    printf("Shuma: %d\n", sum5not3);

    printf("\n--- Krahasimi ---\n");

    if (sum3 > sum5not3) {
        printf("Shuma e numrave te pjesetueshem me 3 eshte me e madhe.\n");
    } else if (sum5not3 > sum3) {
        printf("Shuma e numrave (5 por jo 3) eshte me e madhe.\n");
    } else {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}