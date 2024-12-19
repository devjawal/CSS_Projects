#include<stdio.h>
struct Process {
int arrivalTime;
int burstTime;
int processNumber;
int waitingTime;
int turnAroundTime;
int completionTime; // Added to store completion time
};
// Function to read process details
struct Process readProcess(int index) {
struct Process p;
p.processNumber = index;
printf("\nProcess No: %d\n", index);
printf("Enter the arrival time: ");
scanf("%d", &p.arrivalTime);
printf("Enter the burst time: ");
scanf("%d", &p.burstTime);
return p;
}
int main()
{
struct Process processes[10], temp;
int n;
float totalWaitingTime = 0, totalTurnAroundTime = 0;
// Input the number of processes
printf("Enter the number of processes: ");
scanf("%d", &n);
// Read process details
for (int i = 0; i < n; i++) {
processes[i] = readProcess(i);
}
// Sort processes by arrival time using bubble sort
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (processes[i].arrivalTime > processes[j].arrivalTime) {
temp = processes[i];
processes[i] = processes[j];
processes[j] = temp;
}
}
}
// Calculate completion times
int completionTime = processes[0].arrivalTime + processes[0].burstTime;
processes[0].completionTime = completionTime;
for (int i = 1; i < n; i++) {
if (completionTime < processes[i].arrivalTime) {
// If the CPU is idle, start the process at its arrival time
completionTime = processes[i].arrivalTime + processes[i].burstTime;
} else {
// Otherwise, start immediately after the previous process
completionTime += processes[i].burstTime;
}
processes[i].completionTime = completionTime;
}
// Calculate waiting time and turnaround time
for (int i = 0; i < n; i++) {
processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
totalWaitingTime += processes[i].waitingTime;
totalTurnAroundTime += processes[i].turnAroundTime;
}
// Calculate averages
float avgWaitingTime = totalWaitingTime / n;
float avgTurnAroundTime = totalTurnAroundTime / n;
// Display process details
printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletionTime\n");
for (int i = 0; i < n; i++) {
printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
processes[i].processNumber, processes[i].arrivalTime,
processes[i].burstTime, processes[i].waitingTime,
processes[i].turnAroundTime, processes[i].completionTime);
}
// Display Gantt chart
printf("\nGantt Chart:\n");
printf("0");
for (int i = 0; i < n; i++) {
printf("\t|\tP[%d]\t", processes[i].processNumber);
}
printf("\n");
printf("0");
for (int i = 0; i < n; i++) {
printf("\t%d", processes[i].completionTime);
}
printf("\n");
// Display averages
printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
printf("\nAverage Turnaround Time: %.2f\n", avgTurnAroundTime);
return 0;
}