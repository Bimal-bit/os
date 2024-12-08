#include<stdio.h>
int main() {
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;

    // Input: Number of processes
    printf("Please enter the total number of processes: ");
    scanf("%d", &n);

    // Input: Burst times
    printf("Enter the Burst time for each process\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Initialize waiting time for the first process
    wt[0] = 0;

    // Calculate waiting times for all processes
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {  // Only sum burst times of previous processes
            wt[i] += bt[j];
        }
    }

    // Display table and calculate turnaround times
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];   // Turnaround time = Burst time + Waiting time
        avwt += wt[i];            // Accumulate total waiting time
        avtat += tat[i];          // Accumulate total turnaround time

        // Print results for each process
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate and print averages
    avwt /= n;   // Average Waiting Time
    avtat /= n;  // Average Turnaround Time

    printf("\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d", avtat);

    return 0;
}
