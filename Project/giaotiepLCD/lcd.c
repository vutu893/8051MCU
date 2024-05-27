//GIAO TIEP LCD VOI VDK: 
//GIAO TIEP 8BIT: 
//GIAO TIEP 4BIT: DUNG 4 BIT CAO du lieu truyen 2 lan
//tap lenh cua lcd: 0x01: xoa noi dung, 0x02 xem trong tai lieu
//vi du ve giao tiep lcd:
#include <REGX52.H>
#include "../../Lib/delay.h"

//khai bao ket noi voi LCD
sbit LCD_RS = P2^0;
sbit LCD_EN = P2^1;
#define LCD_DATA P3

//ham chon che do cho lcd
void lcd_cmd(unsigned char cmd)
{
	LCD_RS = 0;
	LCD_DATA = cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	
	if(cmd  <= 0x02)
	{
		delay_ms(2);
	}else
	{
		delay_ms(1);
	}
}

//hien thi 1 ki tu len lcd tren con tro hien tai
void lcd_out_char(char c)
{
	LCD_RS = 1;
	LCD_DATA = c;
	LCD_EN = 0;
	LCD_EN = 1;
	delay_ms(1);
}

//hien thi mot chuoi ki tu
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
	
	//xoa noi dung lcd
	lcd_cmd(0x01);
	//bat hien thi lcd va che do con cho
	lcd_cmd(0x0E);
	
	//hien thi chu A
	lcd_out_str("VUTRINHTU");
	while(1);
}

