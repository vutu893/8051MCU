#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/LCD_4.h"
//khi chan gate = 1 thi dung de do gia tri thoi gian cua muc 1 cua external signals - dong rong xung
//qua trinh thuc thi khi INT0 co muc 1 va dung khi INT0 muc 0
//hien thi tren LCD tan so va chu ki cua mot xung external cap cho timer/counter
void main()
{	
	unsigned int t, f;
	Lcd_Init();
	Lcd_Out(1,1,"T = ");
	Lcd_Out(2,1,"F = ");
	
	//thiet lap che do timer 
	TMOD &= 0xF0;
	TMOD |= 0x09; //gate = 1, M0 = 1
	
	while(1)
	{
		TH0 = 0;
		TL0 = 0;
		
		while(INT0); //bo qua muc 1 dau tien
		while(!INT0); //bo qua muc 0 dau tien
		TR0 = 1; //bat dau cho timer chay
		while(INT0); //chay cho toi khi INT0 xuong muc 0
		TR0 = 0;
		
		t = TH0;
		t <<= 8;
		t |= TL0;
		
		t *= 2;
		Lcd_Chr(1, 5, t/10000 + 0x30);
		Lcd_Chr_Cp(t%10000/1000 + 0x30);
		Lcd_Chr_Cp(t%1000/100 + 0x30);
		Lcd_Chr_Cp(t%100/10 + 0x30);
		Lcd_Chr_Cp(t%10 + 0x30);
		
		f = 1000000/t;
		Lcd_Chr(2, 5, f/10000 + 0x30);
		Lcd_Chr_Cp(f%10000/1000 + 0x30);
		Lcd_Chr_Cp(f%1000/100 + 0x30);
		Lcd_Chr_Cp(f%100/10 + 0x30);
		Lcd_Chr_Cp(f%10 + 0x30);
	}
}