/*
 * everythingFromApps.h
 *
 *  Created on: Mar 25, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_EVERYTHINGFROMAPPS_H_
#define PROJECT_EVERYTHINGFROMAPPS_H_

void listOptions(void);

void selection(char select, sqlite3 *db, char *username, int isAdmin);

#endif /* PROJECT_EVERYTHINGFROMAPPS_H_ */
