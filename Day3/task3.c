    int main() {
    int start, end;

    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    // validim
    if (start > end) {
        printf("Interval jo valid!\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {

        // pjesëtohet me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }

        // pjesëtohet me 5 por jo me 3
        else if (i % 5 == 0) {
            sum5 += i;
            count5++;
        }
    }

    printf("\nIntervali: %d - %d\n", start, end);

    printf("\nNumrat qe pjestohet me 3:\n");
    printf("Numri: %d\n", count3);
    printf("Shuma: %d\n", sum3);

    printf("\nNumrat qe pjestohet me 5 por jo me 3:\n");
    printf("Numri: %d\n", count5);
    printf("Shuma: %d\n", sum5);

    // krahasimi
    if (sum3 > sum5) {
        printf("\nMe e madhe eshte shuma e numrave me 3.\n");
    } else if (sum5 > sum3) {
        printf("\nMe e madhe eshte shuma e numrave me 5.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}
