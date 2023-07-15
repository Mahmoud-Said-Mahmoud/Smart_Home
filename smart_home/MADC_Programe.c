/******************************************************/
/******************************************************/
/*** AUTHOR : MahmoudSAIDMAHMOUD   ********************/
/*** DATA : 21/10/2021             ********************/
/*** FILE_NAME :MADC_Private_H     ********************/
/*** VERSION : 1.0.0               ********************/
/*** DESCRIPTION : main             *******************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MADC_Private.h"
#include "MADC_Interface.h"

void MADC_voidInit(void)
{
	/*AVCC voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/* ACTIVE left adjust */
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/*Set Prescaler to divide by 128*/
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
	/*EN peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	
}
u16 MADC_ReadData(u8 Copy_u8Channel)
{
	/* Clear the mux bits in ADMUX register*/
	ADMUX &=0b11100000;
	/*Set the required channel into the MUX bits*/
	ADMUX|= Copy_u8Channel;
	/* Start conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Busy waiting */
	while ((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);
	/*clear flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*RETURN */
	return ADC_data;
	
}
