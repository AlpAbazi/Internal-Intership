#include <stdio.h>

int main() {
    // Deklarimi i variablave numerike
    int number_int = 0;
    float number_float = 0.0;
    
    // Deklarimi i pointera
    int *ptr_int = &number_int;
    float *ptr_float = &number_float;
    
    // Variabla për ruajtjen e vlerave origjinale
    int original_int = 0;
    float original_float = 0.0;
    
    // Variabla për kontrollimin e intervalit
    int lower_bound = -100;
    int upper_bound = 100;
    
    int test_count = 1;
    
    printf("========================================\n");
    printf("    PROGRAMI PER PUNIMIN ME POINTERS     \n");
    printf("    INT DHE FLOAT - TESTIM KOMPREHENSIV \n");
    printf("========================================\n\n");
    
    // Testimi me values të ndryshme
    int test_values_int[] = {
        5, -10, 0, 100, -50, 1, -1, 42, -99, 25,
        50, -75, 10, -25, 999, -500, 15, -8, 33, 0
    };
    
    float test_values_float[] = {
        3.5, -2.7, 0.0, 15.8, -9.3, 1.1, -0.5, 42.2, -99.9, 25.5,
        50.1, -75.6, 10.3, -25.8, 99.9, -50.0, 15.4, -8.2, 33.7, 0.0
    };
    
    // Looping përmes test values
    for (int i = 0; i < 20; i++) {
        printf("\n--- TEST CASE %d ---\n", test_count);
        printf("Inputi (INT): %d\n", test_values_int[i]);
        printf("Inputi (FLOAT): %.2f\n\n", test_values_float[i]);
        
        // Caktojmë vlerat përmes pointerave
        *ptr_int = test_values_int[i];
        *ptr_float = test_values_float[i];
        
        // Ruajmë vlerat origjinale
        original_int = *ptr_int;
        original_float = *ptr_float;
        
        printf("VLERAT FILLESTARE:\n");
        printf("  INT - Adresa: %p, Vlera direkte: %d, Përmes pointer: %d\n", 
               (void*)ptr_int, number_int, *ptr_int);
        printf("  FLOAT - Adresa: %p, Vlera direkte: %.2f, Përmes pointer: %.2f\n\n", 
               (void*)ptr_float, number_float, *ptr_float);
        
        // Modifikimi i vlerave përmes pointerave
        *ptr_int = *ptr_int + 10;  // Zmadhojmë INT me 10
        *ptr_float = *ptr_float * 2.0;  // Dyfishojmë FLOAT
        
        printf("VLERAT PARE NDRYSHIMIT:\n");
        printf("  INT: %d\n", original_int);
        printf("  FLOAT: %.2f\n\n", original_float);
        
        printf("VLERAT PAS NDRYSHIMIT:\n");
        printf("  INT: %d (operacioni: +10)\n", *ptr_int);
        printf("  FLOAT: %.2f (operacioni: *2)\n\n", *ptr_float);
        
        // Kontroll me if/else për INT
        printf("ANALIZA I NDRYSHIMIT (INT):\n");
        if (*ptr_int > original_int) {
            printf("  Rezultati: RRITUR (rritet nga %d në %d)\n", original_int, *ptr_int);
        } else if (*ptr_int < original_int) {
            printf("  Rezultati: ZVOGËLUAR (zvogëlohet nga %d në %d)\n", original_int, *ptr_int);
        } else {
            printf("  Rezultati: MBETI E NJËJTË (ngel në %d)\n", *ptr_int);
        }
        
        // Kontroll intervali
        if (*ptr_int >= lower_bound && *ptr_int <= upper_bound) {
            printf("  Intervali: BRENDA intervalit [%d, %d]\n", lower_bound, upper_bound);
        } else {
            printf("  Intervali: JASHTA intervalit [%d, %d]\n", lower_bound, upper_bound);
        }
        
        // Kontroll me if/else për FLOAT
        printf("\nANALIZA I NDRYSHIMIT (FLOAT):\n");
        if (*ptr_float > original_float) {
            printf("  Rezultati: RRITUR (rritet nga %.2f në %.2f)\n", original_float, *ptr_float);
        } else if (*ptr_float < original_float) {
            printf("  Rezultati: ZVOGËLUAR (zvogëlohet nga %.2f në %.2f)\n", original_float, *ptr_float);
        } else {
            printf("  Rezultati: MBETI E NJËJTË (ngel në %.2f)\n", *ptr_float);
        }
        
        // Kontroll intervali për float
        if (*ptr_float >= -100.0 && *ptr_float <= 100.0) {
            printf("  Intervali: BRENDA intervalit [-100.0, 100.0]\n");
        } else {
            printf("  Intervali: JASHTA intervalit [-100.0, 100.0]\n");
        }
        
        printf("\n========================================\n");
        test_count++;
    }
    
    printf("\nPROGRAMI MBAROI TESTIMIN E TE GJITHA %d RASTEVE.\n", 20);
    printf("========================================\n");
    
    return 0;
}
