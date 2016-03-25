/*
Description:
This place is used to:
- store custom methods/functions that can be used in more than one app
- import libraries (make sure to include them the README)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for input of chars
char charInput(){
	char *buffer;  char ans;
	int bytes;
	size_t read_size = 4;
	scanf(" ");
	buffer = (char*) malloc (read_size+1);
	bytes = getline(&buffer,&read_size,stdin);
	if(buffer != NULL){
		size_t length = strlen(buffer);
		if(length > 0 && buffer[length-1]=='\n'){
			buffer[--length]='\0';
		}
	}
	if(bytes!=-1){
		ans = buffer[0];
		free(buffer);
		return ans;
	}
	//for error handling, empty is returned as result.
	else{
		fputs("Something went wrong. Please try again.",stderr);
		free(buffer);
		return '\0';
	}
}

char* stringInput(){
	int bytes_read;
	size_t size = 50;
	char *name = (char *) malloc (size + 1);
	bytes_read = getline(&name,&size,stdin);
	//removes '\n' at end of line if it exists
	if(name != NULL){
		size_t len = strlen(name);
		if(len > 0 && name[len-1]=='\n'){ name[--len]='\0';}
	}
	if(bytes_read != -1){
		return (char *) name;
	}
	else{
		puts("ERROR!ERROR!EXITING PROGRAM!");
		exit(0);
	}
}

//to be used for verification purposes
char verify(){
	printf("Enter 'Y' to continue (Y/N): ");
	return charInput();
	puts(" ");
}

//TODO: Add more functions for the input of characters into the program




