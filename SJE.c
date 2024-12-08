#include<stdio.h>

int main () {
    // Variable declarations
    int i, j, n;                // Loop counters and number of processes
    int bt[20], wt[20], p[20];  // Arrays for burst time, waiting time, and process IDs
    int tat[20], pos, temp;     // Array for turnaround time, position tracker, and temporary variable for swapping
    float avtat = 0, avwt = 0;  // Average turnaround time and average waiting time

    // Input: Number of processes
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    // Input: Burst times for each process
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Assign process IDs (P[1], P[2], ...)
    }

    // Sort processes based on burst time using selection sort
    for (i = 0; i < n; i++) {
        pos = i; // Assume the current process has the smallest burst time
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos]) {
                pos = j; // Update position if a smaller burst time is found
            }
        }
        // Swap burst times
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap process IDs to maintain correspondence
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Initialize waiting time for the first process
    wt[0] = 0;

    // Calculate waiting times for each process
    for (i = 1; i < n; i++) { // Start from the second process
        wt[i] = 0;            // Initialize waiting time
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];    // Accumulate burst times of all previous processes
        }
    }

    // Print table header
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    // Calculate turnaround time and accumulate totals for averages
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Turnaround time = Burst time + Waiting time
        avwt += wt[i];           // Accumulate waiting times
        avtat += tat[i];         // Accumulate turnaround times

        // Print process details
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    // Calculate averages
    avwt /= n;    // Average waiting time
    avtat /= n;   // Average turnaround time

    // Print averages
    printf("\nAverage Waiting Time: %f", avwt);
    printf("\nAverage Turnaround Time: %f", avtat);

    return 0;
}
