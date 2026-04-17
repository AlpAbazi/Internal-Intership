#include <stdio.h>

    if (start > end) {
        printf("Intervali nuk eshte valid!\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {

        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            sum5 += i;
            count5++;
        }
    }

    printf("\nRezultatet:\n");

    printf("Numrat qe pjestohet me 3:\n");
    printf("Shuma = %d, Numri = %d\n", sum3, count3);

    printf("Numrat qe pjestohet me 5 por jo me 3:\n");
    printf("Shuma = %d, Numri = %d\n", sum5, count5);

    +
    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjestohet me 3 eshte me e madhe.\n");
    }
    else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjestohet me 5 (jo me 3) eshte me e madhe.\n");
    }
    else {
        printf("Dy shumat jane te barabarta.\n");
    }

    return 0;
