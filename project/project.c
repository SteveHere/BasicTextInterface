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
	do{
		char login;
		char *username;
		char *password;
		do{
			printf("Do you want to login(Y) or exit(N)? ");
			login = charInput();
		}while(
				!( (login=='N') || (login=='n') || (login=='Y') || (login=='y') )
				);
		puts("--------------------------------------------------");
		if((login=='N')||(login=='n'))
			break;
		printf("Enter your username: ");
		username = stringInput();
		printf("Enter your password: ");
		password = stringInput();
		if( (login=='Y'||login=='y') ){
			//verify if username and password are similar
			if((strcmp(username, "admin") == 0) && (strcmp(password, "123456") == 0)){
				environment(username);
			}
			else{
				puts("Incorrect username or password. Try again.");
			}
		}
		free(username);
		free(password);
	}while(1);
	puts("Bye!");
	return 0;
}
