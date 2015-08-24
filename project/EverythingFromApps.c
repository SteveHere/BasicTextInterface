#include "Apps/Tools.c"
#include "Apps/CurrentTime.c"
#include "Apps/ElectricBill.c"
#include "Apps/GuessGame.c"
#include "Apps/Calendar.c"

   char *name;  //for Greeting() and main()

Greeting(void){
   int bytes_read;
   int size = 30;
   puts("Hello. What is your name?");
   name = (char *) malloc (size + 1);
   bytes_read = getline(&name,&size,stdin);
   //removes '\n' at end of line if it exists
   if(name != NULL){
      size_t len = strlen(name);
      if(len > 0 && name[len-1]=='\n'){ name[--len]='\0';}
   }
   if(bytes_read != -1){
      puts("--------------------------------------------------");
      printf("Hello there, %s.\n\n",name);
   }
   else{
      puts("ERROR!ERROR!EXITING PROGRAM!");
      exit(0);
   }
   
}

ListOptions(void){
   puts(" -------------------------------- ");
   puts("|Options                         |");
   puts("|--------------------------------|");
   puts("|1 --- Current Time and Date     |");
   puts("|2 --- Electric Bill Calculator  |");
   puts("|3 --- The Guessing Game         |");
   puts("|4 --- Calendar Generator        |");
   puts("|5 --- Math Game (in progress)   |");
   puts("|6 --- List of Options           |");
   puts("|0 --- Exit                      |");
   puts(" --------------------------------");
}

Selection(char select){
   switch(select){
      case '1': CurrentTime();  break;
      case '2': ElectricBill(); break;
      case '3': GuessGame(); break;
      case '4': Calendar(); break;
      case '5': puts("In progress. come back later."); break;
      case '6': ListOptions(); break;
      case '0': break;
      default: puts("Invalid option entered. Try again."); break;
      }
}