#include <stdio.h>

int main() {
    int fillimi, fundi;

    // Input
    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &fillimi);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &fundi);

    // Kontroll i intervalit
    if (fillimi > fundi) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 0;
    }

    int countCift = 0, countTek = 0;
    int shumaCift = 0, shumaTek = 0;
    int total = 0;

    // Loop
    for (int i = fillimi; i <= fundi; i++) {
        total++;

        if (i % 2 == 0) {
            countCift++;
            shumaCift += i;
        } else {
            countTek++;
            shumaTek += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d - %d]\n", fillimi, fundi);
    printf("Totali i numrave: %d\n", total);

    printf("Numra çift: %d | Shuma: %d\n", countCift, shumaCift);
    printf("Numra tek: %d | Shuma: %d\n", countTek, shumaTek);

    // Krahasimi
    if (countCift > countTek) {
        printf("Ka me shume numra çift.\n");
    } else if (countTek > countCift) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}
