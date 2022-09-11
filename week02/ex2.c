#include <stdio.h>
#define MAX_STRING_SIZE 256

int main() {
	char string[MAX_STRING_SIZE + 1];  // null terminator or newline
	char stringNew[MAX_STRING_SIZE + 1];
	int lastCharIndex = 0;
	char curChar;
	// Loop to read the string character-by-character
	while (1) {
		curChar = fgetc(stdin);
		string[lastCharIndex] = curChar;
		if (curChar == EOF || curChar == '.' || curChar == '\n')
			break;
		lastCharIndex++;
	}
	for (int i = 0; i < lastCharIndex; i++) {
		stringNew[i] = string[lastCharIndex - 1 - i];
	}
	stringNew[lastCharIndex] = '\0';
	printf("\"%s\"\n", stringNew);
}
