#include <stdio.h>

// sort processes 
void sortProcesses(int n, int process[], int burstTime[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap burst time
                int temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                // Swap process IDs
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;

                // Swap priorities
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }
}

// Calculate Waiting Time
void calculateWaitingTime(int n, int burstTime[], int waitingTime[]) {
    waitingTime[0] = 0; // First process's waiting time is always 0
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
}

// Calculate Turnaround Time
void calculateTurnAroundTime(int n, int burstTime[], int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

// Display Result
void displayResult(int n, int process[], int burstTime[], int waitingTime[], int turnAroundTime[], int priority[]) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], burstTime[i], priority[i], waitingTime[i], turnAroundTime[i]);
    }

    // Calculate averages
    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);
}

// Main function
int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], burstTime[n], waitingTime[n], turnAroundTime[n], priority[n];

    // Input burst time and priority for each process
    printf("Enter the burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    // Sort processes
    sortProcesses(n, process, burstTime, priority);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(n, burstTime, waitingTime);
    calculateTurnAroundTime(n, burstTime, waitingTime, turnAroundTime);

    // Display results
    displayResult(n, process, burstTime, waitingTime, turnAroundTime, priority);

    return 0;
}
