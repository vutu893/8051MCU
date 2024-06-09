#include <REGX52.H>

void delay_ms_Timer0(unsigned char t)
{
	unsigned char cnt;
	do{
		TL0 = 0;
		TH0 = 0;
		TR0 = 0;
		do{
			cnt = TH0;
			cnt <<= 8;
			cnt |= TL0;
			
		}while(cnt <= 1000);
		//Timer 0 ngung dem
		TR0	= 0;
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