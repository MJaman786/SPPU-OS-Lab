#include <stdio.h>
#include <conio.h>

#define MAX 30

int n, temp, Process_Numbers[MAX], Burst_Time[MAX], Turn_Around_Time[MAX], Waiting_Time[MAX];
float Average_Waiting_Time = 0, Average_Turn_Around_Time = 0;

void calculation() {

  // Applying Bubble sort [For sorting the processes]
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (Burst_Time[j] > Burst_Time[j + 1]) {
        temp = Burst_Time[j];
        Burst_Time[j] = Burst_Time[j + 1];
        Burst_Time[j + 1] = temp;

        temp = Process_Numbers[j];
        Process_Numbers[j] = Process_Numbers[j + 1];
        Process_Numbers[j + 1] = temp;
      }
    }
  }

  // Calculating waiting time and turnaround time
  for (int i = 0; i < n; i++) {
    Waiting_Time[i] = 0;
    Turn_Around_Time[i] = 0;
    for (int j = 0; j < i; j++) {
      Waiting_Time[i] += Burst_Time[j];
    }
    Turn_Around_Time[i] = Waiting_Time[i] + Burst_Time[i];
  }

  // Calculating average waiting time and turnaround time
  for (int i = 0; i < n; i++) {
    Average_Waiting_Time += Waiting_Time[i];
    Average_Turn_Around_Time += Turn_Around_Time[i];
  }
  Average_Waiting_Time = Average_Waiting_Time / n;
  Average_Turn_Around_Time = Average_Turn_Around_Time / n;
}

void printTable() {
  printf("Process\tBurst-Time\tWaiting-Time\tTurn-Around-Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t %d\t\t %d\t\t %d\n", Process_Numbers[i], Burst_Time[i], Waiting_Time[i], Turn_Around_Time[i]);
  }
  printf("Average-Turn-Around-Time : %f\n", Average_Turn_Around_Time);
  printf("Average-Waiting-Time : %f\n", Average_Waiting_Time);
}

int main() {
  printf("Enter number of processes : ");
  scanf("%d", &n);
  printf("Enter process number : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &Process_Numbers[i]);
  }
  printf("Enter burst times : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &Burst_Time[i]);
  }
  calculation();
  printTable();
  return 0;
}
/*
OUTPUT
Enter number of processes : 4
Enter process number : 1 2 3 4
Enter burst times : 5 2 6 4
Process Burst-Time      Waiting-Time    Turn-Around-Time
2        2               0               2
4        4               2               6
1        5               6               11
3        6               11              17
Average-Turn-Around-Time : 9.000000
Average-Waiting-Time : 4.750000
*/