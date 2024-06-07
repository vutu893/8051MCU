#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_4.h"
#include "../../Lib/Soft_I2C.h"
#include "../../Lib/Rtc_Ds1307.h"
//su dung IC ve thoi gian thuc: ds1307
//su dung ngat INT1
//su dung chan SOUT noi voi chan INT1 cua at89c52
unsigned char* Days[] = {"SUN","MON","TUE", "WED", "THU", "FRI", "SAT"};
void main()
{	
	unsigned char hour, minute, second, mode, Date, month, year,  day;
	
	Soft_I2c_Init();
	
	Ds1307_Init();
	
	Lcd_Init();
	
	//tao dao dong o chan SOUT
	Ds1307_Write(0x07, 0x10);
	
	//Ngat canh xuong
	IT1 = 1;
	
	//Cho phep ngat
	EX1 = 1;
	
	//cho phep ngat toan cuc
	EA = 1;
	while(1)
	{
			Ds1307_Read_Time(&hour, &minute, &second, &mode);
			
			Lcd_Chr(1,5,hour / 10 + 0x30);
			Lcd_Chr_Cp(hour % 10 + 0x30);
			Lcd_Chr_Cp(':');
			Lcd_Chr_Cp(minute /10 + 0x30);
			Lcd_Chr_Cp(minute%10 + 0x30);
			Lcd_Chr_Cp(':');
			Lcd_Chr_Cp(second/10 + 0x30);
			Lcd_Chr_Cp(second%10 + 0x30);
			
			Ds1307_Read_Date(&day, &Date, &month, &year);
			Lcd_Out(2, 2, Days[day - 1]);
			Lcd_Chr_Cp(' ');
			Lcd_Chr_Cp(Date/10 + 0x30);
			Lcd_Chr_Cp(Date % 10 + 0x30);
			Lcd_Chr_Cp('/');
			Lcd_Chr_Cp(month/10 + 0x30);
			Lcd_Chr_Cp(month%10 + 0x30);
			Lcd_Chr_Cp('/');
			Lcd_Out_Cp("20");
			Lcd_Chr_Cp(year/10 + 0x30);
			Lcd_Chr_Cp(year%10 + 0x30);
			
			//che do nghi - vdk vao che do nghi=> tiet kiem nang luong
			PCON |= 0x01;
	}
}

//chuong trinh phuc vu ngat: ISR interrup service routine
void EX1_ISR(void) interrupt 2
{
}
