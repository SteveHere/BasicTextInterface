/*
Game description:
This game is a text-based simulation of the daily:
   - White-collar worker
   - Data entry monkey
   - Spreadsheet-making employee

*/

#include "tools.c"

void mainWorkplaceSimLoop(void);

void workplaceSim(void){
   char cont;
   puts("Welcome to Workplace Simulator 2015!");
   cont = verify();
   puts("--------------------------------------------------");
   while(cont=='y'||cont=='Y'){
      mainWorkplaceSimLoop();
      puts("--------------------------------------------------");
      cont = verify();
   }
}

void mainWorkplaceSimLoop(void){
   char choice;
   printf("Welcome to your first day, %s! What do you want to do?", name);
   choice = input();
   //remove this section once game is complete
   puts("Game is currently being built. Please come back later.");
   //end section
   switch(choice){
      case '0': break;
      case 'e': break;
      case 'h': break;
   }
}