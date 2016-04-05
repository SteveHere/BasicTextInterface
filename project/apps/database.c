/*
 * database.c
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#include <sqlite3.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void createDatabase(char *databaseName){
	sqlite3 *db;
	char *zErrMsg = 0;
	int  rc;
	char *sql;

	/* Open database */
	rc = sqlite3_open(databaseName, &db);

	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}else{
		fprintf(stdout, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "CREATE TABLE DATABASE("  \
			"ID INT PRIMARY KEY     NOT NULL," \
			"USERNAME           TEXT    NOT NULL," \
			"PASSWORD           CHAR(100)"
			");";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
}

void openDatabase(sqlite3 *db, char *databaseName){
	int openDBFail;

	openDBFail = sqlite3_open(databaseName, &db);

	if( openDBFail == TRUE ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}else{
		fprintf(stderr, "Opened database successfully\n");
	}
}

void closeDatabase(sqlite3 *db){
	sqlite3_close(db);
}

int addUser(char *username, char *password){
	//add code here
	return TRUE;
}

int searchForUser(char *username, char *password){
	//add code here
	return TRUE;
}

int changePassword(char *username, char *password){
	//add code here
	return TRUE;
}
