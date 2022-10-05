#include <stdio.h>
#include <stdlib.h>

struct Process{
	int index;
	int arrivalTime;
	int burstTime;
	int completed;
	int active;
	int timeRemaining;
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
		if (p1->index < p2->index) {
			return -1;
		} else if (p1->index == p2->index) {
			return 0;
		} else if (p1->index > p2->index) {
			return 1;
		}
	} else if (p1->arrivalTime > p2->arrivalTime) {
		return 1;
	}

}

void enqueue(struct Process* processPointer, struct ProcessQueueMember** first, struct ProcessQueueMember** last) {
	// Add a member to the round robin queue
	struct ProcessQueueMember* curMember = malloc(sizeof(struct ProcessQueueMember));
	curMember->thisProcess = processPointer;
	if ((*last) != NULL) {
		(*last)->next = curMember;
	} else {
		*first = curMember;
	}
	*last = curMember;

}

int main(){
	int n;
	int quantumLength;
	printf("Input number of processes: ");
	scanf("%d", &n);
	printf("Input quantum length: ");
	scanf("%d", &quantumLength);
	// Add all processes into array
	struct Process processes[n];
	printf("Input arrival times: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &processes[i].arrivalTime);
		processes[i].index = i;
		processes[i].completed = 0;
		processes[i].active = 0;
	}
	printf("Input burst times: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &processes[i].burstTime);
		processes[i].timeRemaining = processes[i].burstTime;
	}
	// Sort process array by arrival time
	qsort(processes, n, sizeof(struct Process), compareProcessTimes);
	// Calculate process metrics (FIFO)
	struct ProcessQueueMember* first = NULL;
	struct ProcessQueueMember* last = NULL;
	struct Metrics procMetrics[n];
	int curTime = 0;
	int quantumTimeRemaining = quantumLength;
	struct Process* curProcess = NULL;
	int completedProcesses = 0;
	// Initial check of processes to be queued up at time 0
	for (int i = 0; i < n; i++) {
		if (processes[i].completed == 1 || processes[i].active == 1 || processes[i].arrivalTime != curTime)
			continue;
		if (processes[i].arrivalTime > curTime)
			break;

		enqueue(&processes[i], &first, &last);
	}
	while (completedProcesses < n) {
		// Check if there is no currently active process and that the queue is not empty to switch active process
		if (curProcess == NULL && first != NULL) {
			struct ProcessQueueMember* curMem = first;
			if (first != last) {
				first = curMem->next;
			} else {
				first = NULL;
				last = NULL;
			}
			curProcess = curMem->thisProcess;
			free(curMem);
		}
		// if (curProcess != NULL)
		//	   printf("At curTime %d running process %d\n", curTime, curProcess->index);
		curTime += 1;
		// Check for any new processes to enqueue immediately after increasing the time counter
		for (int i = 0; i < n; i++) {
			if (processes[i].completed == 1 || processes[i].active == 1 || processes[i].arrivalTime != curTime)
				continue;
			if (processes[i].arrivalTime > curTime)
				break;

			enqueue(&processes[i], &first, &last);
		}
		// Process the active process, if one exists
		if (curProcess != NULL) {
			curProcess->timeRemaining--;
			quantumTimeRemaining--;
			if (curProcess->timeRemaining <= 0) {
				// Flag process as complete and no longer active
				curProcess->active = 0;
				curProcess->completed = 1;
				calculateMetrics(&procMetrics[curProcess->index], curProcess->arrivalTime, curProcess->burstTime,
								 curTime);
				completedProcesses++;
				curProcess = NULL;
				quantumTimeRemaining = quantumLength;
			} else if (quantumTimeRemaining == 0) {
				// If quantum time ran out, enqueue current process and make it no longer active
				enqueue(curProcess, &first, &last);
				curProcess->active = 0;
				curProcess = NULL;
				quantumTimeRemaining = quantumLength;
			}
		}

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