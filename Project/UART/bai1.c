// dung mode  0 de mo rong ngo ra voi 74hc595
#include <REGX52.H>
#include "../../Lib/delay.h"

void Uart_Mode0_Write(unsigned char b)
{
	//du lieu duoc truyen 
	SBUF = b;
	
	while(TI == 0);
	TI = 0;
	
	P3_2 = 0;
	P3_2 = 1;
}
void main()
{	
	unsigned char LED = 0x01;
	unsigned char i;
	//CHE DO 0
	SM0 = SM1 = 0;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{	
			LED = LED | 1 << i;
			Uart_Mode0_Write(LED);
			delay_ms(500);
		}	
		Uart_Mode0_Write(0);
	}
}