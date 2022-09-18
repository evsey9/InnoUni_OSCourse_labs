#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
	int* result = malloc(sizeof(int));
	*result = *(int*)a + *(int*)b;
}

void* addDouble(const void* a, const void* b){
	double* result = malloc(sizeof(double));
	*result = *(double*)a + *(double*)b;
}

void* mulInt(const void* a, const void* b){
	int* result = malloc(sizeof(int));
	*result = *(int*)a * *(int*)b;
}

void* mulDouble(const void* a, const void* b){
	double* result = malloc(sizeof(double));
	*result = *(double*)a * *(double*)b;
}

void* meanInt(const void* a, const void* b){
	int* result = malloc(sizeof(int));
	*result = *(int*)a + *(int*)b;
}

void* meanDouble(const void* a, const void* b){
	double* result = malloc(sizeof(double));
	*result = *(double*)a + *(double*)b;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

	void* output;

	if (size==sizeof(int)){ // base is a pointer to an integer
		int* intOutput = malloc(sizeof(int));
		output = intOutput;
		int* basePointer = (int*)base;
		int* first_val = opr(initial_value, basePointer);
		*intOutput = *first_val;
		free(first_val);
		for (int i = 1; i < n; i++) {
			int *val = opr(intOutput, basePointer + i);
			*intOutput = *val;
			free(val);
		}
		if (opr == meanInt) {
			*intOutput /= n;
		}
	}else{ // base is a pointer to a double
		double* doubleOutput = malloc(sizeof(double));
		output = doubleOutput;
		double* basePointer = (double*)base;
		double* first_val = opr(initial_value, basePointer);
		*doubleOutput = *first_val;
		free(first_val);
		for (int i = 1; i < n; i++) {
			double *val = opr(doubleOutput, basePointer + i);
			*doubleOutput = *val;
			free(val);
		}
		if (opr == meanDouble) {
			*doubleOutput /= n;
		}
	}

	return output;
}




int main(){

	int* ints = malloc(sizeof(int)*5);
	double* doubles = malloc(sizeof(double)*5);
	printf("input five ints:\n");
	for (int i = 0; i < 5; i++) {
		scanf("%d", ints + i);
	}

	printf("input five doubles:\n");
	for (int i = 0; i < 5; i++) {
		scanf("%lf", doubles + i);
	}

	int* const zeroIntPointer = malloc(sizeof(int));
	*zeroIntPointer = 0;
	int* const oneIntPointer = malloc(sizeof(int));
	*oneIntPointer = 1;


	double* const zeroDoublePointer = malloc(sizeof(double));
	*zeroDoublePointer = 0;
	double* const oneDoublePointer = malloc(sizeof(double));
	*oneDoublePointer = 1;

	// Addition

	int* result1a;

	result1a = aggregate(ints, sizeof(int), 5, zeroIntPointer, addInt);

	printf("%d\n", *result1a);

	double* result2a;

	result2a = aggregate(doubles, sizeof(double), 5, zeroDoublePointer, addDouble);

	printf("%f\n", *result2a);


	// Multiplication

	int* result1m;

	result1m = aggregate(ints, sizeof(int), 5, oneIntPointer, mulInt);

	printf("%d\n", *result1m);

	double* result2m;

	result2m = aggregate(doubles, sizeof(double), 5, oneDoublePointer, mulDouble);

	printf("%f\n", *result2m);



	// Mean

	int* result1mean;

	result1mean = aggregate(ints, sizeof(int), 5, zeroIntPointer, meanInt);

	printf("%d\n", *result1mean);

	double* result2mean;

	result2mean = aggregate(doubles, sizeof(double), 5, zeroDoublePointer, meanDouble);

	printf("%f\n", *result2mean);


	// free the pointers
	free(result1a);
	free(result2a);
	free(result1m);
	free(result2m);
	free(result1mean);
	free(result2mean);
	free(oneIntPointer);
	free(zeroIntPointer);
	free(oneDoublePointer);
	free(zeroDoublePointer);

	return EXIT_SUCCESS;
}

