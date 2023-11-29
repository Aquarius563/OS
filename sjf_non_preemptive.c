#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, i, j, p[20], bt[20], wt[20], tat[20], total = 0, min, pos;
    float avg_wt, avg_tat;
    bool flag[20] = { false };

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time for each process:\n");

    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    // Sorting burst time in ascending order using selection sort
    for (i = 0; i < n - 1; i++) {
        min = bt[i];
        pos = i;

        for (j = i + 1; j < n; j++) {
            if (bt[j] < min) {
                min = bt[j];
                pos = j;
            }
        }

        // Swapping positions of process IDs and burst times
        int temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Calculating waiting time and turnaround time for each process
    for (i = 0; i < n; i++) {
        wt[i] = total;
        total += bt[i];
        tat[i] = total;
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Calculating average waiting time and turnaround time
    avg_wt /= n;
    avg_tat /= n;

    // Printing Gantt chart
    printf("\nGantt Chart:\n");

    for (i = 1; i < n; i++) {
        if (bt[i - 1] != bt[i] || flag[i]) {
            printf("Process %2d ->\t", p[i - 1]);
        }
        flag[i - 1] = true;
    }
    printf("Process %2d", p[n - 1]);
    printf("\n");

    // Printing table of process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    // Printing average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);

    return 0;
}
