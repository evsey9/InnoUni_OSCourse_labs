#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // We need this to get the current year

int foo(int age){
	int result;
	// Get the current year to calculate birth year
	time_t t = time(NULL);
	struct tm cur_time = *localtime(&t);
	int cur_year = cur_time.tm_year + 1900;
	result = cur_year - age;
	return result;
}

int main(){
	const int x = 10;
	const int* q = &x;
	const int* const p = malloc(5*sizeof(x));
	// Printing the addresses and filling with x
	for (int i = 0; i < 5; i++) {
		*(int*)(p + i) = x;
		printf("%p\n", p + i);
	}
	// Storing the ages
	for (int i = 0; i < 5; i++) {
		scanf("%d", (int*)(p + i));
	}
	// Store the birth years in the same cells
	for (int i = 0; i < 5; i++) {
		*(int*)(p + i) = foo(*(int*)(p + i));
		printf("%d\n", *(int*)(p + i));  // optionally, print the birth year
	}
	free(p);
	return EXIT_SUCCESS;
}