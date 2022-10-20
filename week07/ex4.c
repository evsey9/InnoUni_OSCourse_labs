#include <stdlib.h>
#include <stdio.h>
#include <time.h>    // time()
#include <string.h>

void* reallocCustom(void* ptr, size_t bytes) {
	// Our custom realloc function
	if (bytes == 0) {
		free(ptr);
		return ptr;
	} else {
		void *newPtr = malloc(bytes);
		size_t sizeOrig = ptr != NULL ? sizeof(ptr) : 0;
		size_t initSize = bytes < sizeOrig ? bytes : sizeOrig;
		memcpy(newPtr, ptr, bytes);
		free(ptr);
		return newPtr;
	}
}


int main(){
	// Testing reallocCustom function on ex3
	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(sizeof(int) * n1);
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i] );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2 using our custom function
	a1 = reallocCustom(a1, sizeof(int) * n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	for (int i = n1; i < n2; i++) {
		a1[i] = 0;
	}
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
