#include <stdio.h>

int main() {
   
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short viteEksperience = 2; 
    long popullsia = 1800000;  

   
    printf("Shkruani moshen: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin (nje shkronje): ");
    scanf(" %c", &iniciali); 

    printf("Shkruani gjatesine (ne metra, p.sh 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruani mesataren: ");
    scanf("%lf", &mesatarja);

    
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d vjec\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vite eksperience (short): %d\n", viteEksperience);
    printf("Popullsia (long): %ld\n", popullsia);

    return 0;
}