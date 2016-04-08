/*
 * accounts.h
 *
 *  Created on: Apr 8, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_PROGRAMS_ACCOUNTS_H_
#define PROJECT_PROGRAMS_ACCOUNTS_H_

//Add or remove an account
void manageAccounts(db, char *username, char *password);

//Change the current account's password
void changeYourPassword(db, char *username, char *password);


#endif /* PROJECT_PROGRAMS_ACCOUNTS_H_ */
