// Now modify your program to swap two long's.

#include <stdio.h>

int main(){

	long a = 12;
	long b = 102;

	printf("Long a is: %ld, Long b is: %ld \n", a, b);
	printf("Swapping a and b \n");
	long c = a;
	a = b;
	b = c;

	printf("Long a is now: %ld, Long b is now: %ld \n", a, b);

	return 0;

}


