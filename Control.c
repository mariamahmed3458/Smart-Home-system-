/*
 * Control.c
 *
 *  Created on: Aug 18, 2024
 *      Author: Mariam
 */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "control.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LIGHT_PIN 0
#define DOOR_PIN 1
#define ALARM_PIN 2

void control_light(int state) {
    if (state) {
        PORTB |= (1 << LIGHT_PIN); // Turn light on
        UART_TransmitString("light is on ");
    } else {
        PORTB &= ~(1 << LIGHT_PIN); // Turn light off
        UART_TransmitString("light is off ");
    }
}

void control_door(int state) {
    if (state) {
        PORTB |= (1 << DOOR_PIN); // Open door
        UART_TransmitString("the door is open ");
    } else {
        PORTB &= ~(1 << DOOR_PIN); // Close door
        UART_TransmitString("the door is closed");
    }
}

void activate_alarm() {
    PORTB |= (1 << ALARM_PIN); // Activate alarm
   /* _delay_ms(5000); // Alarm duration
    PORTB &= ~(1 << ALARM_PIN); // Deactivate alarm*/
}
