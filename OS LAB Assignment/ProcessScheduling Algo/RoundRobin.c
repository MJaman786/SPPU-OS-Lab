#include<stdio.h>
#include<stdlib.h>

int main() {
    int num, quant_time;
    float avg_wt = 0, avg_tat = 0;
    int temp, sq = 0;
    int bt[10], rem_bt[10], wt[10], tat[10];

    printf("Enter number of processes = ");
    scanf("%d", &num);

    printf("\nEnter burst time of all processes = ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter the Time-Quantum = ");
    scanf("%d", &quant_time);

    while (1) {
        for (int i = 0; i < num; i++) {
            if (rem_bt[i] == 0) {
                continue;
            } else if (rem_bt[i] > quant_time) {
                rem_bt[i] -= quant_time;
                sq += quant_time;
            } else {
                sq += rem_bt[i];
                tat[i] = sq;
                rem_bt[i] = 0;
            }
        }

        if (num == 0) {
            break;
        }

        printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting time\n");
        for (int i = 0; i < num; i++) {
            wt[i] = tat[i] - bt[i];
            avg_tat += tat[i];
            avg_wt += wt[i];
            printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], tat[i], wt[i]);
        }

        avg_wt /= num;
        avg_tat /= num;
        printf("Average Waiting-Time = %f\n", avg_wt);
        printf("Average Turnaround-Time = %f\n", avg_tat);
    }

    return 0;
}
/*
Number of processes: 3
Burst time of processes: 10, 20, 30
Time quantum: 5

Process	Burst Time	Turnaround Time	Waiting time
1	10	15	5
2	20	30	10
3	30	45	15
Average Waiting-Time = 10.00
Average Turnaround-Time = 30.00

*/