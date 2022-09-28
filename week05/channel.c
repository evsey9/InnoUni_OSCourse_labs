#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int fd[2];
	pipe(fd);
	pid_t pidSub = fork();
	if (pidSub != 0) {
		char input_str[1024];
		close(fd[0]);
		printf("Input message to send through pipe: ");
		fgets(input_str, 1024, stdin);
		write(fd[1], input_str, strlen(input_str) + 1);
		close(fd[1]);
	}
	else {
		char concat_str[1024];
		read(fd[0], concat_str, 1024);
		printf("Received message: %s", concat_str);
		close(fd[0]);
	}
	return EXIT_SUCCESS;
}