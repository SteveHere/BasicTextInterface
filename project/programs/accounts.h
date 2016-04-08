/*
 * accounts.h
 *
 *  Created on: Apr 8, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_PROGRAMS_ACCOUNTS_H_
#define PROJECT_PROGRAMS_ACCOUNTS_H_

//Add or remove an account
void manageAccounts(sqlite3 *db, char *username, int isAdmin);

//Change the current account's password
void changeYourPassword(sqlite3 *db, char *username);


#endif /* PROJECT_PROGRAMS_ACCOUNTS_H_ */
