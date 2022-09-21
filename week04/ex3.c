#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){
	int n;
	if (argc != 2) {
		printf("Wrong number of arguments supplied\n");
		return EXIT_FAILURE;
	}
	sscanf(argv[1], "%d", &n);
	for (int i = 0; i < n; i++) {
		fork();
		sleep(5);
	}
	printf("Program finished\n");
	return EXIT_SUCCESS;
}