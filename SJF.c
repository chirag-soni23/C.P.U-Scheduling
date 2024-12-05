#include<stdio.h>
// sort process based on brust time
void sortProcess(int n, int process[], int brustTime[]){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0; j < n - i - 1;j++){
            // swap brust time
            if(brustTime[j]>brustTime[j+1]){
                int temp = brustTime[j];
                brustTime[j] = brustTime[j+1];
                brustTime[j+1] = temp;

                // swap process IDs
                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }
}
// calculate waiting time
void calculateWaitingTime(int n, int i, int brustTime[], int waitingTime[]){
    for(int i = 1;i < n;i++){
        waitingTime[i] = brustTime[i-1] + waitingTime[i-1];
    }
}

// calculate turn around time
void calculateTurnAroundTime(int n, int i, int brustTime[], int waitingTime[], int turnAroundTime[]){
    for(int i = 0; i < n;i++){
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

    // calculate average
   printf("Average of waiting time is: %.2f\n",(float)totalWaitingTime/n);
    printf("Average of turn around time is: %.2f\n",(float)totalTurnAroundTime/n);
}

// main function
int main(){
    int n,i;
    int process[20],brustTime[20],waitingTime[20],turnAroundTime[20];

    // enter a number a process
    printf("Enter a number of Process: ");
    scanf("%d",&n);

    // enter a brust time for each process
    for(i = 0;i < n;i++){
        process[n] = i+1;
        printf("Process %d: ",i+1);
        scanf("%d",&brustTime[i]);
    }

    // sort process
    sortProcess(n,process,brustTime);

    // initialize waiting time is 0
    waitingTime[0] = 0;

    // declare function
    calculateWaitingTime(n,i,brustTime,waitingTime);
    calculateTurnAroundTime(n,i,brustTime,waitingTime,turnAroundTime);
    displayResult(n,i,brustTime,waitingTime,turnAroundTime);
    return 0;
}