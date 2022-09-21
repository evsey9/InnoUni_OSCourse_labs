#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
	pid_t pid = fork();
	if (pid != 0) {
		fork();
	}
	printf("My pid: %d Parent id: %d\n", getpid(), getppid());
	printf("Execution time: %ld\n", clock());
	return EXIT_SUCCESS;
}