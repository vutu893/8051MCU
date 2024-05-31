
//xay dung thu vien cho LCD o cach ket noi 8bit voi cac chuc nang sau day:
//1. TAO HAM KHOI TAO CHO LCD
//2. TAO HAM LCD COMMAND DE THAO TAC VOI LCD
//3. TAO HAM GHI KI TU
//4. TAO HAM GHI CHUOI KI TU
//5. TAO HAM HIEN THI SO 
//6. HAM DICH KI TU TREN LCD
//7. HAM HIEN THI KY TU O VI TRI BAT KY
//8. HAM HIEN THI CHUOI O VI TRI BAT KY
//9. HAM TAO KI TU CHO TRUOC TREN LCD CO HIEU UNG HIEN THI


///-------------------------------build library lcd connect 8bit-------------------------------------------------

//cac thu vien can include
#include <REGX52.H>
#include "delay.h"
#include "LCD_8.h"
#include "port.h"

//thiet lap che do cho lcd
void lcd_cmd(unsigned char cmd)
{
	LCD_RS = 0;
	LCD_PORT = cmd;
	LCD_ENB = 0;
	LCD_ENB = 1;
	
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
	lcd_cmd(0x30);
	delay_ms(5);
	
	lcd_cmd(0x30);
	delay_ms(1);
	
	lcd_cmd(0x30);
	//che do lcd su dung 2 dong va font chu la 5x8
	lcd_cmd(0x38);
	
	//xoa man hinh lcd 
	lcd_cmd(0x01);
	
	//bat hien thi va xoa con tro
	lcd_cmd(0x0C);
}
//in mot ki tu ra man hinh
void lcd_out_char(char c)
{
	LCD_RS = 1;
	LCD_PORT = c;
	LCD_ENB = 0;
	LCD_ENB = 1;
	delay_ms(1);
}
	
//in mot chuoi ki tu ra man hinh
void lcd_out_str(char *str)
{
	unsigned char i = 0;
	while(str[i] != 0)
	{
		lcd_out_char(str[i]);
		i++;
	}
}

//hien thi mot ki tu o vi tri bat ki
void lcd_pos_char(unsigned char row, unsigned char col, char c)
{
	unsigned char cmd;
	cmd = row == 1? 0x80: 0xC0;
	cmd = cmd + col -1;
	
	lcd_cmd(cmd);
	
	lcd_out_char(c);
}

//hien thi mot chuoi ki tu o vi tri bat ki
void lcd_pos_str(unsigned char row, unsigned char col, char *str)
{
	unsigned char cmd;
	cmd = row == 1? 0x80: 0xC0;
	cmd = cmd + col -1;
	
	lcd_cmd(cmd);
	
	lcd_out_str(str);
}


//customer a lcd display
void lcd_customer_display(unsigned char location, unsigned char* lcd_char)
{
	unsigned char i;
	lcd_cmd(0x40 + location*8);
	for(i = 0; i<=7; i++)
	{
		lcd_out_char(lcd_char[i]);
	}
}

//hien thi khi input la 1 so nguyen

void lcd_out_int(unsigned char n)
{
	char *str;
	intToStr(n, str);
	lcd_out_str(str);
}
