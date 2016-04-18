//Descripton: Tells the user the current time

#include <stdio.h>
#include <time.h>
#include "../tools.h"

void currentTime(void){
	clrscr();
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	printf ("Current local time and date:\n%s", asctime(timeinfo));
	lineBreak();
}
