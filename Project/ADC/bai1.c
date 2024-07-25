#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_4.h"

sbit ADC_PIN = P3^0;
unsigned char read_ADC();
void main()
{	
	unsigned char value_adc;
	unsigned int voltage;
	Lcd_Init();
	while(1)
	{
		value_adc = read_ADC();
		voltage = value_adc * 1.953125f;
		
		Lcd_Chr(1, 1, value_adc /100 + 0x30);
		Lcd_Chr_Cp(value_adc%100/10 + 0x30);
		Lcd_Chr_Cp(value_adc%10 + 0x30);
		
		Lcd_Chr(2, 1, voltage/100 + 0x30);
		Lcd_Chr_Cd(46);
		Lcd_Chr_Cd(voltage%100/10 + 0x30);
		Lcd_Chr_Cd(voltage%10 + 0x30);
		
		delay_ms(500);
	}
}

unsigned char read_ADC()
{	
	P2 = 255;
	while(P3^0 != 0)
	{
		P2--;
		if(P2 == 0) break;
	}
	return P2;
}
