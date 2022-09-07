#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 256

void convert(long long baseNum, int numericBase, int numericOut) {
	// Sanity check
	if (numericBase > 10 || numericBase < 2 || numericOut > 10 || numericOut < 2) {
		printf("cannot convert!\n");
		return;
	}

	char baseString[MAX_STRING_SIZE];
	sprintf(baseString, "%lld", baseNum);
	unsigned long numLen = strlen(baseString);
	long long numBaseTen = 0;

	// Check for negative number. I know that we assume that the user enters a non-negative number, but whatever.
	int sign = 1;
	int firstChar = 0;
	if (baseString[0] == '-') {
		sign = -1;
		firstChar = 1;
	}

	// Convert to base 10:
	int curMult = 1;
	for (int i = numLen - 1; i >= firstChar; i--) {
		int curDigit = baseString[i] - '0';
		if (curDigit >= numericBase) {
			printf("cannot convert!\n");
			return;
		}
		numBaseTen += curDigit * curMult;
		curMult *= numericBase;
	}

	// Convert to output numeric base, reversed
	char outStringReversed[MAX_STRING_SIZE];
	int i = 0;
	while (numBaseTen > 0) {
		outStringReversed[i] = '0' + (numBaseTen % numericOut);
		numBaseTen /= numericOut;
		i++;
	}
	outStringReversed[i] = '\0';

	// Reverse the string
	char outString[MAX_STRING_SIZE];
	if (sign == -1) {
		outString[0] = '-';
	}
	int outStrLen = i;
	for (int i = 0; i < outStrLen; i++) {
		outString[i + firstChar] = outStringReversed[outStrLen - 1 - i];
	}
	outString[outStrLen + firstChar] = '\0';

	printf("%s\n", outString);
}

int main() {
	long long baseNum;
	int numericBase;
	int numericOut;
	scanf("%lld%d%d", &baseNum, &numericBase, &numericOut);
	convert(baseNum, numericBase, numericOut);
}
