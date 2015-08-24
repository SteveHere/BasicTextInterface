#include "EverythingFromApps.c"

//Description: This is where the whole interface is

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
      puts("--------------------------------------------------");
      Selection(select);
   }
   free(name);
   printf("\nBye bye!\n"); sleep(2);
   return 0; 
}
