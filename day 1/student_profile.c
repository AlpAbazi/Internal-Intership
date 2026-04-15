'include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char email[100];
    float gpa;
} Student;

int main() {
    Student student;
    
    strcpy(student.name, "Ajdina Gashi");
    student.age = 16;
    strcpy(student.email, "ag202@bgt.school");
    student.gpa = 3.85;
    
    printf("Student Profile\n");
    printf("================\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Email: %s\n", student.email);
    printf("GPA: %.2f\n", student.gpa);
    
    return 0;
}