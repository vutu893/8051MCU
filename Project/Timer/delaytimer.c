#include <REGX52.H>

void delay_ms_Timer0(unsigned char t)
{
	unsigned char cnt;
	do{
		//dem tu 65413 cho den luc tran
		TL0 = 0x18;
		TH0 = 0xFC;
		TR0 = 1;
		//DUNG CO TRAN CUA TIMER
		while(!TF0);
		//Timer 0 ngung dem
		TR0	= 0;
		TF0 = 0;
		t--;
	}while(t!=0)
}
void main()
{
	//chon mode cho timer 0
	TMOD &= 0xF0;
	
	//chon che do mode 1 cho timer
	TMOD |= 0x01;
	while(1)
	{
	
	}
}