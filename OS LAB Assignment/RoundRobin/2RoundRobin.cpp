// # C++ Program
/*
#include <iostream>
using namespace std;
struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnaroundTime;
  int waitingTime;
};
void calculateTimes(Process processes[], int n, int quantum) {
  int remainingTime[n];
  for (int i = 0; i < n; i++) {
    remainingTime[i] = processes[i].burstTime;
  }
  int currentTime = 0;
  bool allDone = false;
  while (!allDone) {
    allDone = true;
    for (int i = 0; i < n; i++) {
      if (remainingTime[i] > 0) {
        allDone = false;
        if (remainingTime[i] > quantum) {
          currentTime = currentTime + quantum;
          remainingTime[i] = remainingTime[i] - quantum;
        } else {
          currentTime = currentTime + remainingTime[i];
          processes[i].completionTime = currentTime;
          remainingTime[i] = 0;
        }
      }
    }
  }
}
void calculateTurnaroundTime(Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].turnaroundTime =
        processes[i].completionTime - processes[i].arrivalTime;
}

void claculateWaitingTime(Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].waitingTime =
        processes[i].turnaroundTime - processes[i].burstTime;
}

void printTable(Process processes[], int n) {
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
  cout << "| Process | Arrival Time | Burst Time | Completion Time | "
          "Turnaround Time | Waiting Time |\n";
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
  for (int i = 0; i < n; i++) {
    cout << "|    " << processes[i].id << "    |      "
         << processes[i].arrivalTime << "      |     " << processes[i].burstTime
         << "     |        " << processes[i].completionTime
         << "        |        " << processes[i].turnaroundTime
         << "         |      " << processes[i].waitingTime << "      |\n";
  }
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
}
int main() {
  int n, quantum;
  cout << "Enter The Number of Process = ";
  cin >> n;
  cout << "Enter The Time Quantum = ";
  cin >> quantum;

  Process processes[n];
  cout << "Enter process details:\n";
  for (int i = 0; i < n; i++) {
    cout << "Process " << i + 1 << ":\n";
    processes[i].id = i + 1;
    cout << "   Arrival Time: ";
    cin >> processes[i].arrivalTime;
    cout << "   Burst Time: ";
    cin >> processes[i].burstTime;
  }

  calculateTimes(processes, n, quantum);
  calculateTurnaroundTime(processes, n);
  claculateWaitingTime(processes, n);

  cout << "\nRound Robin Scheduling Results:\n";
  printTable(processes, n);

  return 0;
}
*/

// C program 

#include <stdio.h>

typedef struct {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnaroundTime;
  int waitingTime;
} Process;

void calculateTimes(Process processes[], int n, int quantum) {
  int remainingTime[n];
  for (int i = 0; i < n; i++) {
    remainingTime[i] = processes[i].burstTime;
  }
  int currentTime = 0;
  bool allDone = false;
  while (!allDone) {
    allDone = true;
    for (int i = 0; i < n; i++) {
      if (remainingTime[i] > 0) {
        allDone = false;
        if (remainingTime[i] > quantum) {
          currentTime += quantum;
          remainingTime[i] -= quantum;
        } else {
          currentTime += remainingTime[i];
          processes[i].completionTime = currentTime;
          remainingTime[i] = 0;
        }
      }
    }
  }
}

void calculateTurnaroundTime(Process processes[], int n) {
  for (int i = 0; i < n; i++) {
    processes[i].turnaroundTime =
        processes[i].completionTime - processes[i].arrivalTime;
  }
}

void claculateWaitingTime(Process processes[], int n) {
  for (int i = 0; i < n; i++) {
    processes[i].waitingTime =
        processes[i].turnaroundTime - processes[i].burstTime;
  }
}

void printTable(Process processes[], int n) {
  printf("--------------------------------------------------------------------"
         "----------------------\n");
  printf("| Process | Arrival Time | Burst Time | Completion Time | "
         "Turnaround Time | Waiting Time |\n");
  printf("--------------------------------------------------------------------"
         "----------------------\n");
  for (int i = 0; i < n; i++) {
    printf("|    %d    |      %d      |     %d     |        %d        |        %d"
           "         |      %d      |\n",
           processes[i].id, processes[i].arrivalTime, processes[i].burstTime,
           processes[i].completionTime, processes[i].turnaroundTime,
           processes[i].waitingTime);
  }
  printf("--------------------------------------------------------------------"
         "----------------------\n");
}

int main() {
  int n, quantum;
  printf("Enter The Number of Process = ");
  scanf("%d", &n);
  printf("Enter The Time Quantum = ");
  scanf("%d", &quantum);

  Process processes[n];
  printf("Enter process details:\n");
  for (int i = 0; i < n; i++) {
    printf("Process %d:\n", i + 1);
    processes[i].id = i + 1;
    printf("   Arrival Time: ");
    scanf("%d", &processes[i].arrivalTime);
    printf("   Burst Time: ");
    scanf("%d", &processes[i].burstTime);
  }

  calculateTimes(processes, n, quantum);
  calculateTurnaroundTime(processes, n);
  claculateWaitingTime(processes, n);

  printf("\nRound Robin Scheduling Results:\n");
  printTable(processes, n);

  return 0;
}
/*
Enter The Number of Process = 4
Enter The Time Quantum = 2
Enter process details:
Process 1:
   Arrival Time: 0
   Burst Time: 4
Process 2:
   Arrival Time: 1
   Burst Time: 3
Process 3:
   Arrival Time: 2
   Burst Time: 5
Process 4:
   Arrival Time: 3
   Burst Time: 2

Round Robin Scheduling Results:
------------------------------------------------------------------------------------------
| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
------------------------------------------------------------------------------------------
|    1    |      0      |     4     |        10        |        10         |      6      |
|    2    |      1      |     3     |        11        |        10         |      7      |
|    3    |      2      |     5     |        14        |        12         |      7      |
|    4    |      3      |     2     |        8         |        5          |      3      |
------------------------------------------------------------------------------------------
*/