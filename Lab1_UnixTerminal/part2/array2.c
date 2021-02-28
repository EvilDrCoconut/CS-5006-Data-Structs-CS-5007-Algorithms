// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.
#include <stdlib.h>

int main(){

	int* numbers = (int*)malloc(400 * sizeof(int));

	numbers[1] = 2;
	numbers[3] = 6;
	numbers[100] = 200;
	numbers[201] = 199;
	numbers[300] = 333;
	numbers[399] = 999;

	return 0;
}


