/*
Game description:
This game is a text-based simulation of the daily:
   - White-collar worker
   - Data entry monkey
   - Spreadsheet-making employee

 */

#include <stdio.h>

#include "../tools.h"

void mainWorkplaceSimLoop(char *name);

void workplaceSim(char *name){
	char cont;
	puts("Welcome to Workplace Simulator 2015!");
	cont = inputBinary(1);
	lineBreak();
	while(cont=='y'||cont=='Y'){
		mainWorkplaceSimLoop(name);
		lineBreak();
		cont = inputBinary(1);
	}
}

void mainWorkplaceSimLoop(char *name){
	char choice;
	printf("Welcome to your first day, %s! What do you want to do?", name);
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
