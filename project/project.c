//TODO: 
//- Add a method to login to the Interface
//  - Set up inputs for Username and Password
//  - Use bcrypt to hash password
//  - Store them in a file
//  - Find a way to protect the file
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "environment.h"
#include "apps/tools.h"

int main(void){
	char login;
	do{
		char *username;
		char *password;
		login = inputBinary(0);
		lineBreak();
		if( (login=='Y'||login=='y') ){
			printf("Enter your username: ");
			username = stringInput();
			printf("Enter your password: ");
			password = stringInput();
			//verify if username and password are similar
			if((strcmp(username, "admin") == 0) && (strcmp(password, "123456") == 0)){
				lineBreak();
				environment(username);
			}
			else{
				printf("\nIncorrect username or password. Try again.\n");
				lineBreak();
			}
			free(username);
			free(password);
		}
	}while( !( (login=='N')||(login=='n') ) );
	puts("Bye!");
	return 0;
}
