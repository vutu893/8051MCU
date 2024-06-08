#include <REGX52.H>
#include "UartMode1.h"

//chu y thu vien  su dung tan so 11 059 200
void Uart_Init()
{
	// Khoi tao UART o mode 1, 9600 baud
	SM0 = 0; SM1 = 1;		// Chon UART mode 1
	TMOD = TMOD & 0x0F;   // 0010 xxxx - Timer1 hoat dong o che do 8bit tu dong nap lai
	TMOD = TMOD | 0x20;
	TH1 = 0xFD;				// Toc do baud 9600
//#if(BAUDRATE == 9600)
//TH1 = 0xFD
//#elif(BAUDRATE == 2400)
//TH1 = 0xF4
//#elif(BAUDRATE == 1200)
/TH1 = 0xE8
//#elif(BAUDRATE == 19200)
//TH1 =	0xFH voi SMOD |= 0x80
//#else
	//#error "toc do khong thich hop "
	TR1 = 1;				// Timer1 bat dau chay
	TI = 1;					// San sang gui du lieu
	REN = 1;				// Cho phep nhan du lieu
}

void Uart_Write(char c)
{
 	while(TI == 0);
	TI = 0;
	SBUF = c;
}

void Uart_Write_Text(char * str)
{
	unsigned char i = 0;
 	while(str[i]!=0)
	{
		Uart_Write(str[i]);
		i++;
	}
}

char Uart_Data_Ready()
{
	return RI;
}

char Uart_Read()
{
	RI = 0;
	return SBUF;
}