//Description: This app is used to make calendars based on inputs from stdin

#include <stdio.h>
#include <ctype.h>
#include <time.h>

#include "../tools.h"

void calendar(void){
	int cont;
	char buffer_a[4], buffer_b[4];
	puts("Calendar Generator");
	lineBreak();
	cont = inputYOrN(0);
	while( cont ){
		unsigned char start, number, i, a;
		lineBreak();
		printf("Enter the start day of the month (1(Mon) to 7(Sun)) : ");
		fgets(buffer_a,4,stdin);
		sscanf(buffer_a,"%hhu",&start);
		printf("\nEnter the number of days in the month: ");
		fgets(buffer_b,4,stdin);
		sscanf(buffer_b,"%hhu",&number);
		printf("\nMon  Tue  Wed  Thu  Fri  Sat  Sun");
		printf("\n---  ---  ---  ---  ---  ---  ---\n");
		for(i = 1;i < start; i++){
			printf("     ");
		}
		for(a = 1;a <= number; a++){
			printf("%d",a);
			if(a<10){      printf("    ");}
			else if(a<100){printf("   ");}
			else{          printf("  ");}
			if(((i-1+a)%7)==0){printf("\n");}else{}
		}
		printf("\n---------------------------------\n");
		printf("\nCalendar complete.\n");
		cont = inputYOrN(0);
	}
}
