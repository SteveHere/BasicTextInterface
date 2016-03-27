/*
Description:
listOptions(): 
- Presents user options in a text-based format
- Make sure to add yours
selection(char select):
- A switch case that runs a method, based on input from stdin
- Make sure to add your method here
 */

#include <stdio.h>
#include "apps/tools.h"
#include "apps/currentTime.h"
#include "apps/electricBill.h"
#include "apps/guessGame.h"
#include "apps/calendar.h"
#include "apps/workplaceSim.h"

void listOptions(void){
	puts(" ----------------------------------------------- ");
	puts("|List of Options                                |");
	puts("|-----------------------------------------------|");
	puts("|1 --- Current Time and Date                    |");
	puts("|2 --- Electric Bill Calculator                 |");
	puts("|3 --- The Guessing Game                        |");
	puts("|4 --- Calendar Generator                       |");
	puts("|5 --- Workplace Simulator 2015 (in progress)   |");
	puts("|6 --- List of Options                          |");
	puts("|0 --- Exit                                     |");
	puts(" -----------------------------------------------");
}

void selection(char select, char *name){
	switch(select){
	case '1': currentTime();  break;
	case '2': electricBill(); break;
	case '3': guessGame(); break;
	case '4': calendar(); break;
	case '5': workplaceSim(name); break;
	case '6': listOptions(); break;
	//case '7':
	//case '8':
	//case '9':
	case '0': break;
	default: puts("Invalid option entered. Try again."); break;
	}
}
