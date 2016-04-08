/*
Description:
This place is used to:
- store custom methods/functions that can be used in more than one app
- import libraries (make sure to include them the README)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#define TRUE 1
#define FALSE 0

//outputs a line to the console
void lineBreak(){
	puts("----------------------------------------");
}

//a getline() substitute for passwords. Disables echo so that input cannot be seen
//Obtained from: http://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/getpass.html
ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream){
	struct termios old, new;
	int nread;

	/* Turn echoing off and fail if we can�t. */
	if (tcgetattr (fileno (stream), &old) != 0)
		return -1;
	new = old;
	new.c_lflag &= ~ECHO;
	if (tcsetattr (fileno (stream), TCSAFLUSH, &new) != 0)
		return -1;

	/* Read the password. */
	nread = getline (lineptr, n, stream);

	/* Restore terminal. */
	(void) tcsetattr (fileno (stream), TCSAFLUSH, &old);

	return nread;
}

//for input of chars
char charInput(){
	char *buffer;  char ans;
	int bytes;
	size_t read_size = 1;
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
	//for error handling, empty is returned as a result.
	else{
		fputs("Something went wrong with charInput(). Please try again.", stderr);
		free(buffer);
		return '\0';
	}
}

//for input of strings, with the turnOffEcho flag for sensitive info
char* stringInput(int turnOffEcho){
	int bytes_read;
	size_t read_size = 1;
	char *name = (char *) malloc (read_size + 1);
	if(turnOffEcho == TRUE){
		bytes_read = my_getpass(&name,&read_size,stdin);
		//added puts() as newline is not created when 'enter' is pushed
		puts(" ");
	}
	else
		bytes_read = getline(&name,&read_size,stdin);
	//removes '\n' at end of line if it exists
	if(name != NULL){
		size_t len = strlen(name);
		if(len > 0 && name[len-1]=='\n'){ name[--len]='\0';}
	}
	if(bytes_read != -1){
		return (char *) name;
	}
	//for error handling, a Null pointer is returned as a result.
	else{
		fputs("Something went wrong with stringInput(). Please try again.", stderr);
		free(name);
		return NULL;
	}
}

//to be used for Y/N input attempts
char inputBinary(int continueMessage){
	char attempt;
	int attemptResult;
	do{
		//output continue message if flag is 1, else output login message
		if(continueMessage)
			printf("Enter 'Y' to continue (Y/N): ");
		else
			printf("Do you want to login(Y) or exit(N)? ");
		attempt = charInput();
		attemptResult = (
				(attempt=='N') || (attempt=='n') || (attempt=='Y') || (attempt=='y')
				);
		if(attemptResult != TRUE){
			puts("");
			puts("Incorrect input deteceted. Please enter 'Y' or 'N'.");
			lineBreak();
		}
	}while(attemptResult != TRUE);
	return attempt;
}

//TODO: Add more functions for the input of characters into the program



