/*
 * database.h
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_PROGRAMS_DATABASE_H_
#define PROJECT_PROGRAMS_DATABASE_H_

//Used to print debug output of opening a database
void openDBResponse(int openDBFail);

//Creates databases
void createDatabase(char *databaseName);

//Checks if the database exists. If not, the function creates the database.
void doesDatabaseExist(char *databaseName);

//Adds a user to the database
void addUser(sqlite3 *db, int isAdmin, char *username, char *password);

//Removes a user from the database
void removeUser(sqlite3 *db, char *username);

//Shows a list of users in the database
void listUsers(sqlite3 *db);

//Changes a user's password
void changePassword(sqlite3 *db, char *username, char *password);

//Searches for the user in the database
int searchForUser(sqlite3 *db, char *username, char *password);

//Checks if the user is an admin
int isUserAdmin(sqlite3 *db, char *username, char *password);

#endif /* PROJECT_PROGRAMS_DATABASE_H_ */
