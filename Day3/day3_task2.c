#include <stdio.h>

int main() {
    int start, end;
    printf("Enter start: ");
    scanf("%d", &start);
    printf("Enter end: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval: start must be <= end.\n");
        return 1;
    }

    int even_count = 0, odd_count = 0;
    int even_sum = 0, odd_sum = 0;
    int total = 0;

    for (int i = start; i <= end; i++) {
        total++;
        if (i % 2 == 0) {
            even_count++;
            even_sum += i;
        } else {
            odd_count++;
            odd_sum += i;
        }
    }

    printf("Interval: %d to %d\n", start, end);
    printf("Total values: %d\n", total);
    printf("Even count: %d, Sum: %d\n", even_count, even_sum);
    printf("Odd count: %d, Sum: %d\n", odd_count, odd_sum);

    if (even_count > odd_count) {
        printf("More even numbers.\n");
    } else if (odd_count > even_count) {
        printf("More odd numbers.\n");
    } else {
        printf("Equal number of even and odd.\n");
    }

    return 0;
}