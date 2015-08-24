//Descripton: Tells the user the current time

#include "Tools.c"

CurrentTime(void){
   time_t rawtime;
   struct tm * timeinfo;
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   printf ("\nCurrent local time and date:\n%s", asctime(timeinfo));
}