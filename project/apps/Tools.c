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
char Input(void){  
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
   else{ fputs("Read error. Try again.", stderr);}
   free(buffer);
}

//to be used for verification purposes
char Verify(void){  
   char c;
   printf("Enter 'Y' to continue (Y/N): ");
   c = Input();
   puts(" ");
   return c;
   }
