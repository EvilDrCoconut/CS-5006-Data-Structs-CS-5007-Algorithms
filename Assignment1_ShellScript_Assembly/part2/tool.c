// Implement your cycle count tool here.

#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <string.h>


int addq = 0; int subq = 0; int mulq = 0; int divq = 0; int movq = 0; int leaq = 0; int pushq = 0; int popq = 0; int retq = 0;

int main(int argc, char* argv[]) {
	
	char c[250];
	FILE* file;
	
	if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Error! opening file");
	exit(1);
	}

	while(fgets(c, 250, file) != NULL){
		
		char* code1 = strtok(c, " ");
		char* code2 = strtok(code1, "\t");
		char* code = strtok(code2, "$");
		if(strcmp(code ,"addq") == 0){
			addq ++; 
		} else if(strcmp(code, "addb") == 0){
			addq ++; 
		} else if(strcmp(code, "addl") == 0){
			addq ++; 
		} else if(strcmp(code, "subq") == 0){
			subq ++; 
		} else if(strcmp(code, "mulq") == 0){
			mulq ++; 
		} else if(strcmp(code, "divq") == 0){
			divq ++; 
		} else if(strcmp(code, "movq") == 0){
			movq ++; 
		} else if(strcmp(code, "leaq") == 0){
			leaq ++; 
		} else if(strcmp(code, "pushq") == 0){
			pushq ++; 
		} else if(strcmp(code, "popq") == 0){
			popq ++; 
		} else if(strcmp(code, "retq") == 0){
			retq ++;
		}
	}
	double totalInstructions = addq + subq + mulq + divq + movq + leaq + pushq + popq + retq;
	double cycleCount = (addq * 1) + (subq * 1) + (mulq * 3) + (divq * 6) + (movq * 1) + (leaq * 1) + (pushq * 1) + (popq * 3) + (retq * 2);
	printf("Number of ADDQ commands: %d \n", addq);
	printf("Number of SUBQ commands: %d \n", subq);
	printf("Number of MULQ commands: %d \n", mulq);
	printf("Number of DIVQ commands: %d \n", divq);
	printf("Number of MOVQ commands: %d \n", movq);
	printf("Number of LEAQ commands: %d \n", leaq);
	printf("Number of PUSHQ commands: %d \n", pushq);
	printf("Number of POPQ commands: %d \n", popq);
	printf("Number of RETQ commands: %d \n", retq);
	printf("The total number of instructions used are: %0.2f \n", totalInstructions);
	printf("The total cycle count for this program is: %0.2f \n", cycleCount);
	return 0;
}
