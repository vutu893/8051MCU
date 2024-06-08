#include <REGX52.H>
#include "port.h"
#include "../../Lib/delay.h"
void main()
{	
	//khai bao ngat canh xuong
	IT1 = 1;
	
	//cho phep ngat
	EX1 = 1;
	
	//ngat toan cuc
	EA = 1;
	
	LED1 = LED2 = LED3 = LED4 = 0;
	while(1)
	{
		PCON |= 0x01;
	}
}

void EX1_ISR(void) interrupt 2
{
	//button 1 and led 1
	delay_ms(20);
	if(!BTN1)
	{
		LED1 = !LED1;
		while(!BTN1);
	}
	
	if(!BTN2)
	{
		LED2 = !LED2;
		while(!BTN2);
	}
	if(!BTN3)
	{
		LED3 = !LED3;
		while(!BTN3);
	}
	if(!BTN4)
	{
		LED4 = !LED4;
		while(!BTN4);
	}
}