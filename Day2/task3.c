#include <stdio.h>

int main() {
    int day;

    printf("Shkruaj nje numer (1-7): ");
    scanf("%d", &day);

    switch(day) {
        case 1:
            printf("E hene - Dite pune\n");
            break;
        case 2:
            printf("E marte - Dite pune\n");
            break;
        case 3:
            printf("E merkure - Dite pune\n");
            break;
        case 4:
            printf("E enjte - Dite pune\n");
            break;
        case 5:
            printf("E premte - Dite pune\n");
            break;
        case 6:
            printf("E shtune - Fundjave\n");
            break;
        case 7:
            printf("E diele - Fundjave\n");
            break;
        default:
            printf("Input nuk eshte valid!\n");
    }

    return 0;
}
