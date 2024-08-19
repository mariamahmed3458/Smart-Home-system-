/*

 * ADC_program.c

 *

 *  Created on: Jul 31, 2024

 *      Author: eng_youssef_goher

 */

#include "LSTD_types.h"

#include "LBIT_math.h"



#include " ADC_private.h"

#include "ADC_config.h"

#include "ADC_interface.h"





void ADC_voidini(void){

//Voltage Reference Selections

#if (VOLTAGE_REFERENCE == AVCC)

CLR_BIT(ADC.ADMUX,REFS1);

SET_BIT(ADC.ADMUX,REFS0);



#elif (VOLTAGE_REFERENCE == AREF)

CLR_BIT(ADC.ADMUX,REFS1);

CLR_BIT(ADC.ADMUX,REFS0);

#elif (VOLTAGE_REFERENCE == INTERNAL2_56)

SET_BIT(ADC.ADMUX,REFS1);

SET_BIT(ADC.ADMUX,REFS0);

#else

#error "you dont select option for Voltage Reference"

#endif

//ADC Prescaler Selections

#if (ADC_PRESCALER==DIVISION_2)

CLR_BIT(ADC.ADCSRA,ADPS0);

CLR_BIT(ADC.ADCSRA,ADPS1);

CLR_BIT(ADC.ADCSRA,ADPS2);

#elif (ADC_PRESCALER==DIVISION_4)

CLR_BIT(ADC.ADCSRA,ADPS0);

SET_BIT(ADC.ADCSRA,ADPS1);

CLR_BIT(ADC.ADCSRA,ADPS2);

#elif (ADC_PRESCALER==DIVISION_8)

SET_BIT(ADC.ADCSRA,ADPS0);

SET_BIT(ADC.ADCSRA,ADPS1);

CLR_BIT(ADC.ADCSRA,ADPS2);

#elif (ADC_PRESCALER==DIVISION_16)

CLR_BIT(ADC.ADCSRA,ADPS0);

CLR_BIT(ADC.ADCSRA,ADPS1);

SET_BIT(ADC.ADCSRA,ADPS2);

#elif (ADC_PRESCALER==DIVISION_32)

SET_BIT(ADC.ADCSRA,ADPS0);

CLR_BIT(ADC.ADCSRA,ADPS1);

SET_BIT(ADC.ADCSRA,ADPS2);

#elif (ADC_PRESCALER==DIVISION_64)

CLR_BIT(ADC.ADCSRA,ADPS0);

SET_BIT(ADC.ADCSRA,ADPS1);

SET_BIT(ADC.ADCSRA,ADPS2);

#elif (ADC_PRESCALER==DIVISION_128)

SET_BIT(ADC.ADCSRA,ADPS0);

SET_BIT(ADC.ADCSRA,ADPS1);

SET_BIT(ADC.ADCSRA,ADPS2);

#else

#error "you dont select option for ADC Prescaler"

#endif

//ADC Left Adjust Result

#if ADC_LEFT_ADJUST==ENABLE_LET_ADJUST

SET_BIT(ADC.ADMUX, ADLAR);

#elif (ADC_LEFT_ADJUST == DISABLE_LET_ADJUST)

CLR_BIT(ADC.ADMUX, ADLAR);

#else

#error "you dont select option for ADC Left Adjust Result"

#endif

}

void ADC_voidEnable(void){

SET_BIT(ADC.ADCSRA,ADEN);

}

void ADC_voidDisable(void){

CLR_BIT(ADC.ADCSRA,ADEN);

}

u16  ADC_u16Conversion(Channel_T copy_Channel_TMode){

switch(copy_Channel_TMode){

case ADC0:

CLR_BIT(ADC.ADMUX,MUX0);

CLR_BIT(ADC.ADMUX,MUX1);

CLR_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC1:

SET_BIT(ADC.ADMUX,MUX0);

CLR_BIT(ADC.ADMUX,MUX1);

CLR_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC2:

CLR_BIT(ADC.ADMUX,MUX0);

SET_BIT(ADC.ADMUX,MUX1);

CLR_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC3:

SET_BIT(ADC.ADMUX,MUX0);

SET_BIT(ADC.ADMUX,MUX1);

CLR_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC4:

CLR_BIT(ADC.ADMUX,MUX0);

CLR_BIT(ADC.ADMUX,MUX1);

SET_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC5:

SET_BIT(ADC.ADMUX,MUX0);

CLR_BIT(ADC.ADMUX,MUX1);

SET_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC6:

CLR_BIT(ADC.ADMUX,MUX0);

SET_BIT(ADC.ADMUX,MUX1);

SET_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC7:

SET_BIT(ADC.ADMUX,MUX0);

SET_BIT(ADC.ADMUX,MUX1);

SET_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

CLR_BIT(ADC.ADMUX,MUX4);

break;

case ADC1_ADC2:

SET_BIT(ADC.ADMUX,MUX0);

CLR_BIT(ADC.ADMUX,MUX1);

CLR_BIT(ADC.ADMUX,MUX2);

SET_BIT(ADC.ADMUX,MUX3);

SET_BIT(ADC.ADMUX,MUX4);

break;

case ADC2_ADC1:

CLR_BIT(ADC.ADMUX,MUX0);

SET_BIT(ADC.ADMUX,MUX1);

CLR_BIT(ADC.ADMUX,MUX2);

CLR_BIT(ADC.ADMUX,MUX3);

SET_BIT(ADC.ADMUX,MUX4);

break;

default:

break;

}

SET_BIT(ADC.ADCSRA,ADSC);

while(GET_BIT(ADC.ADCSRA, ADIF)==0);

SET_BIT(ADC.ADCSRA, ADIF);

return (ADC.ADCD);

}
