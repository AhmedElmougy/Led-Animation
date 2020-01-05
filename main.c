/*
 * File        : main.c
 * Description : This file is application main file that contains code for displaying
 *               led animation using Atmega32 DIO and LED Drivers
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#define F_CPU 8000000

#include "LUTILS.h"
#include "LSTD_Types.h"
#include "MDIO_Interface.h"
#include "HLED_Interface.h"
#include <util/delay.h>

int main(void)
{
	/*initialize led string off*/
	HLED_u8InitLedString(MDIO_PORTA);
	HLED_u8LedStringOnOff(MDIO_PORTA,HLED_OFF);
	
	/*while loop*/
	while (1)
	{
		
		/*first animation*/
		for (u8 i=0;i<8;i++)
		{
			HLED_u8LedOnOff(MDIO_PORTA,i,HLED_ON);
			_delay_ms(500);
			HLED_u8LedOnOff(MDIO_PORTA,i,HLED_OFF);
			_delay_ms(50);
		}
		
		/*turn all string on for a second then turn it off*/
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_ON);
		_delay_ms(1000);
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_OFF);
		_delay_ms(50);
		
		
		
		/*Second animation*/
		u8 string = 129;  
		for (u8 i=0;i<8;i++)
		{
			HLED_u8LedStringOnOff( MDIO_PORTA, ((string>>i) | (string<<i)) );
			_delay_ms(500);
		}
		
		/*turn all string on for a second then turn it off*/
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_ON);
		_delay_ms(1000);
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_OFF);
		_delay_ms(50);		
		
		/*Third animation*/
		string = 102;
		for (u8 i=0;i<8;i++)
		{
			HLED_u8LedStringOnOff( MDIO_PORTA, ((string>>i) | (string<<i)) );
			_delay_ms(500);
		}
		
		/*turn all string on for a second then turn it off*/
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_ON);
		_delay_ms(1000);
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_OFF);
		_delay_ms(50);
		
		/*4th animation*/
		string = 153;
		for (u8 i=0;i<8;i++)
		{
			HLED_u8LedStringOnOff( MDIO_PORTA, ((string>>i) | (string<<i)) );
			_delay_ms(500);
		}
		
		/*turn all string on for a second then turn it off*/
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_ON);
		_delay_ms(1000);
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_OFF);
		_delay_ms(50);
		
		/*5th animation*/
		for (u8 i=0;i<4;i++)
		{
			HLED_u8LedStringOnOff( MDIO_PORTA,0xAA);
			_delay_ms(500);
			HLED_u8LedStringOnOff( MDIO_PORTA,0x55);
			_delay_ms(500);
		}
		
		/*turn all string on for a second then turn it off*/
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_ON);
		_delay_ms(1000);
		HLED_u8LedStringOnOff(MDIO_PORTA,HLED_OFF);
		_delay_ms(50);
		
	}/*End of while loop*/
}

