/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "LSTD_TYPES.h"
#include "MAFIO_interface.h"
#include "MGPIO_interface.h"
#include "MRCC_interface.h"
#include "MUART_interface.h"

u8 x=3;

void main(void)
{

	MRCC_Initialize();
	MRCC_EnableClock(BUS_APB2,PERIPHERAL_GPIOA);
	MRCC_EnableClock(BUS_APB2,PERIPHERAL_USART1);



	MGPIO_INITIALIZE();
	MUSART1_Initialize();
	while(1)
	{
		MUSART1_Transmit("97");
	/*	x = MUSART1_Receive();
		if(x=='1')
		{
			MGPIO_SetPin(PORTA,Pin0);
		}
		else if(x=='0')
		{
			MGPIO_ClearPin(PORTA,Pin0);
		}

*/
	}
}

