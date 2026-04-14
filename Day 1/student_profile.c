#include <stdio.h>

struct Student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    struct Student student;
    printf("Enter student details...\n");
    return 0;
}