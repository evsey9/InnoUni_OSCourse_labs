#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define VECTOR_SIZE 120

int main() {
	// Create and fill base vectors
	int u[VECTOR_SIZE];
	int v[VECTOR_SIZE];
	for (int i = 0; i < VECTOR_SIZE; i++) {
		u[i] = rand() % 100;
		v[i] = rand() % 100;
	}

	// Create the fork processes
	int n;
	scanf("%d", &n);
	pid_t pid;
	const int chunk_size = VECTOR_SIZE / n;
	fopen("temp.txt","w");  // Empty file first
	printf("Creating children...\n");
	int chunk_i = 0;
	for (int i = 0; i < n; i++) {
		pid = fork();
		if (pid == 0) {
			// Set the chunk index so that the fork knows which part of the vector to work on
			chunk_i = i;
			break;
		}
	}

	if (pid != 0) {
		// Aggregate results from the file
		while(wait(NULL) > 0) {};
		printf("All children exited!\n");
		FILE * pFile;
		pFile = fopen("temp.txt", "r");
		char line[256];
		long long ans = 0;
		if (pFile != NULL) {
			while (fscanf(pFile, "%s", line) != EOF) {
				if (line[0] == '\n')
					break;
				char **endptr;
				ans += strtol(line, endptr, 10);
			}
			fclose(pFile);
		}
		printf("Dot product: %lld\n", ans);
	} else {
		// Calculate dot product for a chunk of the vectors and write to file
		int chunk_ans = 0;
		for (int i = chunk_i * chunk_size; i < (chunk_i + 1) * chunk_size; i++) {
			chunk_ans += u[i] * v[i];
		}
		printf("Hello from child process %d! Chunk index: %d, chunk size: %d Chunk calculation result: %d\n", getpid(), chunk_i, chunk_size, chunk_ans);
		FILE * pFile;
		pFile = fopen("temp.txt","a");
		if (pFile != NULL) {
			fprintf(pFile, "%d\n", chunk_ans);
			fclose(pFile);
		}
		exit(0);
	}
	return EXIT_SUCCESS;
}