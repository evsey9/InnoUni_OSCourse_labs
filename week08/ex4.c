#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
	int *ptrs[10];
	for (int i = 0; i < 10; i++) {
		ptrs[i] = malloc(10 * 1024 * 1024);
		memset(ptrs[i], 0, 10 * 1024 * 1024);
		struct rusage ourUsage;
		getrusage(RUSAGE_SELF, &ourUsage);
		printf("Memory usage: %ldKB\n", ourUsage.ru_maxrss);
		sleep(1);
	}
	for (int i = 0; i < 10; i++) {
	 	free(ptrs[i]);
	}
	// While running the program, the memory usage output by getrusage(), gotten through the maximus resident set size field, increased roughly by 10MB each iteration.
	// This correlates with the fact that we allocate and fill 10MB of data each loop iteration, 10 times, reaching a max of 100MB used.
	return(0);
}