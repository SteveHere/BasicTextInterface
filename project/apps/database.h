/*
 * database.h
 *
 *  Created on: Apr 1, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_APPS_DATABASE_H_
#define PROJECT_APPS_DATABASE_H_

int addUser(char *username, char *password);
int searchForUser(char *username, char *password);
int changePassword(char *username, char *password);


#endif /* PROJECT_APPS_DATABASE_H_ */
