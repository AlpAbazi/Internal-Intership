#include <stdio.h>

typedef struct {
    char name[100];
    char surname[100];
    int age;
    char email[100];
} StudentProfile;

int main() {
    StudentProfile student;
    
    // Initialize student profile
    snprintf(student.name, sizeof(student.name), "Amar");
    snprintf(student.surname, sizeof(student.surname), "Turbedari");
    student.age = 0;  // Add your age here
    snprintf(student.email, sizeof(student.email), "");  // Add your email here
    
    printf("Student Profile\n");
    printf("================\n");
    printf("Name: %s\n", student.name);
    printf("Surname: %s\n", student.surname);
    printf("Age: %d\n", student.age);
    printf("Email: %s\n", student.email);
    
    return 0;
}
