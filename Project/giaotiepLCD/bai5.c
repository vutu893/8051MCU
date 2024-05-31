#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_8.h"
//test library lcd_8 
void main()
{	
	lcd_init();
	lcd_pos_str(1, 4, "vu trinh tu vu trinh tu");
	lcd_cmd(_LCD_UNDERLINE_ON);
	delay_ms(5000);
	lcd_cmd(_LCD_CLEAR);
	while(1)
	{
		//lcd_cmd(0x1C);
		//delay_ms(100);
	}
}