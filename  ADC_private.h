/*

 * ADC_private.h

 *

 *  Created on: Jul 31, 2024

 *      Author: eng_youssef_goher

 */



#ifndef MCAL_ADC_ADC_PRIVATE_H_

#define MCAL_ADC_ADC_PRIVATE_H_



typedef struct{ volatile u16  ADCD;

volatile u8  ADCSRA;

volatile u8  ADMUX;

volatile u8  ACSR;

}ADC_T;



enum {

ADEN=7,

ADSC=6,

ADATE=5,

ADIF=4,

ADIE=3,

ADPS2=2,

ADPS1=1,

ADPS0=0

};



enum{

REFS1=7,

REFS0=6,

ADLAR=5,

MUX4=4,

MUX3=3,

MUX2=2,

MUX1=1,

MUX0=0

};



enum{

ACD=7,

ACBG=6,

ACO=5,

ACI=4,

ACIE=3,

ACIC=2,

ACIS1=1,

ACIS0=0

};



#define ADC (*((volatile ADC_T *)0x24))



//Voltage Reference Selections

#define AREF 3

#define AVCC 4

#define INTERNAL2_56 8





//ADC Prescaler Selections

#define DIVISION_2 4

#define DIVISION_4 5

#define DIVISION_8 6

#define DIVISION_16 7

#define DIVISION_32 8

#define DIVISION_64 9

#define DIVISION_128 10



//ADC Left Adjust Result

#define ENABLE_LET_ADJUST 1

#define DISABLE_LET_ADJUST 3



#endif /* 03_MCAL_ADC_ADC_PRIVATE_H_ */
