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
#include "apps/tools.h"
#include "apps/database.h"

int main(void){
	sqlite3 *db;
	int rc;
	char *databaseName = "Database.db";
	//char *username = "admin";
	//char *password = "123456";
	doesDatabaseExist(databaseName);
	//open Database.db
	rc = sqlite3_open(databaseName, &db);
	openDBResponse(rc);

	addUser(db, "user", "123");
	changePassword(db, "admin", "123qweasd");
	sqlite3_close(db);

	//focusing on database now; no relation to other stuff for now
	/*
	char login;
	do{
		char *username;
		char *password;
		login = inputBinary(0);
		lineBreak();
		if( (login=='Y'||login=='y') ){
			printf("Enter your username: ");
			username = stringInput(0);
			printf("Enter your password: ");
			password = stringInput(1);
			//verify if username and password are similar
			if((strcmp(username, "admin") == 0) && (strcmp(password, "123456") == 0)){
				puts(" ");
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
	*/
	puts("Bye!");
	return 0;
}
