/*
 * ADC_config.h
 *
 *  Created on: Aug 1, 2024
 *      Author: hp
 */





#ifndef MCAL_ADC_ADC_CONFIG_H_

#define MCAL_ADC_ADC_CONFIG_H_



//Voltage Reference Selections

/*

 * AREF -> pin on microcontroler "Aref" Internal Vref turned off

 * AVCC -> AVCC with external capacitor at AREF pin

 * INTERNAL2_56 -> nternal 2.56V Voltage Reference with external capacitor at AREF pin

 *

 */

#define VOLTAGE_REFERENCE AVCC



//ADC Prescaler Selections

/*

 * DIVISION_2

 * DIVISION_4

 * DIVISION_8

 * DIVISION_16

 * DIVISION_32

 * DIVISION_64

 * DIVISION_128

 *

 */



#define ADC_PRESCALER  DIVISION_64



//ADC Left Adjust Result

/*

 * ENABLE_LET_ADJUST

 * DISABLE_LET_ADJUST

 *

 */

#define ADC_LEFT_ADJUST DISABLE_LET_ADJUST





#endif /* 03_MCAL_ADC_ADC_CONFIG_H_ */

