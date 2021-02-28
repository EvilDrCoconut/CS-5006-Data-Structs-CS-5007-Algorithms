// Take a look at some of the previous examples to create your own program!

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

	pid_t pid;
	pid_t pid2;
	pid = fork();
	int x = 2;
	int y = 3;
	int z = 4;

	char* myargv[16];
	myargv[0] = "/bin/ls";
	myargv[1] = "-F";
	myargv[2] = NULL;

	if(pid == 0){
		printf("Child is: %d\n", (x*y));
		pid2 = fork();
		if(pid2 == 0){
			printf("Child2 is: %d\n",(x*y*z));
			exit(0);
		}
		exit(0);
	} else{
		printf("Parent is: %d\n", (x*z));
		wait(NULL);
	}


	if(fork() == 0){
		execve(myargv[0], myargv, NULL);
		printf("Child no be here!!!\n");
		exit(0);
	} else{
		wait(NULL);
		printf("Printif lastif\n");
	}

	return 0;

}


