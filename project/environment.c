//Description: This is where the whole interface is. A high-level view of the entire thing.

#include <stdio.h>
#include "apps/tools.h"
#include "everythingFromApps.h"

int environment(char *name){
	int start_boolean = 0;
	char select;
	listOptions();
	while(select!='0'){
		puts("--------------------------------------------------");
		if(start_boolean){
			printf("What would you like to do now, %s?\n",name);}
		else{
			printf("What would you like to do, %s?\n",name); start_boolean++;}
		select = charInput();
		if(select!='0'){puts("--------------------------------------------------");}
		selection(select, name);
	}
	printf("\nBye, %s!\n", name);
	puts("--------------------------------------------------");
	return 0;
}
