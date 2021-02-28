// Add your program here!
 #include <stdio.h>
#include <stdlib.h>

int game[5];
int i = 0;

int main() {
    
    while(i < 5) {
        printf("Welcome to the Guessing game! Try and guess the correct number! \n");   
        int number = rand()  % 11;
        int n=0;
        int win = 0;
        while (win == 0) {
            int guess;
            printf("Please pick a number between 1 through 10: ");
            scanf("%d", &guess);
            getchar();
            game[i] ++;
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
        i ++;
    }
    int j;
    for (j = 0; j < 5; j++) {
        printf("Game %d took %d guesses \n", j, game[j]);
    }    
    return 0;
}
