/******************************************************/
/******************************************************/
/*** AUTHOR : MahmoudSAIDMAHMOUD   ********************/
/*** DATA : 21/10/2021             ********************/
/*** FILE_NAME :MADC_Private_H     ********************/
/*** VERSION : 1.0.0               ********************/
/*** DESCRIPTION : DEFINE REGISTERS *******************/
/******************************************************/
/******************************************************/

#ifndef  MADC_Private_H
#define  MADC_Private_H
//ADC multiplexer selection register 
#define   ADMUX        *((volatile u8*)0x27)


#define   ADMUX_REFS1    7     		// Refrence selection bit 1
#define   ADMUX_REFS0    6			// Refrence selection bit 0
#define   ADMUX_ADLAR    5			// ADC Left adjust result

// ADC control and status register A 
#define   ADCSRA       *((volatile u8*)0x26)

#define   ADCSRA_ADEN	7				// ADC enable
#define   ADCSRA_ADSC   6 				// start conversion 
#define   ADCSRA_ADATE  5				// Auto trigger enable
#define   ADCSRA_ADIF   4				//Interrupt flag 
#define   ADCSRA_ADIE   3				// Interrupt enable
#define   ADCSRA_ADPS2  2				// Prescaler bit 2
#define   ADCSRA_ADPS1  1				// Prescaler bit 1
#define   ADCSRA_ADPS0  0				// Prescaler bit 0

#define ADC_data       *((volatile u16*)0x24)
//#define   ADCH         *((volatile u8*)0x25)   //ADC high register
//#define   ADCL         *((volatile u8*)0x24)   //ADC low  register
#endif


