#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	int *ptrs[10];
	for (int i = 0; i < 10; i++) {
		ptrs[i] = malloc(10 * 1024 * 1024);
		memset(ptrs[i], 0, 10 * 1024 * 1024);
		sleep(1);
	}
	for (int i = 0; i < 10; i++) {
	 	free(ptrs[i]);
	}
	// While running the program, the si frequently rised to 12-16, indicating that some memory was being swapped to disk.
	// Alongside that, top showed that as the program ran, free memory became smaller.
	return(0);
}