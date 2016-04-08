/*
Description:
listOptions(): 
- Presents user options in a text-based format
- Make sure to add yours
selection(char select):
- A switch case that runs a method, based on input from stdin
- Make sure to add your method here
 */

#include <sqlite3.h>
#include <stdio.h>
#include "programs/database.h"
#include "programs/tools.h"
#include "programs/allApps.h"


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
	puts("|7 --- Add / Delete accounts                    |");
	puts("|8 --- Change your password                     |");
	puts("|9 ---                                          |");
	puts("|0 --- Exit                                     |");
	puts(" -----------------------------------------------");
	puts(" ");
}

void selection(sqlite3 *db, char select, char *name){
	switch(select){
	case '1': currentTime();  break;
	case '2': electricBill(); break;
	case '3': guessGame(); break;
	case '4': calendar(); break;
	case '5': workplaceSim(name); break;
	case '6': listOptions(); break;
	//case '7': manageAccounts(db, char *username, char *password); break;
	//case '8': changePassword(db, char *username, char *password); break;
	//case '9':
	case '0': break;
	default: puts("Invalid option entered. Try again."); break;
	}
}
