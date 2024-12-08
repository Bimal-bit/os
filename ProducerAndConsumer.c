#include <stdio.h>
#include <stdlib.h>

// Define semaphore as an integer
typedef int semaphore;

// Semaphore variables
semaphore mutex = 1;    // Mutex to control access
semaphore empty = 5;    // Tracks empty slots in the buffer
semaphore full = 0;     // Tracks filled slots in the buffer
int x = 0;              // Tracks the number of items in the buffer

// Producer function
void producer() {
    --mutex;            // Lock the critical section
    ++full;             // Increase the count of filled slots
    --empty;            // Decrease the count of empty slots
    x++;                // Increment the item count
    printf("\nProducer produced an item %d", x);
    ++mutex;            // Unlock the critical section
}

// Consumer function
void consumer() {
    --mutex;            // Lock the critical section
    --full;             // Decrease the count of filled slots
    ++empty;            // Increase the count of empty slots
    printf("\nConsumer consumed item %d", x);
    x--;                // Decrement the item count
    ++mutex;            // Unlock the critical section
}

int main() {
    int n, i;

    // Display menu
    printf("\n1. Press 1 for Producer\n");
    printf("2. Press 2 for Consumer\n");
    printf("3. Press 3 to Exit\n");

    // Loop for user interaction
    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                // Check if buffer has empty slots and mutex is available
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full\n");
                }
                break;

            case 2:
                // Check if buffer has items and mutex is available
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty\n");
                }
                break;

            case 3:
                // Exit the program
                printf("Exiting the program\n");
                exit(0);
                break;

            default:
                // Handle invalid input
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}
