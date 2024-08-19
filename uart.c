/*
 * uart.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Mariam
 */

#include "LBIT_math.h"
#include "LSTD_types.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void UART_Ini()
{
	u8 Local_Temp=0;
	/******   Enable Rx Interrupt (RXCIE)   *******/
	SET_BIT(UCSRB,RXCIE);
	/******   Enable UDRIE          *******/
	SET_BIT(UCSRB,UDRIE);

	/******   Select 8-BIT Data *********/
	CLR_BIT(UCSRB,UCSZ2);
	/*select UCSRC Register*/
	SET_BIT(Local_Temp,URSEL);
	SET_BIT(Local_Temp,UCSZ0);
	SET_BIT(Local_Temp,UCSZ1);
	/******  Select UART Mode *********/
	CLR_BIT(Local_Temp,UMSEL);//select  Asynchronous Mode
	/******   Select Parity Mode *********/
	CLR_BIT(Local_Temp,UPM0);//disable Parity
	CLR_BIT(Local_Temp,UPM1);
	/******   Select Stop bit *********/
	CLR_BIT(Local_Temp,USBS);

	UCSRC=Local_Temp;

	/******   Select BuadRate *********/
	UBRRL=51;
	/******   Enable Rx *********/
	SET_BIT(UCSRB,RXEN);
	/******   Enable Tx *********/
	SET_BIT(UCSRB,TXEN);

}

void UART_Transmit(u8 data){
	while(GET_BIT(UCSRA,UDRE)==0);// If UDRE is one, the buffer is empty, and therefore ready to be written.
	SET_BIT(UCSRA,UDRE);
	UDR=data;
	while(GET_BIT(UCSRA,TXC)==0);//This flag bit is set when the entire frame in the transmit Shift Register has been shifted out and
	SET_BIT(UCSRA,TXC);
	//there are no new data currently present in the transmit buffer (UDR).
}
u8 	UART_Receive(void){
	while(GET_BIT(UCSRA,RXC)==0);//This flag bit is set when there are unread data in the receive buffer and cleared when the receive
	SET_BIT(UCSRA,RXC);
	//buffer is empty (that is, does not contain any unread data)
	return UDR;
}

void UART_TransmitString(u8* ptr_u8Data){
	u32 local_u32Counter=0;
	for(local_u32Counter=0;ptr_u8Data[local_u32Counter]!='\0';local_u32Counter++){
		UART_Transmit(ptr_u8Data[local_u32Counter]);
	}
}
