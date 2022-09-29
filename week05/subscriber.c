#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	char* myFifo = "/tmp/ex2";
	mkfifo(myFifo, 0666);
	int fd;
	char message[1024];
	while (1) {
		fd = open(myFifo, O_RDONLY);
		read(fd, message, 1024);
		close(fd);
		printf("Received message: %s", message);
		sleep(1);
	}
	return EXIT_SUCCESS;
}