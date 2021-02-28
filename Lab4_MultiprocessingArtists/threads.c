// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int colors[64][64*3];

void *paint(void* vargp){

	int* ptr = (int*) vargp;
	pthread_mutex_lock(&mutex1);
	printf("Artist %d is painting.",ptr);
	int i;
	for(i=0; i<64*3; i++){
		colors[*ptr][i] = *ptr;
	}
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

int main(int argc, char** argv){

	pthread_t tids[64];
	printf("check1\n");
	int i;
	for(i=0; i<64; i++){
		int* helper = &i;
		pthread_create(&tids[i], NULL, paint, (void*)helper);
	}
//	printf("check2\n");

	for(i=0; i<64; i++){
		pthread_join(tids[i], NULL);
	}


	printf("New Masterpiece(thread.ppm) is being assembled.\n");

	FILE *fp;
	fp = fopen("threas.ppm","w+");
	fputs("P3\n",fp);
	fputs("64 64\n",fp);
	fputs("255\n",fp);
	for(i=0; i < 64; i++){
		int j;
		for(j=0; j< 64*3; j++){
			fprintf(fp,"%d",colors[i][j]);
			fputs(" ",fp);
		}
		fputs("\n",fp);
	}	

	return 0;
}

