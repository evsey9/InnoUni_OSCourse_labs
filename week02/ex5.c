#include <stdio.h>
#define MAX_STRING_SIZE 256

long long tribonacci(int n) {
	long long ans = 0;
	if (n == 0)
		ans = 0;
	if (n >= 1 && n <= 2)
		ans = 1;
	if (n >= 3) {
		long long Tn1 = 1;
		long long Tn2 = 1;
		long long Tn3 = 0;
		for (int i = 3; i <= n; i++) {
			ans = Tn1 + Tn2 + Tn3;
			Tn3 = Tn2;
			Tn2 = Tn1;
			Tn1 = ans;
		}
	}
	return ans;
}

int main() {
	/* for (int i = 0; i < 50; i++) {
		printf("n: %d Tn: %lld\n", i, tribonacci(i));
	} */
	int arg1 = 4;
	int arg2 = 36;
	printf("%lld %lld\n", tribonacci(arg1), tribonacci(arg2));
}
