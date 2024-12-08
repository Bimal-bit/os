#include<stdio.h>
#define Max 25 // Maximum number of memory blocks

int main() {
    // Variable declarations
    int fragmentation[Max], blockSize[Max], fileSize[Max];
    int i, j, numBlocks, numFiles, temp, smallestFragmentation = 10000;
    int totalInternalFragmentation = 0; // Variable to store total internal fragmentation
    static int blockAllocated[Max], fileToBlock[Max]; // Allocation and file-block mapping

    printf("\n\tMemory Management Scheme - Best Fit");

    // Input number of blocks
    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    // Input number of files
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    // Input the sizes of memory blocks
    printf("\nEnter the sizes of the memory blocks:\n");
    for (i = 1; i <= numBlocks; i++) {
        printf("Block %d: ", i);
        scanf("%d", &blockSize[i]);
    }

    // Input the sizes of the files
    printf("Enter the sizes of the files:\n");
    for (i = 1; i <= numFiles; i++) {
        printf("File %d: ", i);
        scanf("%d", &fileSize[i]);
        fileToBlock[i] = -1; // Initialize as not allocated
    }

    // Best Fit Allocation Algorithm
    for (i = 1; i <= numFiles; i++) {
        for (j = 1; j <= numBlocks; j++) {
            if (blockAllocated[j] != 1) { // Check if the block is free
                temp = blockSize[j] - fileSize[i]; // Calculate space after allocation
                if (temp >= 0 && temp < smallestFragmentation) { // Choose the smallest fit
                    fileToBlock[i] = j; // Assign block to the file
                    smallestFragmentation = temp; // Update the smallest fragmentation
                }
            }
        }

        // If a block was allocated, update fragmentation and mark the block as allocated
        if (fileToBlock[i] != -1) {
            fragmentation[i] = smallestFragmentation;
            totalInternalFragmentation += fragmentation[i]; // Add to total internal fragmentation
            blockAllocated[fileToBlock[i]] = 1; // Mark block as allocated
        }

        // Reset smallestFragmentation for the next file
        smallestFragmentation = 10000;
    }

    // Display allocation details
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragmentation");
    for (i = 1; i <= numFiles; i++) {
        if (fileToBlock[i] != -1) { // Only display allocated files
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i, fileSize[i], fileToBlock[i], blockSize[fileToBlock[i]], fragmentation[i]);
        }
    }

    // Display total internal fragmentation
    printf("\n\nTotal Internal Fragmentation: %d", totalInternalFragmentation);

    return 0;

}
