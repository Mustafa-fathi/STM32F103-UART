#ifndef MAFAIO_PRIVATE_H
#define MAFAIO_PRIVATE_H

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 MAPR2;
}MAFIO_Type;


#define MAFIO ((volatile MAFIO_Type*)0x40010000)




#endif