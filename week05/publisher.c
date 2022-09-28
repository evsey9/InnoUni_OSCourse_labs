#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	char* myFifo = "/tmp/ex2";
	mkfifo(myFifo, 0666);
	int fd;
	char message[1024];
	while (1) {
		printf("Input message to send to subscribers: ");
		fd = open(myFifo, O_WRONLY);
		fgets(message, 1024, stdin);
		write(fd, message, strlen(message) + 1);
		close(fd);
		printf("Sent message.\n");
	}
	return EXIT_SUCCESS;
}