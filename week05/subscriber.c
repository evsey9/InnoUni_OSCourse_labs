#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	char* myFifo = "/tmp/ex2";
	mkfifo(myFifo, 0666);
	int fd;
	char message[1024];
	if (argc < 2) {
		return EXIT_FAILURE;
	}
	int subscriberCount;
	sscanf(argv[1], "%d", &subscriberCount);
	while (1) {
		fd = open(myFifo, O_RDONLY);
		int status = read(fd, message, 1024);
		close(fd);
		if (status > 0) {
			printf("Received message: %s", message);
			usleep(subscriberCount * 100 * 1000 * 5);  // sleep for half a second for every subscriber
		}
	}
	return EXIT_SUCCESS;
}