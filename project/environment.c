//Description: This is where the whole interface is. A high-level view of the entire thing.

#include <stdio.h>
#include <sqlite3.h>
#include "everythingFromApps.h"
#include "programs/tools.h"

int environment(sqlite3 *db, char *username, int isAdmin){
	int start_boolean = 0;
	char select;
	printf("Hello there, %s.\n\n", username);
	listOptions();
	do{
		lineBreak();
		if(start_boolean){
			printf("What would you like to do now, %s? ",username);}
		else{
			printf("What would you like to do, %s? ",username); start_boolean++;}
		select = charInput();
		if(select!='0')
			lineBreak();
		selection(select, db, username, isAdmin);
	}while(select!='0');
	printf("\nBye, %s!\n", username);
	lineBreak();
	return 0;
}
