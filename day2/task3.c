#include <stdio.h>

int main() {
    int day;

    printf("Enter a number from 1 to 7: ");
    scanf("%d", &day);

    switch(day) {
        case 1:
            printf("Monday\n");
            printf("It is a working day.\n");
            break;
        case 2:
            printf("Tuesday\n");
            printf("It is a working day.\n");
            break;
        case 3:
            printf("Wednesday\n");
            printf("It is a working day.\n");
            break;
        case 4:
            printf("Thursday\n");
            printf("It is a working day.\n");
            break;
        case 5:
            printf("Friday\n");
            printf("It is a working day.\n");
            break;
        case 6:
            printf("Saturday\n");
            printf("It is the weekend.\n");
            break;
        case 7:
            printf("Sunday\n");
            printf("It is the weekend.\n");
            break;
        default:
            printf("Invalid input. Please enter a number from 1 to 7.\n");
    }

    return 0;
}
