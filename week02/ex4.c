#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING_SIZE 256

int count(char string[], char countedChar) {
	unsigned long chars = strlen(string);
	int ans = 0;
	for (int i = 0; i < chars; i++) {
		if (tolower(string[i]) == tolower(countedChar)) {
			ans++;
		}
	}
	return ans;
}

void countAll(char string[]) {
	unsigned long chars = strlen(string);
	if (string[chars - 1] == '\n')
		chars--;
	for (int i = 0; i < chars; i++) {
		printf("%c:%d", tolower(string[i]), count(string, string[i]));
		if (chars - i > 1) {
			printf(", ");
		}
	}
	printf("\n");
}

int main() {
	char string[MAX_STRING_SIZE + 1];
	fgets(string, MAX_STRING_SIZE + 1, stdin);
	countAll(string);
}
