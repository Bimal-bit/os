#include<stdio.h>
#define Max 25 // Maximum number of memory blocks

int main() {
    // Variable declarations
    int fragment[Max], blockSize[Max], fileSize[Max];
    int i, j, numBlocks, numFiles, temp,totalInternalFragment =0;
    static int blockFlag[Max], fileToBlock[Max]; // Arrays for block allocation and file-to-block mapping

    printf("\n\tMemory Management Scheme - First Fit");

    // Input the number of memory blocks
    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    // Input the sizes of each memory block
    printf("\nEnter the size of the memory blocks:\n");
    for (i = 1; i <= numBlocks; i++) {
        printf("Block %d: ", i);
        scanf("%d", &blockSize[i]);
    }

    // Input the sizes of each file
    printf("Enter the size of the files:\n");
    for (i = 1; i <= numFiles; i++) {
        printf("File %d: ", i);
        scanf("%d", &fileSize[i]);
        fileToBlock[i] = -1; // Initialize as -1 (not allocated)
    }

    // First Fit Allocation Algorithm
    for (i = 1; i <= numFiles; i++) {
        for (j = 1; j <= numBlocks; j++) {
            if (blockFlag[j] != 1) { // Check if the block is free (not allocated)
                temp = blockSize[j] - fileSize[i]; // Calculate available space after allocation
                if (temp >= 0) { // If the block can fit the file
                    fileToBlock[i] = j; // Assign block to the file
                    fragment[i] = temp; // Store the leftover space (fragmentation)
                    blockFlag[j] = 1; // Mark the block as allocated
                    totalInternalFragment += fragment[i]; // Accumulate internal fragmentation
                    break; // Move to the next file
                }
            }
        }
    }

    // Display the results
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= numFiles; i++) {
        if (fileToBlock[i] != -1) { // Only print files that were allocated
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", 
                   i, fileSize[i], fileToBlock[i], blockSize[fileToBlock[i]], fragment[i]);
        }
    }
     // Display the total internal fragmentation
    printf("\n\nTotal Internal Fragmentation: %d", totalInternalFragment);

    return 0;

}
