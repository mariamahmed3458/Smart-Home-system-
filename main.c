
#include <string.h>
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "control.h"
#include <avr/io.h>
#include "aut.h"
#include "uart.h"
#include "eeprom.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include"ADC_interface.h"

void UART_ReceiveString(char *str, u8 max_length);

void uart_transmit(unsigned char data);

void uart_print(const char *str) ;

void uart_print_number(uint16_t number);

void pwm_init() ;

void set_fan_speed(uint8_t speed) ;

uint8_t map_adc_to_pwm(uint16_t adc_value);
volatile uint8_t fan_speed = 0;


int main(void) {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    u16 conv_value=0;
    u16 temp_val;
    int attempts = 0;
//initialize adc
    CLR_BIT(DDRA,PIN0);
    ADC_voidini();
    ADC_voidEnable();
    SET_BIT(DDRD,PIN7);

    pwm_init();


    // Initialize UART and GPIO
    UART_Ini();
    DDRB = (1 << LIGHT_PIN) | (1 << DOOR_PIN) | (1 << ALARM_PIN); // Set pins as output

    while (1) {
    	_delay_ms(400);
    	 UART_TransmitString("temp: ");
    	  conv_value=ADC_u16Conversion(ADC0);
    	  temp_val=(conv_value* 500UL)/1024;
    	  uart_print("\r\n");

    	  uart_print_number(temp_val);
    	  uart_print("%\r\n");
    	  if (temp_val> 25) {
    	                uint8_t pwm_value = (uint8_t)((temp_val- 25) * 612 /10); // Adjust as needed
    	                set_fan_speed(pwm_value); // Set the PWM duty cycle based on the temperature
    	                if (pwm_value > 255)
    	                	pwm_value = 255;
    	                set_fan_speed(pwm_value); // Set the PWM duty cycle based on the temperature
    	            }
    	  else {
    	                set_fan_speed(0); // Turn off fan if temperature is at or below 25
    	            }
    	UART_TransmitString("Enter Username: ");
    	 UART_ReceiveString(username, USERNAME_LENGTH); // Receive username

        UART_TransmitString("Enter Password: ");
        UART_ReceiveString(password, PASSWORD_LENGTH); // Receive password


        if (authenticate(username, password)) {
        	UART_TransmitString("Login Successful\r\n");
            attempts = 0; // Reset attempts on successful login

            // Process further commands
            char command;
            UART_TransmitString("Enter Command (1: Light ON, 0: Light OFF, 2: Open Door, 3: Close Door) \r\n");
            uart_print("\n");
            command = UART_Receive(); // Receive command

            switch (command) {
                case '1':
                    control_light(1); // Turn light on
                    break;
                case '0':
                    control_light(0); // Turn light off
                    break;
                case '2':
                    control_door(1); // Open door
                    break;
                case '3':
                    control_door(0); // Close door
                    break;
                default:
                	UART_TransmitString("Invalid Command\r\n");
                    break;
            }
       } else {
            attempts++;
            UART_TransmitString("Login Failed\r\n");

            if (attempts >= MAX_ATTEMPTS) {
                activate_alarm(); // Trigger alarm after max attempts
                attempts = 0; // Reset attempts after alarm
            }
        }
    }
}

void UART_ReceiveString(char *str, u8 max_length) {
    u8 i = 0;
    char ch;
    while (i < max_length - 1) {
        ch = UART_Receive(); // Read a character from UART
        if (ch == '\n' || ch == '\r') { // End of input
            break;
        }
        str[i++] = ch; // Store character
    }
    str[i] = '\0'; // Null-terminate the string
}

void uart_transmit(unsigned char data) {
    while (!(UCSRA & (1 << UDRE))); // Wait until buffer is empty
    UDR = data; // Send data
}

void uart_print(const char *str) {
    while (*str) {
        uart_transmit(*str++);
    }
}
void uart_print_number(uint16_t number) {
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%u", number);
    uart_print(buffer);
}


void pwm_init() {
    DDRD |= (1 << DDD7); // Set PD7 as output (OC2)
    TCCR2 = (1 << WGM20) | (1 << COM21) | (1 << CS20); // Fast PWM mode, non-inverted
    OCR2 = 0; // Set initial PWM duty cycle to 0%
}

void set_fan_speed(uint8_t speed) {
    OCR2 = speed; // Set the PWM duty cycle
    fan_speed = speed; // Update fan speed percentage
}

uint8_t map_adc_to_pwm(uint16_t adc_value) {
    return (uint8_t)((adc_value * 255) / 1023); // Map ADC value (0-1023) to PWM duty cycle (0-255)
}

