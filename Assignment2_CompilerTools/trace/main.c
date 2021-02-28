#include <stdio.h>
#include <unistd.h>

int countdown = 10;

void msg(){
	printf("Hello!\n");
	sleep(2);
}

void blastOff(){
	while(countdown > 0){
		printf("Countdown: %d \n", countdown);
		countdown --;
	}
	printf("BlastOff! \n");
}

void countUp(){
	int hardstop = 1;
	while(countdown != 10){
		if(hardstop == 1){
			countdown = countdown + 2;
			hardstop = 0;
		} else{
			countdown --;
			hardstop = 1;
		}
	}
	printf("Reversed Countdown \n");
}

int main(){

	int i;
	for(i= 0;i  < 10; ++i){
		msg();
		blastOff();
		countUp();
		sleep(2);
	}

	return 0;
}
