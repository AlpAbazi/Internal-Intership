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
void sortRecordsByTypeAndSize(PatternRecord records[], int count);
void displayRankedRecords(const PatternRecord records[], int count);

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

void sortRecordsByTypeAndSize(PatternRecord records[], int count) {
    // Bubble sort: first by pattern type (STARS before NUMBERS), then by size (ascending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int shouldSwap = 0;
            
            // First, sort by pattern type (STARS=0 comes before NUMBERS=1)
            if (records[j].choice > records[j + 1].choice) {
                shouldSwap = 1;
            }
            // If pattern types are the same, sort by size (ascending)
            else if (records[j].choice == records[j + 1].choice && 
                     records[j].size > records[j + 1].size) {
                shouldSwap = 1;
            }
            
            if (shouldSwap) {
                // Swap records
                PatternRecord temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void displayRankedRecords(const PatternRecord records[], int count) {
    if (count == 0) {
        printf("No saved records available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("         RANKED RECORDS (Sorted)\n");
    printf("========================================\n");
    printf("Ranking by: Pattern Type → Size (ascending)\n");
    printf("========================================\n\n");

    for (int i = 0; i < count; i++) {
        const PatternRecord *record = &records[i];
        printf("Rank #%d:\n", i + 1);
        printf("  Pattern Type: %s\n", record->choice == STARS ? "★ STARS" : "# NUMBERS");
        printf("  Size: %d\n", record->size);
        printf("  Example Output (first 3 rows):\n");
        
        // Show only first 3 rows for compact display
        int rows_to_show = record->size < 3 ? record->size : 3;
        for (int row = 1; row <= rows_to_show; row++) {
            printf("    ");
            if (record->choice == STARS) {
                for (int col = 1; col <= row; col++) {
                    printf("*");
                }
            } else {
                for (int col = 1; col <= row; col++) {
                    printf("%d", col);
                }
            }
            printf("\n");
        }
        if (record->size > 3) {
            printf("    ... (pattern continues to size %d)\n", record->size);
        }
        printf("\n");
    }
    printf("========================================\n\n");
}

int main(void) {
    PatternRecord records[MAX_RECORDS];
    int recordCount = 0;
    int option;

    printf("\n╔════════════════════════════════════════╗\n");
    printf("║    Pattern Manager - Mini Project    ║\n");
    printf("║  Manage and rank pattern records!    ║\n");
    printf("╚════════════════════════════════════════╝\n");

    do {
        printf("\n┌─ MAIN MENU ─────────────────────────────┐\n");
        printf("│  1. Add new record                      │\n");
        printf("│  2. Show all records                    │\n");
        printf("│  3. Update record                       │\n");
        printf("│  4. View ranked records (sorted)        │\n");
        printf("│  5. Exit                                │\n");
        printf("└─────────────────────────────────────────┘\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (recordCount >= MAX_RECORDS) {
                    printf("\n❌ Cannot add new record: maximum capacity of %d reached.\n", MAX_RECORDS);
                } else {
                    printf("\n➕ Adding new record...\n");
                    PatternType choice = readPatternChoice();
                    int size = readPatternSize();
                    records[recordCount].choice = choice;
                    records[recordCount].size = size;
                    recordCount++;
                    printf("✓ Record saved successfully. Current records: %d/%d.\n", recordCount, MAX_RECORDS);
                }
                break;

            case 2:
                printf("\n📋 Displaying all records...\n");
                displayRecords(records, recordCount);
                break;

            case 3:
                if (recordCount == 0) {
                    printf("\n⚠ No records to update.\n");
                } else {
                    printf("\n✏️  Updating record...\n");
                    printf("Enter record number to update (1-%d): ", recordCount);
                    int recordNum;
                    scanf("%d", &recordNum);
                    if (recordNum < 1 || recordNum > recordCount) {
                        printf("❌ Invalid record number.\n");
                    } else {
                        updateRecord(&records[recordNum - 1]);
                    }
                }
                break;

            case 4:
                if (recordCount == 0) {
                    printf("\n⚠ No records to rank.\n");
                } else {
                    printf("\n🏆 Generating ranking...\n");
                    // Create a copy of records for sorting (to preserve original order)
                    PatternRecord sortedRecords[MAX_RECORDS];
                    for (int i = 0; i < recordCount; i++) {
                        sortedRecords[i] = records[i];
                    }
                    // Sort the copy
                    sortRecordsByTypeAndSize(sortedRecords, recordCount);
                    // Display the ranked results
                    displayRankedRecords(sortedRecords, recordCount);
                }
                break;

            case 5:
                printf("\n👋 Thank you for using Pattern Manager!\n");
                printf("   Exiting program...\n\n");
                break;

            default:
                printf("\n❌ Invalid option. Please choose 1-5.\n");
                break;
        }
    } while (option != 5);

    return 0;
}
