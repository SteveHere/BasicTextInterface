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
		char *password;
		printf("Enter your password: ");
		password = stringInput(1);
		if(searchForUser(db, username, password)){
			char cont;
			do{
				char option;
				int attemptResult = 0;
				do{
					printf("Do you want to Add(A) or Remove(R) accounts? ");
					option = charInput();
					attemptResult = (
							(option=='A') || (option=='a') || (option=='R') || (option=='r')
					);
					if(attemptResult != 1){
						puts("");
						puts("Incorrect input deteceted. Please enter 'A' or 'R'.");
						lineBreak();
					}
				}while(attemptResult != 1);
				if( (option == 'A') || (option == 'a') ){
					int adminPriv = 0;
					char *newUsername, *newPassword;
					printf("Make new user admin? ");
					scanf("%i\n", &adminPriv);
					printf("New username: ");
					newUsername = stringInput(0);
					printf("New user's password: ");
					newPassword = stringInput(1);
					addUser(db, adminPriv, newUsername, newPassword);
					printf("%s has been entered into the database\n", newUsername);
					free(newUsername);	free(newPassword);
				}
				else{
					char *usernameToBeRemoved;
					listUsers(db);
					printf("User to remove: ");
					usernameToBeRemoved = stringInput(0);
					removeUser(db, usernameToBeRemoved);
					printf("%s has been removed from the database.\n"
							, usernameToBeRemoved);
					free(usernameToBeRemoved);
				}
				cont = inputBinary(1);
			}while( !( (cont=='N') || (cont=='n') ) );
		}
		else{
			printf("\nIncorrect password. Exiting program.");
		}
		free(password);
	}
	else{
		printf("You are not an admin.\n");
		puts("Please log out and retry using an admin account.");
	}
}

//Change the current account's password
void changeYourPassword(sqlite3 *db, char *username){
	char *password;
	char *newPassword, *newPassword2;
	for(int i = 0; i < 3; i++){
		printf("Current password: ");
		password = stringInput(1);
		if(searchForUser(db, username, password)){
			printf("New password: ");
			newPassword = stringInput(1);
			printf("Re-enter new password: ");
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
	}
}

