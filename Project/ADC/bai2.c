#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_8.h"
#include "port.h"
#include "../../Lib/ADC0804.h"

void main()
{	
	unsigned char value_digital;
	unsigned int voltage;
	
	
	//Use LCD to display result implemenr
	lcd_init();
	while(1)
	{
		value_digital = ADC0804_Read();
		
		lcd_pos_char(1, 1, value_digital /100 + 0x30);
		lcd_out_char(value_digital %100/10 + 0x30);
		lcd_out_char(value_digital %10 + 0x30);
		
		voltage = value_digital * 19.61f;
		
		lcd_pos_char(2, 1, voltage /1000 + 0x30);
		lcd_out_char('.');
		lcd_out_char(voltage %1000/100 + 0x30);
		lcd_out_char(voltage %100/10 + 0x30);
		lcd_out_char(voltage%10 + 0x30);
		
		delay_ms(500);
	}
}
