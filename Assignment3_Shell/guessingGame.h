// Guessing Game module for mini shell.
#include <stdio.h>
#include <stdlib.h>

int game;
int i = 0;

int guessingGame() {
    
        printf("Welcome to the Guessing game! Try and guess the correct number! \n");   
        int number = rand()  % 11;
        int n=0;
        int win = 0;
        while (win == 0) {
            int guess;
            printf("Please pick a number between 1 through 10 (enter 1234 to quit): ");
            scanf("%d", &guess);
	    if(guess == 1234){
		break;
	    }
            getchar();
            game ++;
            if (guess == number) {
                printf("Correct! You win! \n");
                win = 1;
            } else if (guess > number) {
                printf("Your guess is too high, try a lower number! \n");
            } else if (guess < number) {
                printf("Your guess is too low, try a higher number! \n");
            } else {
                printf("Development issue, check if else statement");
            }
    }
    printf("This round took %d guesses!\n", game);   
    return 0;
}
