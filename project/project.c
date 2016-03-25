//TODO: 
//- Add a method to login to the Interface
//  - Set up inputs for Username and Password
//  - Use bcrypt to hash password
//  - Store them in a file
//  - Find a way to protect the file
//

#include <stdio.h>
#include "environment.h"
#include "apps/tools.h"

int main(void){
	char buffer[50];
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
		if((login=='Y'||login=='y') && (username == "admin") && (password == "123456")){
			environment(username);
		} //modify parameter once login method has been set up
		else{
			puts("Incorrect username or password. Try again."); //only use when login method is complete
		}
	}while(!(login=='N'||login=='n'));
	return 0;
}
