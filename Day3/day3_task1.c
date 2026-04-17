#include <stdio.h>

#define MAX_RECORDS 10
#define MIN_SIZE 1
#define MAX_SIZE 12

typedef struct {
    int choice; // 1 = stars, 2 = numbers
    int size;
} PatternRecord;

void printPattern(int choice, int size) {
    if (choice == 1) {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d", j);
            }
            printf("\n");
        }
    }
}

int readPatternChoice(void) {
    int choice;
    printf("Choose pattern: 1 for stars, 2 for numbers: ");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Please enter 1 or 2.\n");
        return 0;
    }
    return choice;
}

int readPatternSize(void) {
    int size;
    printf("Enter a positive number (%d-%d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid input. Must be between %d and %d.\n", MIN_SIZE, MAX_SIZE);
        return 0;
    }
    return size;
}

void displayRecords(const PatternRecord records[], int count) {
    if (count == 0) {
        printf("No saved records available.\n");
        return;
    }

    printf("Saved records (%d/%d):\n", count, MAX_RECORDS);
    for (int i = 0; i < count; i++) {
        const PatternRecord *record = &records[i];
        printf("\nRecord %d:\n", i + 1);
        printf("  Pattern: %s\n", record->choice == 1 ? "Stars" : "Numbers");
        printf("  Size: %d\n", record->size);
        printf("  Output:\n");
        printPattern(record->choice, record->size);
    }
}

int main(void) {
    PatternRecord records[MAX_RECORDS];
    int recordCount = 0;
    int option;

    do {
        printf("\nMenu:\n");
        printf("  1. Add new record\n");
        printf("  2. Show all records\n");
        printf("  3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (recordCount >= MAX_RECORDS) {
                    printf("Cannot add new record: maximum capacity of %d reached.\n", MAX_RECORDS);
                } else {
                    int choice = readPatternChoice();
                    int size = readPatternSize();
                    if (choice && size) {
                        records[recordCount].choice = choice;
                        records[recordCount].size = size;
                        recordCount++;
                        printf("Record saved successfully. Current records: %d/%d.\n", recordCount, MAX_RECORDS);
                    }
                }
                break;

            case 2:
                displayRecords(records, recordCount);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option. Please choose 1, 2, or 3.\n");
                break;
        }
    } while (option != 3);

    return 0;
}
