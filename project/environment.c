//Description: This is where the whole interface is. A high-level view of the entire thing.

#include <stdio.h>
#include "everythingFromApps.h"
#include "programs/tools.h"

int environment(char *name){
	int start_boolean = 0;
	char select;
	printf("Hello there, %s.\n\n", name);
	listOptions();
	do{
		lineBreak();
		if(start_boolean){
			printf("What would you like to do now, %s? ",name);}
		else{
			printf("What would you like to do, %s? ",name); start_boolean++;}
		select = charInput();
		if(select!='0')
			lineBreak();
		selection(select, name);
	}while(select!='0');
	printf("\nBye, %s!\n", name);
	lineBreak();
	return 0;
}
