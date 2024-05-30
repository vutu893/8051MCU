#include "delay.h"
#include "port.h"
#include "LCD_8.h"
//thiet lap che do cho lcd
void lcd_cmd(unsigned char cmd)
{
	LCD_RS = 0;
	LCD_PORT = cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	if(cmd <= 0x02)
	{
		delay_ms(2);
	}else
	{
		delay_ms(1);
	}
}

//init lcd
void lcd_init()
{
	lcd_cmd(_LCD_8BIT_1LINE_5x7FONT);
	delay_ms(5);
	lcd_cmd(_LCD_8BIT_1LINE_5x7FONT);
	delay_ms(1);
	
	lcd_cmd(_LCD_8BIT_1LINE_5x7FONT);
	lcd_cmd(_LCD_8BIT_2LINE_5x7FONT);//so dong la 2, font chu la 5x8
	
	lcd_cmd(0x01); //xoa noi dung tren lcd
	lcd_cmd(0x0C); //bat hien thi va xoa con tro
}