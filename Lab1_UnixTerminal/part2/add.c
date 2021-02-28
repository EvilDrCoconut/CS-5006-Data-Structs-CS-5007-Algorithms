// Write a C program that calls an add function(long add(long a, long b).

#include <stdio.h>

long add(long a, long b){
	return a + b;
	}

int main(){

	long a = 23;
	long b = 22;

	long c = add(a, b);

	printf("%ld plus %ld equals %ld \n", a, b, c);

	return 0;
}

