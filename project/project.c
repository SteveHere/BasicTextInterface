//TODO:
//  - Use bcrypt to hash password
//  - Store them in a sql database
//  - Find a way to protect the database
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <unistd.h>
#include "environment.h"
#include "programs/database.h"
#include "programs/tools.h"

int main(void){
	sqlite3 *db;	int rc;
	char *databaseName = "Database.db";
	char *username, *password;
	char login;
	//Creates database if it doesn't exist
	doesDatabaseExist(databaseName);
	//Opens connection to database
	rc = sqlite3_open(databaseName, &db);
	openDBResponse(rc);
	do{
		int isAdmin;
		login = inputBinary(0);
		lineBreak();
		if( (login=='Y'||login=='y') ){
			printf("Enter your username: ");
			username = stringInput(0);
			printf("Enter your password: ");
			password = stringInput(1);
			//verify if username and password are similar
			if(searchForUser(db, username, password)){
				isAdmin = isUserAdmin(db, username, password);
				puts(" ");
				lineBreak();
				environment(username, isAdmin);
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
	sqlite3_close(db);
	return 0;
}
