#ifndef MUART_INTERFACE_H
#define MUART_INTERFACE_H


void MUSART1_Initialize(void);
void MUSART1_Transmit(u8 arr[]);
u8 MUSART1_Receive(void);




#endif
