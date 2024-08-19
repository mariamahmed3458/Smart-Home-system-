/*
 * aut.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Mariam
 */

#ifndef AUT_H_
#define AUT_H_
#define MAX_USERS 10
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 3

int authenticate(char* username, char* password);

#endif /* AUT_H_ */
