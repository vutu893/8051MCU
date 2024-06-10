#include <REGX52.H>

//ngat voi timer
//khi overflow thi se co mot interrup_request
//cau hinh trong thanh ghi IE: ET0 = 1
sbit LED = P2^1;
unsigned char cnt = 0;
void Timer0_delay_1s_ISR(void) interrupt 1
{
	TH0 = 0x3C;
	TL0 = 0xB0;
	
	cnt++;
	if(cnt >= 20)
	{
		LED = !LED;
		cnt = 0;
	}
}
void main()
{
	LED = 0;
	//cau hinh timer 0 mode 1
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	TH0 = 0x3C;
	TL0 = 0xB0;
	
	//cai dat ngat
	ET0 = 1;
	EA = 1;
	
	//chay timer
	TR0 = 1;
	while(1)
	{
		//vdk hoat dong che do ngu
		PCON |= 0x01;
	}
}
