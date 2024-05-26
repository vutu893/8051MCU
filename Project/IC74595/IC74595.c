//IC74595 la ic mo rong ngo ra: chi can it chan vdk nhung van co nhieu dau ra de dieu khien
//chi so: 3 vao 8 ra
//ghep noi tiep 
//toc do truyen du lieu thap di
// chan DS de nhan du lieu, chan SH-CP nhan xung nhip, chan ST_CP
// CHAN MR 5V, chan con lai noi dat trong truowng hop khong ghep noi

//Bai1: giao tiep voi 74595 va led sang nhap nhay
#include <REGX52.H>
#include "../../Lib/delay.h"

//khai bao ket noi voi IC74HC595
sbit IC74595_SHCP = P2^0;
sbit IC74595_DS = P2^1;
sbit IC74595_STCP = P2^2;

void IC74595_out_byte(unsigned char b)
{
	unsigned char i;
	for(i = 0; i < 8;i++)
	{	
		//lay tung b  cua byte gui ra DS, lay b MSB truoc
		IC74595_DS = b & (0x80 >> i);
		
		//tao xung dich du lieu
		IC74595_SHCP = 0;
		IC74595_SHCP = 1;
	}
	//Tao xung  xuat du lieu 
	IC74595_STCP = 0;
	IC74595_STCP = 1;	
}

void main()
{
	unsigned char b, i;
	while(1) 
	{	
		b = 0;
		IC74595_out_byte(b);
		delay_ms(300);
		for(i = 0; i < 8; i++)
		{
			b = b | (1 << i);
			IC74595_out_byte(b);
			delay_ms(300);
		}
	}
}
