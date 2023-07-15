/*
 * Smart_Home.c
 *
 *  Created on: Nov 17, 2021
 *      Author: team work
 */
#include "STD_TYPES.h"
#include "MDIO_INTERFACE.h"
#include "HLCD_Interface.h"
#include "MURT_Interface.h"
#include "MTimer_Interface.h"
#include "MADC_Interface.h"
#include "Smart_Home_Private.h"
#include <avr/delay.h>
u8 Login_Trial=False;
u8 Door_State=Closed;
u8 Login_state=OUT;
u8 Data=0;
int main(void)
{
	/*bigger Loop*/
	while(1)
	{
		/*Login */
		while(!Login_Trial)
		{

			/*Password & ID */
			u8 *IDTrue[3]={0};
			u8 *PassTrue[3]={0};

			/*Init */
			URT_Init();
			HLCD_VoidInit();
			MADC_voidInit();
			/*TIM0 Init*/
			TIM0_Init();
			u8 ID=0;
			u8 Pass=0;

			/*Password Check */
			void Pass_Check(void)
			{
				Pass=0;

				HLCD_VoidSendCommand(0x01);
				HLCD_VoidSetPostion(0,0);
				HLCD_VoidSendString("Password:");
				for(u8 i=0;i<=3;i++)
				{
					/*Get Password From User*/
					Pass=URT_Recevier();
					URT_Transmitte(PassTrue[i]);
					/*Display Password On LCD*/
					HLCD_VoidSendChar('*');
					/*Store Password In Array*/
					PassTrue[i]=Pass;
				}
			}



			/*ID Check Function*/
			void ID_CHECK(void)
			{
				ID=0;
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidSetPostion(0,0);
				HLCD_VoidSendString("ID:");
				for(u8 i=0;i<=3;i++)
				{
					/*Get ID From User*/
					ID=URT_Recevier();
					URT_Transmitte(IDTrue[i]);
					/*Display ID On LCD*/
					HLCD_VoidSendChar(ID);
					/*Store ID In Array*/
					IDTrue[i]=ID;
				}
			}



			/*Go To ID Check Function*/

			u8 Pas=0;
			/* bigger loop id check  */
			for(u8 y=0;y<3;y++)
			{
				/*If Correct ID*/
				if(IDTrue[0]=='3'&&IDTrue[1]=='0'&&IDTrue[2]=='0'&&IDTrue[3]=='0')
				{
					y=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					/*Go To Pass Check Function*/
					Pass_Check();

					for(Pas=0;Pas<2;Pas++)
					{
						/*If Correct Password*/
						if(PassTrue[0]=='1'&&PassTrue[1]=='0'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
						{
							Login_Trial=True;
							Pas=3; //For Exit For Loop
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSetPostion(0,6);
							HLCD_VoidSendString("Hello");
							Login_state=IN;
						}

						/*If Incorrect Password*/
						else if(Pas<2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass Try Again");
							_delay_ms(1000);
							/*Go To Pass Check Function*/
							Pass_Check();
						}
						/*If Incorrect Password*/
						else if(Pas==2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass ");
							_delay_ms(1000);
						}
					}
				}




				/*get secound user */
				else if(IDTrue[0]=='2'&&IDTrue[1]=='0'&&IDTrue[2]=='0'&&IDTrue[3]=='0')
				{
					y=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					/*Go To Pass Check Function*/
					Pass_Check();

					for(Pas=0;Pas<2;Pas++)
					{
						/*If Correct Password*/
						if(PassTrue[0]=='5'&&PassTrue[1]=='0'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
						{
							Login_Trial=True;
							Pas=2; //For Exit For Loop
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSetPostion(0,6);
							HLCD_VoidSendString("HELLO");
							Login_state=IN;
						}
						/*If Incorrect Password*/
						else if(Pas<2)
						{
							HLCD_VoidSendCommand(0x01);
							//HLCD_VoidSendString("Wrong Pass Try Again");
							_delay_ms(1000);
							/*Go To Pass Check Function*/
							Pass_Check();
						}
						/*If Incorrect Password*/
						else if(Pas==2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass ");
							_delay_ms(1000);
						}
					}
				}






				/*get third user */
				else if(IDTrue[0]=='6'&&IDTrue[1]=='0'&&IDTrue[2]=='0'&&IDTrue[3]=='0')
				{
					y=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					/*Go To Pass Check Function*/
					Pass_Check();

					for(Pas=0;Pas<2;Pas++)
					{
						/*If Correct Password*/
						if(PassTrue[0]=='8'&&PassTrue[1]=='0'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
						{
							Login_Trial=True;
							Pas=2; //For Exit For Loop
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSetPostion(0,4);
							HLCD_VoidSendString("HELLO");
							Login_state=IN;
						}
						/*If Incorrect Password*/
						else if(Pas<2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass Try Again");
							_delay_ms(1000);
							/*Go To Pass Check Function*/
							Pass_Check();
						}
						/*If Incorrect Password*/
						else if(Pas==2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass ");
							_delay_ms(1000);

						}
					}
				}




				/* get 4 user  by using voice application */
				else if(IDTrue[0]=='u'&&IDTrue[1]=='s'&&IDTrue[2]=='e'&&IDTrue[3]=='r')
				{
					y=4; //For Exit For Loop
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					/*Go To Pass Check Function*/
					Pass_Check();

					for(Pas=0;Pas<2;Pas++)
					{
						/*If Correct Password*/
						if(PassTrue[0]=='8'&&PassTrue[1]=='0'&&PassTrue[2]=='0'&&PassTrue[3]=='0')
						{
							Login_Trial=True;
							Pas=2; //For Exit For Loop
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSetPostion(0,4);
							HLCD_VoidSendString("HELLO");
							Login_state=IN;
						}
						/*If Incorrect Password*/
						else if(Pas<2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass Try Again");
							_delay_ms(1000);
							/*Go To Pass Check Function*/
							Pass_Check();
						}
						/*If Incorrect Password*/
						else if(Pas==2)
						{
							HLCD_VoidSendCommand(0x01);
							HLCD_VoidSendString("Wrong Pass ");
							_delay_ms(1000);

						}
					}
				}




				/*If Incorrect ID*/
				else if(y<3)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong ID Try Again");
					_delay_ms(1000);
					/*Go To ID Check Function*/
					ID_CHECK();
				}
				/*If Incorrect ID*/
				if(y==2)
				{
					Login_Trial=True;
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSendString("Wrong ID ");
					_delay_ms(1000);
				}
			}
		} /*end Login loop*/


		/* ID & Password Correct*/
		while(Login_state)
		{
			/*Display Options On LCD*/

			_delay_ms(2000);
			HLCD_VoidSendCommand(0x01);
			HLCD_VoidSetPostion(0,0);
			HLCD_VoidSendString("1:O/D");
			HLCD_VoidSetPostion(0,7);
			HLCD_VoidSendString("2:C/D");
			HLCD_VoidSetPostion(1,0);
			HLCD_VoidSendString("3:Temp");
			HLCD_VoidSetPostion(1,7);
			HLCD_VoidSendString("4:LED");
			HLCD_VoidSetPostion(1,13);
			HLCD_VoidSendString("5:0");



			Data=URT_Recevier();
			if(Data=='1')
			{
				if(Door_State==Closed)
				{
					MDIO_VoidSetPinDirection(PORTB,3,OUTPUT);
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					HLCD_VoidSendString("Open Door");
					TIM0_FastPWM_Set_DutyCycle(13);
					Door_State=Open;

				}
				else if(Door_State==Open)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					HLCD_VoidSendString("Door Already Open");
				}

			}

			else if(Data=='2')
			{
				if(Door_State==Open)
				{
					MDIO_VoidSetPinDirection(PORTB,3,OUTPUT);
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,0);
					HLCD_VoidSendString("Close Door");
					TIM0_FastPWM_Set_DutyCycle(75);
					Door_State=Closed;
				}
				else if(Door_State==Closed)
				{
					HLCD_VoidSendCommand(0x01);
					HLCD_VoidSetPostion(0,2);
					HLCD_VoidSendString("Door Already ");
					HLCD_VoidSetPostion(1,5);
					HLCD_VoidSendString(" Closed");
				}


			}
			else if(Data=='3')
			{
				HLCD_VoidSendCommand(0x01);
				u16 Digital=0,milivolt=0,temp=0;
				Digital= MADC_ReadData(0);
				milivolt=(Digital*5000)/256;
				temp=milivolt/10;
				HLCD_VoidSetPostion(0,0);
				HLCD_VoidSendString("Temp:");
				HLCD_VoidSendNumber(temp);
				HLCD_VoidSendString("C");
				_delay_ms(3000);


			}


			else if(Data=='4')
			{
				HLCD_VoidSendCommand(0x01);//
				MDIO_VoidSetPinDirection(PORTA,PIN1,OUTPUT);
				MDIO_VoidTogglePin(PORTA,PIN1);
				HLCD_VoidSetPostion(0,0);
				HLCD_VoidSendString("LED:ON/Off");

			}


			else if(Data=='5')
			{
				Login_state=OUT;
				Login_Trial=False;

			}

		} //End Program

	} /*End bigger Loop*/
	return 0;
} //End Main
