#include <REGX52.H>
#include "../../delay.h"


unsigned char ADC0804_Read();

void main()
{
	while(1)
	{
	
	}
}
unsigned char ADC0804_Read()
{
	unsigned char kq;
	
	//CHON CHIP VA CHIP BAT DAU HOAT DONG
	ADC0804_CS = 0;
	
	//TAO XUNG BAT DAU CHUYEN DOI
	ADC0804_WR = 0;
	ADC0804_WR = 1;
	
	//DOI CHO DEN KHI CHUYEN DOI XONG
	while(ADC0804_INTR);
	
	//DOC GIA TRI SAU KHI CHUYEN DOI
	ADC0804_RD = 0;
	kq = ADC0804_DATA;
	ADC0804_RD = 1;
	
	return kq;
}