#include <stdio.h>

int main() {
    int start, end;
    int i;

    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    // Marrja e input-it
    printf("Shkruani fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruani fundin e intervalit: ");
    scanf("%d", &end);

    // Kontroll për input të pavlefshëm
    if (start > end) {
        printf("Gabim: Fillimi duhet te jete me i vogel se fundi.\n");
        return 1;
    }

    // For loop për intervalin
    for (i = start; i <= end; i++) {

        // Numrat që pjesëtohen me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }

        // Numrat që pjesëtohen me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            sum5 += i;
            count5++;
        }
    }

    // Shfaq rezultatet
    printf("\nRezultatet:\n");

    printf("Numrat qe pjesetohen me 3: %d\n", count3);
    printf("Shuma e tyre: %d\n", sum3);

    printf("Numrat qe pjesetohen me 5 por jo me 3: %d\n", count5);
    printf("Shuma e tyre: %d\n", sum5);

    // Krahasimi i shumave
    if (sum3 > sum5) {
        printf("\nShuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("\nShuma e numrave qe pjesetohen me 5 (jo me 3) eshte me e madhe.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}
