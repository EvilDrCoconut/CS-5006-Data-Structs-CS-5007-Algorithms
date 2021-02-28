// Modify this file for your assignment

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include "guessingGame.h"
#define clear() printf("\033[H\033[J")
#define MAX 80
#define MAXCMD 16

void init_shell(){
	clear();
	printf("\n\n------------------------------------------");
	char* username = getenv("USER");
	printf("\n\nWelcome to R@ND0M @%s\n", username);
	printf("As written by Evil Dr Coconut!\n\n");
	printf("Enjoy this wierd matrix...\n");
	printf("-------------------------------------\n");
	sleep(2);
	clear();

}

int userInp(char* str){
	char buffer[MAX];
	if (fgets(buffer, MAX, stdin) == NULL || strcmp(buffer, "\n") == 0){
		return 1;
	}
	if(strlen(buffer) != 0) {
		strcpy(str, buffer);
		return 0;
	} else{
		return 1;
	}

}

void cd(char** arg){
	if(chdir(arg[1]) < 0){
		printf("Directory does not exist: %s\n", arg[1]);
	} else{
		chdir(arg[1]);
	}
}

void helpMenu(){
	printf("-------------R@ND0M Help Menu----------------\n");
	printf("Current commands include:\n");
	printf("cd\n");
	printf("ls\n");
	printf("guess\n");
	printf("exit\n");
	printf("All general commands used in Linux Shell\n");
	return;
}


void doCMD(char** cmd){

	pid_t pid = fork();

	if(pid == -1){
		printf("Fork failed, check code\n");
		return;
	} else if(pid == 0){
		if(execvp(cmd[0], cmd) < 0){
			printf("Command not found, did you mean something else?\n");
		}
		exit(0);
	} else{
		wait(NULL);
		return;
	}

}

void dopipedCMD(char** cmd, char** pipedcmd){
	int pipeHelper[2];
	pid_t pid1;
	pid_t pid2;

	if(pipe(pipeHelper) < 0){
		printf("Pipe can't intialize\n");
		return;
	}
	pid1 = fork();
	if(pid1 < 0){
		printf("Fork failed\n");
		return;
	}

	if(pid1 == 0){
		close(pipeHelper[0]);
		dup2(pipeHelper[1], STDOUT_FILENO);
		close(pipeHelper[1]);

		if(execvp(cmd[0], cmd) < 0){
			printf("Could not find first command, did you mean something else?\n");
			return;
		}
	} else{

		pid2 = fork();

		if(pid2 < 0){
			printf("Forking failed\n");
			return;
		}

		if(pid2 == 0){
			close(pipeHelper[1]);
			dup2(pipeHelper[0], STDIN_FILENO);
			close(pipeHelper[0]);

			if(execvp(pipedcmd[0], pipedcmd) < 0){
				printf("Could not find second command, did you mean something else?\n");
				return;
			}
		} else{
			close(pipeHelper[1]);
			wait(NULL);	
			wait(NULL);
			
		}
	}
}


int randomCMDs(char** command){
	if(strstr(command[0], "help")){
		helpMenu();
		return 1;
	} else if(strstr(command[0], "cd")){
		cd(command);
		return 1;
	} else if(strstr(command[0], "guess")){
 		guessingGame();
		return 1;
	} else if(strstr(command[0], "exit")){
		printf("Thanks for using R@ND0M! Goodbye!\n");
		exit(0);
	} else {
		return 0;
	}
	return 0;		
}

int cmdTaker(char* cmd, char** pipedcmds){
	int i;
	for(i = 0; i < 2; i++){
		pipedcmds[i] = strsep(&cmd, "|");
		if(pipedcmds[i] == NULL){
			break;
		}
	}
	if(pipedcmds[1] == NULL){
		return 0;
	} else{
		return 1;
	}


}

void cmdBreaker(char* str, char** cmds){
	int i;
	for(i = 0; i < MAX; i++){
		cmds[i] = strsep(&str, " ");

		if(cmds[i] == NULL){
			break;
		} else if(strlen(cmds[i]) == 0){
			i --;
		}
		char* helper = strtok(cmds[i], "\n");
		cmds[i] = helper;
	}
}

int cmdTearer(char* str, char** cmds, char** pipedcmds){
	char* cmdspipe[2];
	int pipeCheck = 0;
	pipeCheck = cmdTaker(str, cmdspipe);

	if(pipeCheck){
		cmdBreaker(cmdspipe[0], cmds);
		cmdBreaker(cmdspipe[1], pipedcmds);
	} else {
		cmdBreaker(str, cmds);
	}

	if(randomCMDs(cmds)){
		return 0;
	} else{
		return 1 + pipeCheck;
	}

}

void sigint_handler(int sig){
	write(1, "Terminating through signal terminatorator\n", 35);
	exit(0);
}


int main(){

	signal(SIGINT, sigint_handler);

	char input[MAX]; char* cmds[MAXCMD]; char* pipedcmds[MAXCMD];
	int argFlag = 0;

	init_shell();
	printf("Can only terminate by Ctrl+C\n");

	while(1){
		printf("R@ND0M mini-shell>>> ");
		if(userInp(input)){
			continue;
		}
		argFlag = cmdTearer(input, cmds, pipedcmds);

		if(argFlag == 1){
			doCMD(cmds);
		} else if(argFlag == 2){
			dopipedCMD(cmds, pipedcmds);
		}


	}

  return 0;
}
