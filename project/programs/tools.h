/*
 * tools.h
 *
 *  Created on: Mar 25, 2016
 *      Author: SteveHere
 */

#ifndef PROJECT_PROGRAMS_TOOLS_H_
#define PROJECT_PROGRAMS_TOOLS_H_

void lineBreak();
ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream);
char charInput();
char* stringInput(int turnOffEcho);
char inputBinary(int continueMessage);

#endif /* PROJECT_PROGRAMS_TOOLS_H_ */
