#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_4.h"
#include "../../Lib/Soft_I2C.h"
#include "../../Lib/Rtc_Ds1307.h"
//su dung IC ve thoi gian thuc: ds1307
unsigned char* Days[] = {"SUN","MON","TUE", "WED", "THU", "FRI", "SAT"};
void main()
{	
	unsigned char hour, minute, second, mode, Date, month, year, old_second, day;
	
	Soft_I2c_Init();
	
	Ds1307_Init();
	
	Lcd_Init();
	
	while(1)
	{
		Ds1307_Read_Time(&hour, &minute, &second, &mode);
		if(old_second != second )
		{	
			old_second = second;
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
		}
		
	}
}
