//bai4: quet led 7 thanh da hop 
// co the dung hai led rieng le roi dung tran pnp de dieu khien moi led: ==> khong giong thuc te vi led nhap nhay
// nhung cothe dung led mpx2-ca: va thay tran bang cong not: ban chat den van nhap nhay nhung do delay thap mat thuong khong the thay
//bai tap: dem tu 00 den 99
// chan dieu khien  LED 1 LED 2 muc 1 thi den tuong ung sang
#include <REGX52.H>
#include "../../Lib/delay.h"

#define LED7SEG P2
sbit led1 = P3^0;
sbit led2 = P3^1;

unsigned char code_led[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0x8F, 0x80, 0x90};

void main()
{
	unsigned int i;
	unsigned char chuc;
	unsigned char dvi;
	unsigned char dem;
	while(1)
	{
		for(dem = 0; dem < 100; dem++)
		{
			chuc = dem/10;
			dvi = dem%10;
			
			for(i = 0; i < 500; i++)
			{
					//sang den hang chuc
				LED7SEG = code_led[chuc];
				led1 = 0;
				delay_ms(1);
				led1 = 1;
				
				//sang den hang don vi
				LED7SEG = code_led[dvi];
				led2 = 0;
				delay_ms(1);
				led2 = 1;
			}
		}
	}
}