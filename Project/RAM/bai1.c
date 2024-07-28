#include <REGX52.H>
#include "../../Lib/delay.h"

// Bo nho cua 8051 co cac vung:
// 1. DATA: 00 --> 7F, CHI TRUY XUAT BANG CAC DINH DIA CHI TRUC TIEP VA GIAN TIEP
// 2. SFR: 80 --> FF, CHI TRUY XUAT BANG CACH DINH DIA CHI GIAN TIEP: DUNG CON TRO
// 3. XDATA: co 16 b

// PHAI KHAI BAO BIEN THEO CACH KHAC:
// DUA VAO MEMORY MODEL: SMALL(DATA), COMPACT(PDATA), LARGE(XDATA)

// VIDU: unsigned int pdata x; khong co dia chi cu the tren vung nho
// hoac: unsigned int pdata x _at_ 0x00;
// khong khai bao hai bien cung dia chi hoac co the dung union 
// vi du ket noi voi RAM 62256: 256 Kbit
void main()
{	
	unsigned char x;
	unsigned char xdata y;
	unsigned char xdata z _at_ 0x0001;
	while(1)
	{
		
	}
}
