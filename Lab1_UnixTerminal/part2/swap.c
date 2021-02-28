// Write a C program that swaps two integers in a function

#include <stdio.h>

void swap(int* a, int* b){
		int c = *a;
		*a = *b;
		*b = c;
	}

int main(){
	
	int a = 4;
	int b = 5;

	printf("Integer a is: %d, Integer b is: %d \n", a, b);
	printf("Swapping a and b \n");
	
	swap(&a, &b);

	printf("Intger a is now: %d, Integer b is now %d \n", a, b);

	return 0;

}

