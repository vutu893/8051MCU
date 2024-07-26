#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_4.h"

void ADC0808_Init();
unsigned char ADC0808_Read();
void main()
{
	unsigned char value_adc;
	unsigned int voltage;
	
	while(1)
	{
		value_adc = ADC0809_Read();
		
		
		
		voltage = value_adc * 19.61f;
		
		
		
		
		delay_ms(500);
	}
}
void ADC0808_Init()
{

}
unsigned char ADC0808_Read()
{

}
