/*

 * ADC_interface.h

 *

 *  Created on: Jul 31, 2024

 *      Author: eng_youssef_goher

 */



#ifndef MCAL_ADC_ADC_INTERFACE_H_

#define MCAL_ADC_ADC_INTERFACE_H_



typedef enum{

ADC0,

ADC1,

ADC2,

ADC3,

ADC4,

ADC5,

ADC6,

ADC7,

ADC1_ADC2,

ADC2_ADC1

}Channel_T;



void ADC_voidini(void);

void ADC_voidEnable(void);

void ADC_voidDisable(void);

u16  ADC_u16Conversion(Channel_T copy_Channel_TMode);



#endif /* 03_MCAL_ADC_ADC_INTERFACE_H_ */
