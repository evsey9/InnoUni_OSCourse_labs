#include <stdio.h>
#include <stdlib.h>

struct Process{
	int index;
	int arrivalTime;
	int burstTime;
	int completed;
};

struct ProcessQueueMember{
	struct ProcessQueueMember* next;
	struct Process* thisProcess;
};

struct Metrics{
	int processIndex;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
};

void calculateMetrics(struct Metrics* mPointer, int arrivalTime, int burstTime, int exitTime) {
	mPointer->completionTime = exitTime;
	mPointer->turnAroundTime = exitTime - arrivalTime;
	mPointer->waitingTime = mPointer->turnAroundTime - burstTime;
}

int compareProcessTimes(struct Process* p1, struct Process* p2) {
	if (p1->arrivalTime < p2->arrivalTime) {
		return -1;
	} else if (p1->arrivalTime == p2->arrivalTime) {
		if (p1->burstTime < p2->burstTime) {
			return -1;
		} else if (p1->burstTime == p2->burstTime) {
			if (p1->index < p2->index) {
				return -1;
			} else if (p1->index == p2->index) {
				return 0;
			} else if (p1->index > p2->index) {
				return 1;
			}
		} else if (p1->burstTime > p2->burstTime) {
			return 1;
		}
	} else if (p1->arrivalTime > p2->arrivalTime) {
		return 1;
	}

}

int main(){
	int n;
	printf("Input number of processes: ");
	scanf("%d", &n);
	// Add all processes into array
	struct Process processes[n];
	printf("Input arrival times: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &processes[i].arrivalTime);
		processes[i].index = i;
		processes[i].completed = 0;
	}
	printf("Input burst times: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &processes[i].burstTime);
	}
	// Sort process array by arrival time
	qsort(processes, n, sizeof(struct Process), compareProcessTimes);
	// Calculate process metrics (FIFO)
	struct Metrics procMetrics[n];
	int curTime = 0;
	int curProcessIndex = 0;
	int completedProcesses = 0;
	while (completedProcesses < n) {
		struct Process* curProcess = &processes[curProcessIndex];
		if (curTime < curProcess->arrivalTime) {
			curTime = curProcess->arrivalTime;
		}
		curTime += curProcess->burstTime;
		calculateMetrics(&procMetrics[curProcess->index], curProcess->arrivalTime, curProcess->burstTime, curTime);
		curProcess->completed = 1;
		completedProcesses++;
		int minProcessIndex = -1;
		for (int i = 0; i < n; i++) {
			if (processes[i].completed == 0 && (minProcessIndex == -1 || processes[i].burstTime < processes[minProcessIndex].burstTime && processes[i].arrivalTime <= curTime)) {
				minProcessIndex = i;
			}
		}
		curProcessIndex = minProcessIndex;
	}
	// Display process metrics
	double averageTurnAroundTime = 0;
	double averageWaitingTime = 0;
	for (int i = 0; i < n; i++) {
		struct Metrics* curMetrics = &procMetrics[i];
		averageTurnAroundTime += curMetrics->turnAroundTime;
		averageWaitingTime += curMetrics->waitingTime;
		printf("For process %d, Completion Time: %d, Turn Around Time: %d, Waiting Time: %d\n", i, curMetrics->completionTime, curMetrics->turnAroundTime, curMetrics->waitingTime);
	}
	averageWaitingTime /= n;
	averageTurnAroundTime /= n;
	printf("Average waiting time: %lf\nAverage turn around time: %lf\n", averageWaitingTime, averageTurnAroundTime);
	return EXIT_SUCCESS;
}