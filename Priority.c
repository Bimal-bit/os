#include<stdio.h>

int main() {
    // Variable declarations
    int n, i, j, p[20], bt[20], pr[20], wt[20], tat[20], temp;
    float avtat = 0, avwt = 0;

    // Input: Number of processes
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    // Input: Burst times and priorities for each process
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter the priority for P[%d]: ", i + 1);
        scanf("%d", &pr[i]);
        p[i] = i + 1; // Assign process IDs
    }

    // Sort processes based on priority (higher priority first, descending order)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] < pr[j + 1]) { // Swap if the current process has lower priority
                // Swap priorities
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
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
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time");

    // Calculate turnaround time and accumulate totals for averages
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
        avwt += wt[i];          // Accumulate waiting times
        avtat += tat[i];        // Accumulate turnaround times

        // Print process details
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    // Calculate averages
    avwt /= n;    // Average waiting time
    avtat /= n;   // Average turnaround time

    // Print averages
    printf("\nAverage Waiting Time: %f", avwt);
    printf("\nAverage Turnaround Time: %f", avtat);

    return 0;
}
