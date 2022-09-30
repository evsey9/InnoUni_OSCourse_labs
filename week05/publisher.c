#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	char* myFifo = "/tmp/ex2";
	mkfifo(myFifo, 0666);
	int fd;
	char message[1024];
	int subscriberCount;
	if (argc < 2) {
		return EXIT_FAILURE;
	}
	sscanf(argv[1], "%d", &subscriberCount);
	while (1) {
		printf("Input message to send to %d subscribers: ", subscriberCount);
		fgets(message, 1024, stdin);
		for (int i = 0; i < subscriberCount; i++) {
			fd = open(myFifo, O_WRONLY);
			write(fd, message, 1024);
			close(fd);
			usleep(5 * 100 * 1000);  // sleep half a second for every subscriber
		}
		printf("Sent message.\n");
	}
	return EXIT_SUCCESS;
}