#include <REGX52.H>
#include "../../Lib/delay.h"

//bai5: giao tiep va xuat du lieu ra lcd
//test cac thu vien lcd
//cau hinh chan cho lcd
sbit LCD_RS = P2^0;
sbit LCD_EN = P2^1;
#define LCD_PORT  P3

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

void lcd_init()
{
	lcd_cmd(0x30);
	delay_ms(5);
	lcd_cmd(0x30);
	delay_ms(1);
	
	lcd_cmd(0x30);
	lcd_cmd(0x38);//so dong la 2, font chu la 5x8
	
	lcd_cmd(0x01); //xoa noi dung tren lcd
	lcd_cmd(0x0C); //bat hien thi va xoa con tro
}

void lcd_out_char(char c)
{
	LCD_RS = 1;
	LCD_PORT = c;
	LCD_EN = 0;
	LCD_EN = 1;
	delay_ms(1);
}

void lcd_out_str(char *str)
{
	unsigned char i = 0;
	while(str[i] != 0)
	{
		lcd_out_char(str[i]);
		i++;
	}
}

void main()
{
	while(1);
}