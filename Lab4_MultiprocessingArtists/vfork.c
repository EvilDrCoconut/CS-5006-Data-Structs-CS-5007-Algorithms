// Implement your part 1 solution here
// gcc vfork.c -o vfork


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int colors[64][64*3];

void paint(int workID){
	printf("Artisit %d is painting\n", workID);
	int i;
	for(i=0; i < 64*3; i++){
		colors[workID][i] = workID;
	}
}


int main(int argc, char** argv){

	//int* integers = malloc(sizeof(int)*8000);

	int numberOfArtists = 64;

	pid_t pid;
	int i;
	for(i=0; i < numberOfArtists; i++){
		pid = vfork();

		if(pid == 0){
			paint(i);
			exit(0);
		}
		printf("Child created: %d\n",pid);
	}

	pid_t wpid;
	int status = 0;
	while((wpid = wait(&status)) > 0){

	}

	printf("Masterpiece(vfork.ppm) is being assembled.\n");

	FILE *fp;
	fp = fopen("vfork.ppm","w+");
	fputs("P3\n",fp);
	fputs("64 64\n",fp);
	fputs("255\n",fp);
	for(i = 0; i<64; i++){
		int j;
		for(j=0; j < 64*3; j++){
			fprintf(fp,"%d",colors[i][j]);
			fputs(" ",fp);
		}
		fputs("\n",fp);
	}

	//free(integers);
	return 0;
}

