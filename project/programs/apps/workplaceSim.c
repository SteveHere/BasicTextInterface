/*
Game description:
This game is a text-based simulation of the daily:
   - White-collar worker
   - Data entry monkey
   - Spreadsheet-making employee

 */

#include <stdio.h>
#include "../tools.h"

void mainWorkplaceSimLoop(char *username);

void workplaceSim(char *username){
	int cont;
	puts("Welcome to Workplace Simulator 2015!");
	cont = inputYOrN(0);
	lineBreak();
	while( cont ){
		mainWorkplaceSimLoop(username);
		lineBreak();
		cont = inputYOrN(0);
	}
}

void mainWorkplaceSimLoop(char *username){
	char choice;
	printf("Welcome to your first day, %s! What do you want to do?", username);
	choice = charInput();
	//remove this section once game is complete
	puts("Game is currently being built. Please come back later.");
	//end section
	switch(choice){
	case '0': break;
	case 'e': break;
	case 'h': break;
	}
}
