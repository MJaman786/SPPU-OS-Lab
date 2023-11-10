#include <stdio.h>
int num, temp, qt, count = 0, sq = 0, bt[10], rem_t[10], wt[10], tat[10];
float awt = 0, atat = 0;

void calculation() {
    while (1) {
        temp = qt;
        int i;  
        for (i = 0, count = 0; i < num; i++) {
            if (rem_t[i] == 0) {
                count++;
                continue;
            }
            if (rem_t[i] > qt) {
                rem_t[i] = rem_t[i] - qt;
            } 
            else 
                if (rem_t[i] >= 0) {
                    temp = rem_t[i];
                    rem_t[i] = 0;
                }
                sq = sq + temp;
                tat[i] = sq;
        }
        if (num == count) {
            break;
        }
    }
    for (int i = 0; i < num; i++) {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
    }
    awt = awt / num;
    atat = atat / num;
}

void table() {
    printf("Processes\tBurst-Time\tWaiting-Time\tTurnaround-Time\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time : %f\n", awt); 
    printf("Average turn around time : %f\n", atat); 
}

int main() {
    printf("Enter number of processes : ");
    scanf("%d", &num);

    printf("Enter burst times : ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &bt[i]);
        rem_t[i] = bt[i];
    }

    printf("Enter Quantum-Time : ");
    scanf("%d", &qt);

    calculation();
    table();

    return 0;
}

/*
OUTPUT
Enter number of processes : 4
Enter burst times : 5 3 1 4
Enter Quantum-Time : 2
Processes       Burst-Time      Waiting-Time    Turnaround-Time
1                5               7               12
2                3               6               9
3                1               4               5
4                4               7               11
Average waiting time : 6.000000
Average turn around time : 9.250000
*/