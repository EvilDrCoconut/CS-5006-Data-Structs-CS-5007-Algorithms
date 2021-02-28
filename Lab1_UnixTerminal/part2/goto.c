// Write a C program using the goto command and a label.

#include <stdio.h>

int main(){

	int maybe = 1;

	if(maybe == 1){	
		goto no;
	}

	yes:
		printf("yes \n");
		return 1;
	no:
		printf("no \n");


	return 0;
}

