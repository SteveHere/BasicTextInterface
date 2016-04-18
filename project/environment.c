//Description: This is where the whole interface is. A high-level view of the entire thing.

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "everythingFromApps.h"
#include "programs/tools.h"

int environment(sqlite3 *db, char *username, int isAdmin){
	int start_boolean = 0;
	char select;
	printf("Hello there, %s.\n\n", username);
	listOptions();
	lineBreak();
	do{
		if(start_boolean){
			printf("What would you like to do now, %s? ",username);
		}
		else{
			printf("What would you like to do, %s? ",username);
			start_boolean = 1;
		}
		select = charInput();
		clrscr();
		selection(select, db, username, isAdmin);
		clrscr();
	}while( select!='0' );
	printf("\nBye, %s!\n", username);
	sleep(1);
	clrscr();
	return 0;
}
