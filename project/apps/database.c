/*
 * database.c
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#include <sqlite3.h>
#include <stdio.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

//Used in sqlite3_exec()'s 4th parameter
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	for(int i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void executeSQLCommand(sqlite3 *db, char *databaseName, char *sql){
	char *zErrMsg = 0;
	int rc;

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
		fprintf(stdout, "Operation done successfully\n");
}

//Used to print debug output
void openDBResponse(int openDBFail){
	if( openDBFail == TRUE )
		fprintf(stderr, "Can't open database: Database.db\n");
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
	char *sql = "CREATE TABLE DATABASE("  \
			"ID       INT       PRIMARY KEY  NOT NULL," \
			"USERNAME TEXT                   NOT NULL," \
			"PASSWORD CHAR(100)              NOT NULL);" \
			"INSERT INTO DATABASE VALUES (1, 'admin', '123456'); ";

	executeSQLCommand(db, databaseName, sql);

	sqlite3_close(db);
	puts("Database.db is closed");
}

//Checks if the database exists. If not, the function creates the database.
void doesDatabaseExist(char *databaseName){
	if(access(databaseName, F_OK) != -1 )
		puts("It exists");
	else{
		puts("It does not exist. Creating it.");
		createDatabase(databaseName);
	}
}

//Adds a user to the database
void addUser(sqlite3 *db, char *databaseName, char *username, char *password){
	int idNumber = 2;
	/* Create SQL statement */
	char *sql = sqlite3_mprintf(
			"INSERT INTO DATABASE VALUES (%d, '%q', '%q');",
			idNumber, username, password);

	/* Execute SQL statement */
	executeSQLCommand(db, databaseName, sql);
}

int searchForUser(char *username, char *password){
	//add code here
	return TRUE;
}

int changePassword(char *username, char *password){
	//add code here
	return TRUE;
}
