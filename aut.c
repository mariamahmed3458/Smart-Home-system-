/*
 * aut.c
 *
 *  Created on: Aug 18, 2024
 *      Author: Mariam
 */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "aut.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>



typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

User users[MAX_USERS] = {
    {"user1", "password1"},
    {"user2", "password2"},
    // Add more users as needed
};

int authenticate(char* username, char* password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if ((strcmp(users[i].username, username) == 0) && (strcmp(users[i].password, password) == 0)) {
            return 1; // Success
        }
    }
    return 0; // Failure
}
