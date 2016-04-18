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

//Outputs a line to the console
void lineBreak(){
	puts("----------------------------------------");
}

//Clears the command console screen
void clrscr(){

	//For Linux systems
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    //For Windows systems
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

//A getline() substitute for passwords. Disables echo so that input cannot be seen
//Obtained from: http://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/getpass.html
ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream){
	struct termios old, new;
	int nread;

	/* Turn echoing off and fail if we can’t. */
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

//For the input of chars
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

//For the input of strings, with the turnOffEcho flag for sensitive info
char* stringInput(int turnOffEcho){
	int bytes_read;
	size_t read_size = 1;
	char *username = (char *) malloc (read_size + 1);
	if(turnOffEcho == TRUE){
		bytes_read = my_getpass(&username,&read_size,stdin);
		//added puts() as newline is not created when 'enter' is pushed
		puts(" ");
	}
	else
		bytes_read = getline(&username,&read_size,stdin);
	//removes '\n' at end of line if it exists
	if(username != NULL){
		size_t len = strlen(username);
		if(len > 0 && username[len-1]=='\n'){ username[--len]='\0';}
	}
	if(bytes_read != -1){
		return (char *) username;
	}
	//for error handling, an empty string is returned as a result.
	else{
		fputs("Something went wrong with stringInput(). Please try again.", stderr);
		free(username);
		return "";
	}
}

//To be used for Y/N input attempts
//(1 for Yes, 0 for No)
int inputYesOrNo(char *customMessage){
	char attempt;
	int attemptResult;
	do{
		printf("%s ", customMessage);
		attempt = charInput();
		attemptResult = (
				(attempt=='N') || (attempt=='n') || (attempt=='Y') || (attempt=='y')
		);
		if(attemptResult != TRUE){
			puts("");
			puts("Incorrect input detected. Please enter 'Y' or 'N'.");
			lineBreak();
		}
	}while(attemptResult != TRUE);
	//By this point, only 'Y' or 'N' exist.
	//All we need to do now is to check if it's 'Y'.
	return ( (attempt=='Y') || (attempt=='y') );
}

//Version of inputYOrN that contains default templates
int inputYOrN(int template){
	char *customMessage;
	//output message based on continueMessage flag
	//0 is the default flag
	switch(template){
	case 1:
		customMessage = "Do you want to login(Y) or exit(N)?";
		break;
	default:
		customMessage = "Enter 'Y' to continue (Y/N):";
		break;
	}
	return inputYesOrNo(customMessage);
}

//TODO: Add more functions for the input of characters into the program




