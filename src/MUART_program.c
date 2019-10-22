#include "LSTD_TYPES.h"

#include "MUART_private.h"

#include "MUART_interface.h"


void MUSART1_Initialize(void)
{
	(MUSART1 -> BRR) =0x156;
	(MUSART1 -> CR1) =0x00002000;
	(MUSART1 -> CR1) |=(3<<2);
	(MUSART1 -> SR)	 =0;
}


void MUSART1_Transmit(u8 arr[])
{
	u8 i=0;
	while(arr[i]!='\0')
	{
	(MUSART1 -> DR) = arr[i];
	while(((MUSART1 -> SR)&(MUART_TC_BIT))==0);
	i++;
	}
}


u8 MUSART1_Receive(void)
{
	while(((MUSART1 -> SR)&(1<<5))==0);
	return ((0xFF) & (MUSART1 -> DR));
}
