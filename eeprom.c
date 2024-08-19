/*
 * eeprom.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Mariam
 */

#include "LBIT_math.h"
#include "LSTD_types.h"
#include "eeprom.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

u8 eeprom_read(u16 address) {
    // Set up address register
    EEAR = address;

    // Start EEPROM read by writing EERE
    SET_BIT(EECR,EERE);

    // Return the data from the data register
    return EEDR;
}


void eeprom_write(u16 address, u8 data) {
    // Wait for completion of previous write
    while ( GET_BIT(EECR,EEWE));

    // Set address and data
    EEAR = address;
    EEDR = data;

    // Enable EEPROM master write
    SET_BIT(EECR,EEMWE);
    // Start EEPROM write
    SET_BIT(EECR,EEWE);
}
