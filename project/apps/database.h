/*
 * database.h
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_APPS_DATABASE_H_
#define PROJECT_APPS_DATABASE_H_

void createDatabase(char *databaseName);
void openDatabase(sqlite3 *db, char *databaseName);
void closeDatabase(sqlite3 *db);
void doesDatabaseExist(sqlite3 *db, char *databaseName);

void addUser(sqlite3 *db);
int searchForUser(char *username, char *password);
int changePassword(char *username, char *password);


#endif /* PROJECT_APPS_DATABASE_H_ */
