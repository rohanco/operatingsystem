#include <stdio.h>

int main()
{
    int processes[10], burst_time[10], arrival_time[10], completion_time[10], wait_time[10], tat[10], is_completed[10] = {0};
    int n, current_time = 0, completed = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
    }

    printf("Enter the burst time respectively: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the arrival time respectively: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }

    // SJF Scheduling Logic
    while (completed < n) {
        int idx = -1;
        int min_bt = 100000; // A large number to find the minimum burst time

        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && !is_completed[i] && burst_time[i] < min_bt) {
                min_bt = burst_time[i];
                idx = i;
            }
        }

        if (idx != -1) {
            current_time += burst_time[idx];
            completion_time[idx] = current_time;
            tat[idx] = completion_time[idx] - arrival_time[idx];
            wait_time[idx] = tat[idx] - burst_time[idx];
            is_completed[idx] = 1;
            completed++;
        } else {
            current_time++;
        }
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], arrival_time[i], burst_time[i], completion_time[i], tat[i], wait_time[i]);
    }

    return 0;
}
5