#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int count = 0;
	char buff[255];
	fgets(buff, 255, fp);
	char *end = buff;
	char *begin = buff;
	int referenceSequence[255];
	int pageFrames = 0;
	int agingNumber[255];
	scanf("%d", &pageFrames);
	while (*end) {
		int n = strtol(begin, &end, 10);
		referenceSequence[count] = n;
		count++;
		while (*end == ' ') {
			end++;
		}
		if (*end == '\n' || *end == '\0' || *end == EOF) {
			break;
		}
		begin = end;
	}

	return(0);
}