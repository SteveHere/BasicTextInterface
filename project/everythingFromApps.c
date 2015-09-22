/*
Description:
greeting():
- Reads from stdin the user's name. 
- Input buffer overflows may have been solved.
- Mostly stable.
listOptions(): 
- Presents user options in a text-based format
- Make sure to add yours
selection(char select):
- A switch case that runs a method, based on input from stdin
- Make sure to add your method here
*/

   char *name;  //for Greeting() and main()

#include "apps/tools.c"
#include "apps/currentTime.c"
#include "apps/electricBill.c"
#include "apps/guessGame.c"
#include "apps/calendar.c"
#include "apps/workplaceSim.c"

greeting(void){
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

listOptions(void){
   puts(" ----------------------------------------------- ");
   puts("|Options                                        |");
   puts("|-----------------------------------------------|");
   puts("|1 --- Current Time and Date                    |");
   puts("|2 --- Electric Bill Calculator                 |");
   puts("|3 --- The Guessing Game                        |");
   puts("|4 --- Calendar Generator                       |");
   puts("|5 --- Workplace Simulator 2015 (in progress)   |");
   puts("|6 --- List of Options                          |");
   puts("|0 --- Exit                                     |");
   puts(" -----------------------------------------------");
}

selection(char select){
   switch(select){
      case '1': currentTime();  break;
      case '2': electricBill(); break;
      case '3': guessGame(); break;
      case '4': calendar(); break;
      case '5': workplaceSim(); break;
      case '6': listOptions(); break;
      //case '7': 
      //case '8':
      //case '9':
      case '0': break;
      default: puts("Invalid option entered. Try again."); break;
      }
}
