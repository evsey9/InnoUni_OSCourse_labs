#include <stdio.h>
#include <limits.h>
#include <float.h>
#define MAX_STRING_SIZE 256

int main() {
	char string[MAX_STRING_SIZE + 1];  // null terminator or newline
	fgets(string, MAX_STRING_SIZE + 1, stdin);
	char stringNew[MAX_STRING_SIZE + 1];
	int lastCharIndex = 0;
	for (lastCharIndex = 0; lastCharIndex < MAX_STRING_SIZE; lastCharIndex++) {
		if (string[lastCharIndex] == '.' || string[lastCharIndex] == '\n')  // Find the last character
			break;
	}
	for (int i = 0; i < lastCharIndex; i++) {
		stringNew[i] = string[lastCharIndex - 1 - i];
	}
	stringNew[lastCharIndex] = '\0';
	printf("\"%s\"\n", stringNew);
}
