#include <stdio.h>

int main() {
    int num;
    float grade;

    int oldNum;
    float oldGrade;

    int *pNum;
    float *pGrade;

    // Input
    printf("Shkruaj nje numer int: ");
    scanf("%d", &num);

    printf("Shkruaj nje numer float: ");
    scanf("%f", &grade);

    // Ruaj vlerat para ndryshimit
    oldNum = num;
    oldGrade = grade;

    // Pointerat marrin adresat
    pNum = &num;
    pGrade = &grade;

    // Output para ndryshimit
    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("Num direct: %d\n", num);
    printf("Num address: %p\n", (void*)&num);
    printf("Num me pointer: %d\n", *pNum);

    printf("Grade direct: %.2f\n", grade);
    printf("Grade address: %p\n", (void*)&grade);
    printf("Grade me pointer: %.2f\n", *pGrade);

    // Ndryshimi permes pointer-it
    *pNum = *pNum + 10;
    *pGrade = *pGrade + 1.5f;

    // Output pas ndryshimit
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("Num para: %d | Num pas: %d\n", oldNum, num);
    printf("Grade para: %.2f | Grade pas: %.2f\n", oldGrade, grade);

    // Kontroll me if / else
    printf("\n--- REZULTATI FINAL ---\n");

    if (num > oldNum) {
        printf("Vlera e num eshte rritur.\n");
    }
    else if (num < oldNum) {
        printf("Vlera e num eshte zvogeluar.\n");
    }
    else {
        printf("Vlera e num ka mbetur e njejte.\n");
    }

    if (grade >= 0 && grade <= 10) {
        printf("Grade eshte brenda intervalit 0 deri 10.\n");
    }
    else {
        printf("Grade eshte jashte intervalit 0 deri 10.\n");
    }

    return 0;
}
