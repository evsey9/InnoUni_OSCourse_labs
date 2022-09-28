#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

struct Thread{
	int id;
	int i;
	char message[256];
};

void* printThread(void* thread) {
	struct Thread* convertedThread = (struct Thread*)thread;
	printf("Thread id: %u, thread message: %s\n", convertedThread->id, convertedThread->message);
}

int main(){
	struct Thread threads[1024];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		pthread_t curThread;
		struct Thread threadObj;
		threads[i] = threadObj;
		char message[256];
		sprintf(message, "Hello from thread %d", i);
		threadObj.i = i;
		strcpy(threadObj.message, message);
		pthread_create(&curThread, NULL, &printThread, &threadObj);
		threadObj.id = curThread;
		printf("Thread %d is created.\n", i);
		pthread_join(curThread, NULL);  // This is needed for strict order of printing
	}
	return EXIT_SUCCESS;
}