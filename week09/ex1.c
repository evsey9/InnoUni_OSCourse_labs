#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

union Bits {
	unsigned char num;

};

int main(int argc, char *argv[]) {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int count = 0;
	char buff[8192];
	fgets(buff, 8192, fp);
	char *end = buff;
	char *begin = buff;
	int referenceSequence[8192];
	int pageFrames = 0;
	unsigned char agingNumber[8192];  //8-bit clock
	if (argc < 2) {
		return EXIT_FAILURE;
	}
	sscanf(argv[1], "%d", &pageFrames);
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

	int pagesInMemoryNum = 0;
	int pagesInMemory[pageFrames];
	int hits = 0;
	int misses = 0;
	for (int i = 0; i < 8192; i++) {
		agingNumber[i] = 0;
	}
	for (int i = 0; i < count; i++) {
		int isPageInMemory = 0;  // 0 or 1
		int pageInMemoryIndex = -1;
		int curPage = referenceSequence[i];
		for (int j = 0; j < pagesInMemoryNum; j++) {
			if (pagesInMemory[j] == curPage) {
				isPageInMemory = 1;
				pageInMemoryIndex = j;
				break;
			}
		}
		if (!isPageInMemory) {
			misses++;
			if (pagesInMemoryNum < pageFrames) {
				pagesInMemory[pagesInMemoryNum] = curPage;
				pageInMemoryIndex = pagesInMemoryNum;
				pagesInMemoryNum++;
			} else {
				int minVal = 256;
				int minPageIndex = -1;
				for (int j = 0; j < pagesInMemoryNum; j++) {
					if (agingNumber[pagesInMemory[j]] < minVal) {
						minPageIndex = j;
						minVal = agingNumber[pagesInMemory[minPageIndex]];
					}
				}
				pagesInMemory[minPageIndex] = curPage;
				pageInMemoryIndex = minPageIndex;
			}
			isPageInMemory = 1;
		} else {
			hits++;
		}
		for (int j = 0; j < pagesInMemoryNum; j++) {
			agingNumber[pagesInMemory[j]] = agingNumber[pagesInMemory[j]] >> 1;
		}
		agingNumber[curPage] += 128;  // set leftmost bit to 1
	}
	printf("For %d page frames, %d hits, %d misses, hit/miss ratio: %lf\n", pageFrames, hits, misses, (double)hits / (double)misses);
	return(0);
}