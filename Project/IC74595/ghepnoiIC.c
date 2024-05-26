//bai2: ghep noi nhieu IC
#include <REGX52.H>
#include "../../Lib/delay.h"

sbit IC74595_SHCP = P2^0;
sbit IC74595_DS = P2^1;
sbit IC74595_STCP = P2^2;

//dung con tro boi vi trong main ta se dung mang va de thay doi gia tri truyen thi phai dung con tro trong ham
void IC74595_out(unsigned char *p, unsigned char n)
{
	unsigned char i, b, j;
	for(j = 0; j < n;j++)
	{
		//lay byte cao nhat truoc
		b = *(p - j + n -1);
		
		for(i = 0; i < 8; i++)
		{
			IC74595_DS = b & (0x80 >> i);
			
			//tao xung dich du lieu
			 IC74595_SHCP = 0;
			 IC74595_SHCP = 1;
		}
	}
	//tao xung xuat du lieu
	IC74595_STCP = 0;
	IC74595_STCP = 1;
}

void main()
{
	unsigned char buffer[2];
	unsigned char i;
	while(1)
	{
		for(i = 0; i < 2; i++)
		{
			buffer[i] = 0;
		}
		IC74595_out(buffer, 2);
		delay_ms(250);
		
		for(i = 0; i < 2; i++)
		{
			buffer[i] = 0xFF;
		}
		IC74595_out(buffer, 2);
		delay_ms(200);
	}
}