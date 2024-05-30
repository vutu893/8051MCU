
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
#include "delay.h"
#include "port.h"
#include "LCD_8.h"

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

