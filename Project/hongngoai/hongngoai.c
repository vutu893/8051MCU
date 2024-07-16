#include <REGX52.H>
#include "delay.h"
void main()
{
	T2CON = 0x00;
	T2MOD = 0x02;
	
	RCAP2H = 0xFF;
	RCAP2L = 0xB1;
	
	TH2 = 0xFF;
	TL2 = 0xB1;
	
	TR2 = 1;
	
	while(1)
	{
		
	}
}
