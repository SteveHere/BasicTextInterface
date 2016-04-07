/*
 * database.h
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_APPS_DATABASE_H_
#define PROJECT_APPS_DATABASE_H_

//Used to print debug output of opening a database
void openDBResponse(int openDBFail);

//Creates databases
void createDatabase(char *databaseName);

//Checks if the database exists. If not, the function creates the database.
void doesDatabaseExist(char *databaseName);

//Adds a user to the database
void addUser(sqlite3 *db, char *username, char *password);

int searchForUser(sqlite3 *db, char *username, char *password);
int changePassword(sqlite3 *db, char *username, char *password);


#endif /* PROJECT_APPS_DATABASE_H_ */
