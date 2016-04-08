/*
 * accounts.c
 *
 *  Created on: Apr 8, 2016
 *      Author: SteveHere
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "tools.h"
#include "database.h"

#define EQUAL 0

//Add or remove an account
void manageAccounts(sqlite3 *db, char *username, int isAdmin){
	if(isAdmin){

	}
	else{
		printf("You are not an admin.\n");
		puts("Please log out and retry using an admin account.");
		lineBreak();
	}
}

//Change the current account's password
void changeYourPassword(sqlite3 *db, char *username){
	char *password;
	char *newPassword, *newPassword2;
	for(int i = 0; i < 3; i++){
		printf("Enter your current password: ");
		password = stringInput(1);
		if(searchForUser(db, username, password)){
			printf("Enter your new password: ");
			newPassword = stringInput(1);
			printf("Re-enter your new password: ");
			newPassword2 = stringInput(1);
			if(strcmp(newPassword, newPassword2) == EQUAL ){
				changePassword(db, username, newPassword);
				printf("\nPassword change successful. Exiting program.\n");
				i = 3;
			}
			else if(i == 2){
				printf("\nToo many tries used. Exiting program.\n");
			}
			else{
				printf("\nNon-equal inputs detected. Please try again.\n");
			}
			free(newPassword);	free(newPassword2);
		}
		else if(i == 2){
			printf("\nToo many tries used. Exiting program.\n");
		}
		else{
			printf("\nIncorrect password. Try again.\n");
		}
		free(password);
		lineBreak();
	}
}

