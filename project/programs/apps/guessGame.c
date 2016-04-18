/*
Game description: 
The generator generates a number based within
the limit given by the user. The user then has
to guess the number.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#include "../tools.h"

void guessGame(void){
	char buffer[7];
	unsigned short guess, rNumber, limit;
	int cont;
	srand(time(NULL));
	puts("The Guessing Game");
	lineBreak();
	cont = inputYOrN(0);
	while(cont){
		guess = 0; // reset guess to 0
		lineBreak();
		printf("Enter the maximum limit(1 to 65535): ");
		fgets(buffer,7,stdin);
		sscanf(buffer, "%hu", &limit);
		//generate random number
		rNumber = (rand() % limit) + 1;
		while(guess!=rNumber){
			printf("\nGuess the random number(1 to %d): ",limit);
			fgets(buffer,7,stdin);
			if(isdigit((int)buffer[0])){
				sscanf(buffer, "%hu", &guess);
				if(guess==rNumber){
					printf("Congratulations! You found the number!\n");}
				else{
					printf("Sorry, your guess was %s. Try again!\n", ((guess>rNumber)?"too high":"too low") );}
			}
			else{printf("Invalid input. Try again.\n");}
		}
		cont = inputYOrN(0);
	}
}
