//Description: This is where the whole interface is. A high-level view of the entire thing.

#include "EverythingFromApps.c"

int Environment(void){
   int start_boolean = 0;
   char select;
   Greeting();
   ListOptions();
   while(select!='0'){
      puts("--------------------------------------------------");
      if(start_boolean){
         printf("What would you like to do now, %s?\n",name);}
      else{
         printf("What would you like to do, %s?\n",name); start_boolean++;}
      select = Input();
      if(select!='0'){puts("--------------------------------------------------");}
      Selection(select);
   }
   free(name);
   printf("\nBye bye!\n");
   puts("--------------------------------------------------");
   return 0; 
}
