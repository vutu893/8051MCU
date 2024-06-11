#include <REGX52.H>

//dung timer2 o che do 16bit tu dong nap lai
//RCAP2H, RCAP2L la hai thang ghi dung de nap lai cho TH2, TL2
//ham delay bang timer2
void Delay_Timer2_1s()
{
	unsigned char i;
	
	TR2 = 1;//bat dau dem
	for(i = 0; i < 20; i++)
	{
		while(!TF2);
		TF2 = 0;
	}
	TR2 = 0;
}
void main()
{
	//cau hinh timer 2 tu dong nap lai, mode 16bit
	T2CON = 0x00;
	T2MOD = 0x00;
	
	RCAP2H = 0x3C;
	RCAP2L = 0xB0;
	
	TH2 = 0x3C;
	TL2 = 0xB0;
	
	while(1)
	{
	
	}
}