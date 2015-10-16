/*
Description: 
This place is used to:
- store custom methods/functions that can be used in more than one app
- import libraries (make sure to include them the README)
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//for input of chars
char input(void){  
   char *buffer;  char ans;
   int bytes;
   int read_size = 4;
   scanf(" ");
   buffer = (char*) malloc (read_size+1); 
   bytes = getline(&buffer,&read_size,stdin);
   if(buffer != NULL){
      size_t length = strlen(buffer);
      if(length > 0 && buffer[length-1]=='\n'){
         buffer[--length]='\0';
      }
   }
   if(bytes!=-1){ ans = buffer[0]; return ans;}
   //for error handling
   else{ fputs("Something went wrong. Please try again.",stderr); }
   free(buffer);
}

//to be used for verification purposes
char verify(void){  
   char c;
   printf("Enter 'Y' to continue (Y/N): ");
   c = input();
   puts(" ");
   return c;
}

//TODO: Add more functions for the input of characters into the program