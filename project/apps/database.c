/*
 * database.c
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#include <sqlite3.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//Used in sqlite3_exec()'s 4th parameter
static int callback(void *data, int argc, char **argv, char **azColName){
	fprintf(stderr, "%s: ", (const char*)data);
	for(int i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

//simplifies executing SQL Commands to 2 parameters
int executeSQLCommand(sqlite3 *db, char *sql){
	char *zErrMsg = 0;
	int result;
	const char* data = "Callback";

	//Execute SQL statement
	result = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

	if( result != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
		fprintf(stdout, "Operation done successfully\n");

	return result;
}

//Used to print debug output
void openDBResponse(int openDBFail){
	if( openDBFail == TRUE )
		fprintf(stderr, "Can't open Database.db\n");
	else
		fprintf(stderr, "Opened database successfully\n");
}

//Creates databases
void createDatabase(char *databaseName){
	sqlite3 *db;

	/* Open database */
	int rc = sqlite3_open(databaseName, &db);
	openDBResponse(rc);

	/* Create SQL statement */
	char *sql = "Create Table Database("
			"ID        Int       PRIMARY KEY  NOT NULL,"
			"Username  Text                   NOT NULL,"
			"Password  Char(100)              NOT NULL);"
			"Insert into Database values (1, 'admin', '123456'); ";

	rc = executeSQLCommand(db, sql);

	sqlite3_close(db);
}

//Checks if the database exists. If not, the function creates the database.
void doesDatabaseExist(char *databaseName){
	if(access(databaseName, F_OK) != -1 )
		puts("Database.db exists.");
	else{
		puts("Database.db does not exist. Creating it.");
		createDatabase(databaseName);
	}
}

//Adds a user to the database
void addUser(sqlite3 *db, char *username, char *password){
	//Create SQL statement
	char *sql = sqlite3_mprintf(
			"Insert into Database values "
			"((Select max(ID) From Database)+1, '%q', '%q');"
			, username, password);

	//Execute SQL statement
	executeSQLCommand(db, sql);
}

//Changes a user's password
void changePassword(sqlite3 *db, char *username, char *password){
	//Create SQL statement
	char * sql = sqlite3_mprintf(
			"Update Database set Password = '%q' where Username = '%q';"
			, password, username);

	//Execute SQL statement
	executeSQLCommand(db, sql);
}

//Searches for the user in the database
int searchForUser(sqlite3 *db, char *username, char *password){
	int result = 1;
	sqlite3_stmt *stmt;

	//Create SQL statement
	char * sql = sqlite3_mprintf(
			"Select EXISTS(Select * From Database "
			"Where Username = '%q' and Password = '%q');"
				, password, username);

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	if (sqlite3_step(stmt) != SQLITE_ROW) {
	    printf("ERROR 1 reading data: %s\n", sqlite3_errmsg(db));
	}

	result = sqlite3_column_int(stmt, 0);

	if (sqlite3_step(stmt) != SQLITE_DONE) {
		printf("ERROR 2 reading data: %s\n", sqlite3_errmsg(db));
	}

	printf("%s, %s evals to %d\n", username, password, result);

	sqlite3_finalize(stmt);

	return result;
}


