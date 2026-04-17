#include <stdio.h>

/* Maximum number of student records the program can store */
#define MAX_STUDENTS 10
#define NAME_SIZE 50

/* Enum for the student's progress category */
enum Status {
    BEGINNER = 1,
    IMPROVING,
    GOOD,
    EXCELLENT
};

/* Structure that stores one student record */
struct Student {
    int id;
    char name[NAME_SIZE];
    double score;
    enum Status status;
};

/* Clear invalid input from the keyboard buffer */
void clearInputBuffer(void) {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Keep reading until the line is cleared */
    }
}

/* Read an integer safely from the user */
int readInteger(const char prompt[]) {
    int value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1) {
            clearInputBuffer();
            return value;
        }

        printf("Invalid input. Please enter a whole number.\n");
        clearInputBuffer();
    }
}

/* Read a positive integer, useful for student IDs */
int readPositiveInteger(const char prompt[]) {
    int value;

    while (1) {
        value = readInteger(prompt);

        if (value > 0) {
            return value;
        }

        printf("Invalid input. Please enter a number greater than 0.\n");
    }
}

/* Read a name and make sure it is not empty */
void readName(char name[]) {
    int i;

    while (1) {
        printf("Enter student name: ");
        fgets(name, NAME_SIZE, stdin);

        /* Remove the newline character from the end of the name */
        for (i = 0; i < NAME_SIZE; i++) {
            if (name[i] == '\n') {
                name[i] = '\0';
                break;
            }
        }

        if (name[0] != '\0') {
            return;
        }

        printf("Invalid name. The name cannot be empty.\n");
    }
}

/* Read a score safely and make sure it is between 0 and 100 */
double readScore(void) {
    double score;
    int result;

    while (1) {
        printf("Enter student score (0 - 100): ");
        result = scanf("%lf", &score);

        if (result == 1) {
            clearInputBuffer();

            if (score >= 0 && score <= 100) {
                return score;
            }

            printf("Invalid score. The score must be between 0 and 100.\n");
        } else {
            printf("Invalid input. Please enter a number for the score.\n");
            clearInputBuffer();
        }
    }
}

/* This function uses a pointer to store the chosen enum value */
void setStatus(enum Status *status, enum Status chosenStatus) {
    *status = chosenStatus;
}

/* Convert enum status to text so it prints as a word */
const char *getStatusText(enum Status status) {
    switch (status) {
        case BEGINNER:
            return "BEGINNER";
        case IMPROVING:
            return "IMPROVING";
        case GOOD:
            return "GOOD";
        case EXCELLENT:
            return "EXCELLENT";
        default:
            return "UNKNOWN";
    }
}

/* Let the user choose a student status using a second switch */
enum Status chooseStatus(void) {
    int choice;
    enum Status selectedStatus;

    while (1) {
        printf("\nChoose student status:\n");
        printf("1. Beginner\n");
        printf("2. Improving\n");
        printf("3. Good\n");
        printf("4. Excellent\n");

        choice = readInteger("Enter status choice: ");

        switch (choice) {
            case 1:
                selectedStatus = BEGINNER;
                return selectedStatus;
            case 2:
                selectedStatus = IMPROVING;
                return selectedStatus;
            case 3:
                selectedStatus = GOOD;
                return selectedStatus;
            case 4:
                selectedStatus = EXCELLENT;
                return selectedStatus;
            default:
                printf("Invalid status choice. Please choose 1, 2, 3, or 4.\n");
        }
    }
}

/* Add one new student to the array */
void addStudent(struct Student students[], int *studentCount) {
    struct Student newStudent;
    enum Status chosenStatus;

    if (*studentCount >= MAX_STUDENTS) {
        printf("\nThe student list is full. You cannot add more students.\n");
        return;
    }

    printf("\n--- Add Student Record ---\n");

    newStudent.id = readPositiveInteger("Enter student ID: ");
    readName(newStudent.name);

    newStudent.score = readScore();

    chosenStatus = chooseStatus();
    setStatus(&newStudent.status, chosenStatus);

    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("\nStudent record added successfully.\n");
    printf("Stored status: %s\n", getStatusText(newStudent.status));
}

/* Display all stored student records */
void showStudents(struct Student students[], int studentCount) {
    int i;

    printf("\n--- Student Records ---\n");

    if (studentCount == 0) {
        printf("No student records have been added yet.\n");
        return;
    }

    printf("%-5s %-20s %-10s %-12s\n", "ID", "Name", "Score", "Status");
    printf("----------------------------------------------------\n");

    for (i = 0; i < studentCount; i++) {
        printf("%-5d %-20s %-10.2f %-12s\n",
               students[i].id,
               students[i].name,
               students[i].score,
               getStatusText(students[i].status));
    }
}

/* Show a short analytics report about all saved students */
void showAnalyticsReport(struct Student students[], int studentCount) {
    int i;
    int beginnerCount = 0;
    int improvingCount = 0;
    int goodCount = 0;
    int excellentCount = 0;
    int successfulCount = 0;
    double totalScore = 0;
    double averageScore;
    double highestScore;
    double lowestScore;

    printf("\n--- Analytics Report ---\n");

    if (studentCount == 0) {
        printf("No student records found.\n");
        printf("Add students first before viewing the report.\n");
        return;
    }

    highestScore = students[0].score;
    lowestScore = students[0].score;

    /* Go through each student and calculate report values */
    for (i = 0; i < studentCount; i++) {
        totalScore = totalScore + students[i].score;

        if (students[i].score > highestScore) {
            highestScore = students[i].score;
        }

        if (students[i].score < lowestScore) {
            lowestScore = students[i].score;
        }

        if (students[i].score >= 50) {
            successfulCount++;
        }

        if (students[i].status == BEGINNER) {
            beginnerCount++;
        } else if (students[i].status == IMPROVING) {
            improvingCount++;
        } else if (students[i].status == GOOD) {
            goodCount++;
        } else if (students[i].status == EXCELLENT) {
            excellentCount++;
        }
    }

    averageScore = totalScore / studentCount;

    printf("Total records:      %d\n", studentCount);
    printf("Average score:      %.2f\n", averageScore);
    printf("Highest score:      %.2f\n", highestScore);
    printf("Lowest score:       %.2f\n", lowestScore);
    printf("Successful records: %d\n", successfulCount);

    printf("\nStatus counts:\n");
    printf("Beginner:           %d\n", beginnerCount);
    printf("Improving:          %d\n", improvingCount);
    printf("Good:               %d\n", goodCount);
    printf("Excellent:          %d\n", excellentCount);

    printf("\nResult message: ");

    if (averageScore >= 80) {
        printf("Great work! The class average is high.\n");
    } else if (averageScore >= 50) {
        printf("Good progress. Some improvement is still possible.\n");
    } else {
        printf("Improvement is needed. The average score is low.\n");
    }
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    int running = 1;

    /* The menu keeps running until the user chooses Exit */
    while (running) {
        printf("\n==============================\n");
        printf(" Student Progress Tracker\n");
        printf("==============================\n");
        printf("1. Add student record\n");
        printf("2. Show all student records\n");
        printf("3. Show analytics report\n");
        printf("4. Exit program\n");

        choice = readInteger("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                showStudents(students, studentCount);
                break;
            case 3:
                showAnalyticsReport(students, studentCount);
                break;
            case 4:
                running = 0;
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid menu choice. Please choose 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
