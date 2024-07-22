#include <REGX52.H>

//tao xung PWM bang phan mem : dung ngat timer 0 de tao xung PWM  tren chan P2.0.Timer 0 hoat dong o che do dinh thoi 16bit
// do dao dong la 12MHz nen tan so clock cho timer 0 la 1MHz

sbit PWM_PIN = P2^0;

unsigned int T, Ton, Toff;
unsigned char Ton_high_reload, Ton_low_reload, Toff_high_reload, Toff_low_reload;

void PWM_Init(unsigned int ck)
{
	PWM_PIN = 1;
	
	TMOD &= 0xF0; //Xoa di cac b chon mode cua timer0
	TMOD != 0x01;	// Timer0 hoat dong o mode1
	
	ET0 = 1;	//Cho phep ngat Timer0	
	EA = 1;	//Cho phep ngat toan cuc
	
	T = ck;
	Ton = T / 2; //duty cycle = 50%
	Toff = T /2;
	
	
	Ton_high_reload = (65536 - Ton)>>8;
	Ton_low_reload = (65536 - Ton)&0x00FF;
	Toff_high_reload = (65536 - Toff)>>8;
	Toff_low_reload = (65536 - Toff)&0x00FF;
	TH0 = Ton_high_reload;
	TL0 =  Ton_low_reload;
}

void PWM_Start()
{
	TR0 = 1; //cho phep timer0 bat dau dem
	
}

void PWM_Stop()
{
	TR0 = 0;
}

void set_PWM(unsigned char duty)
{
	//hai truong hop dac biet khi duty = 0 hoac duty = 100
	if(duty ==0)
	{
		PWM_PIN = 0;
		ET0 = 0;
	}else if(duty == 100)
	{
		PWM_PIN = 1;
		ET0 =0;
	}else
	{
		Ton = ((unsigned long)T)*duty /100;
		Toff = T-Ton;
		Ton_high_reload = (65536 - Ton)>>8;
		Ton_low_reload = (65536 - Ton)&0x00FF;
		Toff_high_reload = (65536 - Toff)>>8;
		Toff_low_reload = (65536 - Toff)&0x00FF;
		
		ET0 = 1;
	}
}
void main()
{	
	PWM_Init(1000); //tao xung PWM co chu ki T = 1000 us
	set_PWM(70); //duty cycle = 70%
	PWM_Start();
	while(1)
	{
	
	}
}

void Timer0Overflow() interrupt 1
{
	PWM_PIN = !PWM_PIN;
	if(PWM_PIN == 0)
	{
		TH0 = Toff_high_reload;
		TL0 = Toff_low_reload;
	}else
	{
		TH0 = Ton_high_reload;
		TL0 = Ton_low_reload;
	}
}