#include <stdio.h>

#define MAX_RECORDS 10
#define MIN_SIZE 1
#define MAX_SIZE 12

typedef enum {
    STARS,
    NUMBERS
} PatternType;

typedef struct {
    PatternType choice;
    int size;
} PatternRecord;

// Function prototypes
void printPattern(PatternType choice, int size);
PatternType readPatternChoice(void);
int readPatternSize(void);
void displayRecords(const PatternRecord records[], int count);
void updateRecord(PatternRecord *record);

void printPattern(PatternType choice, int size) {
    switch (choice) {
        case STARS:
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case NUMBERS:
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%d", j);
                }
                printf("\n");
            }
            break;
    }
}

PatternType readPatternChoice(void) {
    int choice;
    while (1) {
        printf("Choose pattern: 1 for stars, 2 for numbers: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        if (choice == 1) {
            return STARS;
        } else if (choice == 2) {
            return NUMBERS;
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }
}

int readPatternSize(void) {
    int size;
    while (1) {
        printf("Enter a positive number (%d-%d): ", MIN_SIZE, MAX_SIZE);
        if (scanf("%d", &size) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        if (size >= MIN_SIZE && size <= MAX_SIZE) {
            return size;
        } else {
            printf("Invalid input. Must be between %d and %d.\n", MIN_SIZE, MAX_SIZE);
        }
    }
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
        printf("  Pattern: %s\n", record->choice == STARS ? "Stars" : "Numbers");
        printf("  Size: %d\n", record->size);
        printf("  Output:\n");
        printPattern(record->choice, record->size);
    }
}

void updateRecord(PatternRecord *record) {
    printf("Updating record:\n");
    printf("Current pattern: %s\n", record->choice == STARS ? "Stars" : "Numbers");
    printf("Current size: %d\n", record->size);

    PatternType newChoice = readPatternChoice();
    int newSize = readPatternSize();

    record->choice = newChoice;
    record->size = newSize;

    printf("Record updated successfully.\n");
}

int main(void) {
    PatternRecord records[MAX_RECORDS];
    int recordCount = 0;
    int option;

    do {
        printf("\nMenu:\n");
        printf("  1. Add new record\n");
        printf("  2. Show all records\n");
        printf("  3. Update record\n");
        printf("  4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (recordCount >= MAX_RECORDS) {
                    printf("Cannot add new record: maximum capacity of %d reached.\n", MAX_RECORDS);
                } else {
                    PatternType choice = readPatternChoice();
                    int size = readPatternSize();
                    records[recordCount].choice = choice;
                    records[recordCount].size = size;
                    recordCount++;
                    printf("Record saved successfully. Current records: %d/%d.\n", recordCount, MAX_RECORDS);
                }
                break;

            case 2:
                displayRecords(records, recordCount);
                break;

            case 3:
                if (recordCount == 0) {
                    printf("No records to update.\n");
                } else {
                    printf("Enter record number to update (1-%d): ", recordCount);
                    int recordNum;
                    scanf("%d", &recordNum);
                    if (recordNum < 1 || recordNum > recordCount) {
                        printf("Invalid record number.\n");
                    } else {
                        updateRecord(&records[recordNum - 1]);
                    }
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option. Please choose 1, 2, 3, or 4.\n");
                break;
        }
    } while (option != 4);

    return 0;
}
