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

void removeUserFunction(sqlite3* db);

void addUserFunction(sqlite3* db);

//Add or remove an account
void manageAccounts(sqlite3 *db, char *username, int isAdmin){
	if(isAdmin){
		char *password;
		printf("Enter your password: ");
		password = stringInput(1);
		if(searchForUser(db, username, password)){
			int cont;
			do{
				lineBreak();
				char option;
				int attemptResult = 0;
				do{
					printf("Do you want to Add(A) or Remove(R) accounts? ");
					option = charInput();
					attemptResult = (
							(option=='A') || (option=='a') || (option=='R') || (option=='r')
					);
					if(attemptResult != 1){
						printf("\nIncorrect input detected. Please enter 'A' or 'R'.\n");
						lineBreak();
					}
				}while(attemptResult != 1);
				if( (option == 'A') || (option == 'a') ){
					addUserFunction(db);
				}
				else{
					removeUserFunction(db);
				}
				cont = inputYOrN(0);
			}while( cont );
		}
		else{
			printf("\nIncorrect password. Exiting program.\n");
		}
		free(password);
	}
	else{
		printf("You are not an admin.\n");
		puts("Please log out and retry using an admin account.");
	}
	sleep(2);
}

//Change the current account's password
void changeYourPassword(sqlite3 *db, char *username){
	char *password;
	char *newPassword, *newPassword2;
	//Give three tries to change password
	for(int i = 0; i < 3; i++){
		//Ask for current password
		printf("Current password: ");
		password = stringInput(1);
		if(searchForUser(db, username, password)){
			//Ask for new password
			printf("New password: ");
			newPassword = stringInput(1);
			if(strlen(newPassword) <= 0){
				printf("\nInvalid password entered. Please try again.\n");
			}
			else{
				//Ask for new password again
				printf("Re-enter new password: ");
				newPassword2 = stringInput(1);
				if(strlen(newPassword2) <= 0){
					printf("\nInvalid password entered. Please try again.\n");
				}
				else{
					//Check if both entries are equal
					if(strcmp(newPassword, newPassword2) == EQUAL ){
						//Change password
						changePassword(db, username, newPassword);
						printf("\nPassword change successful. Exiting program.\n");
						i = 3;
					}
					//Output errors if attemps fail
					else if(i == 2){
						printf("\nToo many tries used. Exiting program.\n");
					}
					else{
						printf("\nNon-equal inputs detected. Please try again.\n");
					}
				}
				free(newPassword2);
			}
			free(newPassword);
		}
		//Output errors if attemps fail
		else if(i == 2){
			printf("\nToo many tries used. Exiting program.\n");
		}
		else{
			printf("\nIncorrect password. Try again.\n");
		}
		free(password);
		sleep(2);
	}
}

void removeUserFunction(sqlite3* db){
	char* usernameToBeRemoved;
	printf("\nList of users:\n");
	listUsers(db);
	printf("User to remove: ");
	usernameToBeRemoved = stringInput(0);
	if (doesUserExist(db, usernameToBeRemoved)) {
		removeUser(db, usernameToBeRemoved);
		printf("%s has been removed from the database.\n", usernameToBeRemoved);
	}
	else{
		puts("This user does not exist. Please try again.");
	}
	free(usernameToBeRemoved);
}

void addUserFunction(sqlite3* db){
	int adminPriv = inputYesOrNo("Make the new user admin(Y/N)?");
	printf("New username: ");
	char* newUsername = stringInput(0);
	if(strlen(newUsername) <= 0){
		printf("\nInvalid username entered. Please try again.\n");
	}
	else{
		printf("New user's password: ");
		char* newPassword = stringInput(1);
		if(strlen(newPassword) <= 0){
			printf("\nInvalid password entered. Please try again.\n");
		}
		else{
			addUser(db, adminPriv, newUsername, newPassword);
			printf("\n%s has been entered into the database\n", newUsername);
		}
		free(newPassword);
	}
	free(newUsername);
}
