// dung PWM dieu khien do sang cua led
#include <REGX52.H>
#include "../../Lib/delay.h"

sbit PWM_PIN = P2^0;

unsigned int T, Ton, Toff;

unsigned char UP = 1 ;
unsigned char DOWN = 0;
unsigned char duty_current = 0;

unsigned char Ton_high_reload, Ton_low_reload, Toff_high_reload, Toff_low_reload;
void PWM_Init(unsigned int ck)
{
	PWM_PIN = 1;
	
	TMOD &= 0xF0;
	TMOD != 0x01;
	
	ET0 = 1;
	EA = 1;
	
	T = ck;
	Ton = T/2;
	Toff = T - Ton;
	
	Ton_high_reload = (65536 - Ton)>>8;
	Ton_low_reload = (65536 - Ton)&0x00FF;
	Toff_high_reload = (65536 - Toff)>>8;
	Toff_low_reload = (65536 - Toff)&0x00FF;
	TH0 = Ton_high_reload;
	TL0 =  Ton_low_reload;
}

void PWM_Start()
{
	TR0 = 1;
}
void PWM_Stop()
{
	TR0 = 0;
}

void set_PWM(unsigned char duty)
{
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
	unsigned char dir = UP;
	PWM_Init(1000);
	set_PWM(0);
	PWM_Start();
	while(1)
	{
		delay_ms(100);
		if(dir == UP)
		{
			duty_current += 2;
			if(duty_current == 100)
			{
				dir = DOWN;
			}
		}else
		{
			duty_current -= 2;
			if(duty_current == 0)
			{
				dir = UP;
			}
		}
		set_PWM(duty_current);
	}
}
void Timer0Overflow() interrupt 1
{
	PWM_PIN = !PWM_PIN;
	if(PWM_PIN ==0)
	{
		TH0 = Toff_high_reload;
		TL0 = Toff_low_reload;
	}else
	{
		TH0 = Ton_high_reload;
		TL0 = Ton_low_reload;
	}
}
