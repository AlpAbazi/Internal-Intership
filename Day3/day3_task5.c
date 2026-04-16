#include <stdio.h>

enum Level {
    Beginner,
    Intermediate,
    Advanced,
    Expert
};

int main() {
    int valid = 0, invalid = 0;
    for(int i = 0; i < 3; i++) {
        int choice;
        printf("Enter choice (0-3): ");
        scanf("%d", &choice);
        if(choice >= 0 && choice <= 3) {
            enum Level level = (enum Level)choice;
            switch(level) {
                case Beginner:
                    printf("You are a beginner.\n");
                    break;
                case Intermediate:
                    printf("You are intermediate.\n");
                    break;
                case Advanced:
                    printf("You are advanced.\n");
                    break;
                case Expert:
                    printf("You are an expert.\n");
                    break;
            }
            valid++;
        } else {
            printf("Invalid choice.\n");
            invalid++;
        }
    }
    printf("Valid choices: %d\n", valid);
    printf("Invalid choices: %d\n", invalid);
    return 0;
}