#include "LSTD_TYPES.h"

#include "MRCC_private.h"

#include "MRCC_interface.h"



void MRCC_Initialize(void)
{
//	RCC.CR	  = 0x00010000;
//	RCC.CFGR  = 0x00000001;
	RCC.CR	  = 0x00010001;/*Enable HSE and HSI*/

	while( (RCC.CR & 0x2) != 2);/*Wait till HSI is ready*/

	RCC.CFGR  = 0x00000001;/*Choose HSE as the SYSCLK*/

	RCC.CR   &= ~(0xFFFFFFFE);/*Enable only HSI*/

	RCC.CFGR    = 0x00230402;/*HSE = 8MHZ , PLL source = HSE/2 = 4MHZ , PLL mul = 4x10 = 40MHZ*/
							 /*AHB = 40MHZ , APB2 = 40MHZ , APB1 = 20MHZ*/

	RCC.CR    = 0x01000001;	/*Enable PLL and HSI*/

	while (( (RCC.CR & 0x02000000) != 0) && ((RCC.CR & 0x2) != 2));

	RCC.CFGR    = 0x003F0402;/*HSE = 8MHZ , PLL source = HSE/2 = 4MHZ , PLL mul = 4x10 = 40MHZ*/
							 /*AHB = 40MHZ , APB2 = 40MHZ , APB1 = 20MHZ*/

	while ((RCC.CFGR & 0x8)!=8);
}


void MRCC_EnableClock(u8 Bus,u32 Peripheral)
{
	switch(Bus)
	{
	case BUS_AHB:RCC.AHBENR|=Peripheral;break;
	case BUS_APB1:RCC.APB1ENR|=Peripheral;break;
	case BUS_APB2:RCC.APB2ENR|=Peripheral;break;
	}
}

void MRCC_DisableClock(u8 Bus,u8 Peripheral)
{
	switch(Bus)
	{
	case BUS_AHB :	RCC.AHBENR	 &=~Peripheral;	break;
	case BUS_APB1:	RCC.APB1ENR	 &=~Peripheral;	break;
	case BUS_APB2:	RCC.APB2ENR	 &=~Peripheral;	break;
	}
}
