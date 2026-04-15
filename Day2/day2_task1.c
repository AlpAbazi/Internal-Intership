#include <stdio.h>

int main(void) {
    int age;
    char initial;
    float height;
    double average_score;
    short num_courses;
    long annual_income;

    printf("Ju lutem shkruani moshën tuaj (int): ");
    scanf("%d", &age);

    printf("Ju lutem shkruani inicialin tuaj (char): ");
    scanf(" %c", &initial);

    printf("Ju lutem shkruani gjatësinë tuaj në metra (float): ");
    scanf("%f", &height);

    printf("Ju lutem shkruani mesataren tuaj të notave (double): ");
    scanf("%lf", &average_score);

    printf("Ju lutem shkruani numrin e kurseve që keni ndjekur (short): ");
    scanf("%hd", &num_courses);

    printf("Ju lutem shkruani të ardhurat vjetore në lekë (long): ");
    scanf("%ld", &annual_income);

    printf("\n--- Profil i shkurtër i përdoruesit ---\n");
    printf("Mosha (int): %d\n", age);
    printf("Iniciali (char): %c\n", initial);
    printf("Gjatësia (float): %.2f metra\n", height);
    printf("Mesatarja (double): %.2lf\n", average_score);
    printf("Numri i kurseve (short): %hd\n", num_courses);
    printf("Të ardhurat vjetore (long): %ld lekë\n", annual_income);

    return 0;
}
