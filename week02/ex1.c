#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int int_var = INT_MAX;
	unsigned short un_s_int = USHRT_MAX;
	signed long s_l_int = LONG_MAX;
	float float_var = FLT_MAX;
	double double_var = DBL_MAX;
	printf("INT_MAX: %d sizeof(INT_MAX): %lu\n", int_var, sizeof(int_var));
	printf("USHRT_MAX: %d sizeof(USHRT_MAX): %lu\n", un_s_int, sizeof(un_s_int));
	printf("LONG_MAX: %ld sizeof(LONG_MAX): %lu\n", s_l_int, sizeof(s_l_int));
	printf("FLT_MAX: %f sizeof(FLT_MAX): %lu\n", float_var, sizeof(float_var));  //float and double has same printf specifier
	printf("DBL_MAX: %f sizeof(DBL_MAX): %lu\n", double_var, sizeof(double_var));

}
