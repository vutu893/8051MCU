#include <REGX52.H>
#inclue "../../Lib/delay.h"
#include "../../Lib/LCD_4.h"
#include "../../Lib/ADC0804.h"

// t = Vout / 10(mV) ma Vout = D * 5 /255 nen:
//nhiet do: t = D * 1.961
// Chan Vout cua cam bien ket noi voi Vin cua 0804 
// dung thu vien ADC0804 
// ket qua nhiet do can do tinh theo cong thuc tren roi hien thi thong qua LCD
void main()
{
	unsigned char adc_value;
	unsigned int t;
	
	LCD_Init();
	Lcd_Out(1, 1,"Nhiet do: ");
	while(1)
	{
		adc_value = ADC0804_Read();
		t = adc_value * 1.961f + 0.5f; //cong 0.5 de tang do chinh xac vi no se bi lam tron xuong
		
		Lcd_Chr(1, 11, t /100 + 0x30);
		Lcd_Chr_Cp(t%100/10 + 0x30);
		Lcd_Chr_Cp(t % 10 + 0x30);
		
		delay_ms(500);
	}
}
