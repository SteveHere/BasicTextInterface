//TODO: 
//- Add a method to login to the Interface
//  - Set up inputs for Username and Password
//  - Use bcrypt to hash password
//  - Store them in a file
//  - Find a way to protect the file
//

#include <stdio.h>
#include <string.h>
#include "environment.h"
#include "apps/tools.h"

int main(void){
	//char buffer[50];
	char *username = "admin";
	char *password = "123456";
	char login;
	do{
		printf("Do you want to login(Y) or exit(N)? ");
		login = input();
		puts("--------------------------------------------------");
		/*
		printf("\nEnter your username: ");
		fgets(&buffer,50,stdin);
		sscanf(buffer, "%s", username);
		memset(&buffer[0], 0, sizeof(buffer));
		printf("\nEnter your password: ");
		fgets(buffer,50,stdin);
		sscanf(buffer, "%s", password);
		*/
		if( (login=='Y'||login=='y') ){
			//verify if username and password are similar
			if((strcmp(username, "admin") == 0) && (strcmp(password, "123456") == 0)){
				environment(username);
			}
			else{
				puts("Incorrect username or password. Try again.");
			}
		}
	}while(!(login=='N'||login=='n'));
	puts("Bye!");
	return 0;
}
