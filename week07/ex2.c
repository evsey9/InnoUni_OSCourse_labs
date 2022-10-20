#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* arr;
	printf("Enter array length: ");
	scanf("%d", &n);
	arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return EXIT_SUCCESS;
}