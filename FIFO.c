#include <stdio.h>
#include <stdbool.h>

void main() {
    // Variable declarations
    int numPages, numFrames;
    int pages[100], frames[100];
    int i, j, pageFaults = 0, pageHits = 0, currentIndex = 0;
    bool isPageInFrame;

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    // Input the pages
    printf("Enter the page sequence: ");
    for (i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    // Initialize frames with -1 (empty)
    for (i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    // FIFO page replacement logic
    for (i = 0; i < numPages; i++) {
        isPageInFrame = false;

        // Check if the current page is already in a frame
        for (j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                pageHits++; // Page is already in a frame (hit)
                isPageInFrame = true;
                break;
            }
        }

        // If the page is not in a frame (miss), replace the oldest page
        if (!isPageInFrame) {
            frames[currentIndex] = pages[i]; // Replace page at current index
            currentIndex = (currentIndex + 1) % numFrames; // Move to the next frame index
            pageFaults++; // Increment page fault count
        }

        // Display the current frame contents
        printf("\nFrames after processing page %d: ", pages[i]);
        for (j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
    }

    // Output the total page hits and page faults
    printf("\n\nTotal Page Hits: %d", pageHits);
    printf("\nTotal Page Faults: %d\n", pageFaults);
}
