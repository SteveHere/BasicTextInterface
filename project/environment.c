//Description: This is where the whole interface is. A high-level view of the entire thing.

#include <stdio.h>
#include <unistd.h>
#include <sqlite3.h>
#include "everythingFromApps.h"
#include "programs/tools.h"

int environment(sqlite3 *db, char *username, int isAdmin){
	int start_boolean = 0;
	char select;
	do{
		if( (select != '1') && (select != '6') ) clrscr();
		if(start_boolean){
			printf("What would you like to do now, %s? ",username);
		}
		else{
			printf("Hello there, %s.\n\n", username);
			listOptions();
			lineBreak();
			printf("What would you like to do, %s? ",username);
			start_boolean = 1;
		}
		select = charInput();
		if(select != '0') clrscr();
		selection(select, db, username, isAdmin);
	}while( select!='0' );
	lineBreak();
	printf("Bye, %s!\n", username);
	sleep(2);
	clrscr();
	return 0;
}
