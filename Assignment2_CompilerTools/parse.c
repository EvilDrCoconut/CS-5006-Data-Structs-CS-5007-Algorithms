// Implement a working parser in this file that splits text into individual tokens.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* command[]){

	// command [args]* [ | command [args]* ]*

	char* commandLine = command[1];

	char* token = strtok(commandLine, " ");

	while(token != NULL){
		printf("%s \n", token);
		token = strtok(NULL, " ");
	}
	

	return 0;
}

