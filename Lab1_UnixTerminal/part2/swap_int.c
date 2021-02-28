// Write a C program that swaps two integers(in the main body of code).

#include <stdio.h>

int main(){
	int a = 1;
	int b = 2;
	
	printf("Integer a is: %d, Integer b is: %d \n", a, b);

	printf("Swapping a and b \n");
	int c = a;
	a = b;
	b = c;

	printf("Integer a is now: %d, Integer b is now: %d \n", a, b);

	return 0;
}

