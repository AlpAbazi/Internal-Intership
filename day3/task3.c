#include <stdio.h>

int main() {
    int start, end;
    int count3 = 0, count5 = 0;
    int sum3 = 0, sum5 = 0;

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

        // Pjestohen me 3
        if(i % 3 == 0) {
            count3++;
            sum3 += i;
        }
        // Pjestohen me 5 por JO me 3
        else if(i % 5 == 0 && i % 3 != 0) {
            count5++;
            sum5 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);

    printf("Pjestohen me 3: %d | Shuma: %d\n", count3, sum3);
    printf("Pjestohen me 5 (jo me 3): %d | Shuma: %d\n", count5, sum5);

    // Krahasimi
    if(sum3 > sum5) {
        printf("Shuma e numrave qe pjestohen me 3 eshte me e madhe\n");
    }
    else if(sum5 > sum3) {
        printf("Shuma e numrave qe pjestohen me 5 eshte me e madhe\n");
    }
    else {
        printf("Shumat jane te barabarta\n");
    }

    return 0;
}
