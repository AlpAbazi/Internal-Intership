#include <stdio.h>

int main() {
    int day;
    printf("Shkruani nje numer nga 1 deri ne 7: ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("E hene - eshte dite pune\n");
            break;
        case 2:
            printf("E marte - eshte dite pune\n");
            break;
        case 3:
            printf("E merkure - eshte dite pune\n");
            break;
        case 4:
            printf("E enjte - eshte dite pune\n");
            break;
        case 5:
            printf("E premte - eshte dite pune\n");
            break;
        case 6:
            printf("E shtune - eshte fundjave\n");
            break;
        case 7:
            printf("E diel - eshte fundjave\n");
            break;
        default:
            printf("Input i pavlefshëm\n");
            break;
    }

    return 0;
}