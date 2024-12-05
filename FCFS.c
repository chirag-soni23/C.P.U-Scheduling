#include<stdio.h>
// calculate waiting time
void calculateWaitingTime(int n, int i, int brustTime[], int waitingTime[]){
    for(int i = 1;i < n;i++){
    waitingTime[i] = brustTime[i-1] + waitingTime[i-1];
    }
}

// calculate turn around time
void calculateTurnAroundTime(int n, int i, int brustTime[], int waitingTime[], int turnAroundTime[]){
    for(int i = 0;i < n;i++){
        turnAroundTime[i] = brustTime[i] + waitingTime[i];
    }
}

// display result
void displayResult(int n, int i, int brustTime[], int waitingTime[], int turnAroundTime[]){
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    printf("\nProcess\tBrust Time\tWaiting Time\tAround Time\n");
    for(int i = 0;i < n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,brustTime[i],waitingTime[i],turnAroundTime[i],totalTurnAroundTime+=turnAroundTime[i],totalWaitingTime+=waitingTime[i]);
    }

    // calculate averge 
    printf("Average of total waiting time is: %.2f\n",(float)totalWaitingTime/n);
    printf("Average of total turn around time is: %.2f\n",(float)totalTurnAroundTime/n);
}

// main function
int main(){
    int n,i;
    int brustTime[20],waitingTime[20],turnAroundTime[20];

    // number of process
    printf("Enter a number of Process: ");
    scanf("%d",&n);

    // enter a brust time for each process
    printf("Enter a brust time for each Process: \n");
    for(i = 0;i < n;i++){
        printf("Process %d: ",i+1);
        scanf("%d",&brustTime[i]);
    }

    // initialize waiting time is zero
    waitingTime[0] = 0;

    // declare the functions
    calculateWaitingTime(n,i,brustTime,waitingTime);
    calculateTurnAroundTime(n,i,brustTime,waitingTime,turnAroundTime);
    displayResult(n,i,brustTime,waitingTime,turnAroundTime);

    return 0;
}