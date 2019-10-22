#include "LSTD_TYPES.h"

#include "MGPIO_private.h"

#include "MGPIO_interface.h"

/*#include "MRCC_private.h"*/

void MGPIO_INITIALIZE(/*u8 PortNum,u8 PinNum,u8 Mode,u8 CNF*/void)
{

	/*USART1 already mapped on PA9(Tx)  , PA10 (Rx)as alternative functions
	 * we need to make these pins (PA9 as output alternative func push pull) and (PA10 as input pull-up)
	 * */
	GPIOA.CRL=0x00000002;
	GPIOA.CRH=0x000004A0;
	/*switch (PortNum)
	{
	case PORTA:
	{
		RCC.APB2ENR|=(1<<IOPAEN);
		switch (Mode)
		{
		case 0:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOA.CRL&=~(3<<(4*PinNum));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOA.CRH&=~(3<<(4*PinNum));
			}
			break;
		}
		default:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOA.CRL|=(Mode<<(4*PinNum));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOA.CRH|=(Mode<<(4*PinNum));
			}
			break;
		}
		}
		switch (CNF)
		{
		case 0:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOA.CRL&=~(3<<((4*PinNum)+2));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOA.CRH&=~(3<<((4*PinNum)+2));
			}
			break;
		}
		default:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOA.CRL|=(Mode<<((4*PinNum)+2));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOA.CRH|=(Mode<<((4*PinNum)+2));
			}
			break;
		}
		}
		break;
	}
	case PORTB:
	{
		RCC.APB2ENR|=(1<<IOPBEN);
		switch (Mode)
		{
		case 0:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOB.CRL&=~(3<<(4*PinNum));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOB.CRH&=~(3<<(4*PinNum));
			}
			break;
		}
		default:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOB.CRL|=(Mode<<(4*PinNum));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOB.CRH|=(Mode<<(4*PinNum));
			}
			break;
		}
		}
		switch (CNF)
		{
		case 0:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOB.CRL&=~(3<<((4*PinNum)+2));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOB.CRH&=~(3<<((4*PinNum)+2));
			}
			break;
		}
		default:
		{
			if(PinNum>=0&&PinNum<=7)
			{
				GPIOB.CRL|=(Mode<<((4*PinNum)+2));
			}
			else if(PinNum>=8&&PinNum<=15)
			{
				GPIOB.CRH|=(Mode<<((4*PinNum)+2));
			}
			break;
		}
		}
		break;
	}
	}*/
}

void MGPIO_SetPin(u8 Port ,u8 Pin)
{
	switch (Port)
	{
	case PORTA:GPIOA.BSRR=Pin;break;
	case PORTB:GPIOB.BSRR=Pin;break;
	case PORTC:GPIOC.BSRR=Pin;break;
	}
}

void MGPIO_ClearPin(u8 Port,u8 Pin)
{
	switch(Port)
	{
	case PORTA:GPIOA.BRR=Pin;break;
	case PORTB:GPIOB.BRR=Pin;break;
	case PORTC:GPIOC.BRR=Pin;break;
	}
}

void MGPIO_AssignPort(u8 Port,u16 Value)
{
	switch(Port)
	{
	case PORTA:GPIOA.ODR=Value;break;
	case PORTB:GPIOB.ODR=Value;break;
	case PORTC:GPIOC.ODR=Value;break;
	}
}
u8 MGPIO_GetPinValue(u8 Port, u8 Pin)
{
	u8 value;
	switch (Port)
	{
	case PORTA:value=(GPIOA.IDR&Pin);if(value)value=1;break;
	case PORTB:value=(GPIOB.IDR&Pin);if(value)value=1;break;
	}
	return value;
}


