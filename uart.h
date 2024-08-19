/*
 * uart.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Mariam
 */

#ifndef UART_H_
#define UART_H_

void UART_Ini();

void UART_Transmit(u8 data);
u8 	UART_Receive(void);

void UART_TransmitString(u8* ptr_u8Data);

void UART_ReceiveString(char *str, u8 max_length);





#endif /* UART_H_ */
