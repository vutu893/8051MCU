#include <REGX52.H>

// giao tiep SPI: cam bien, eeprom, adc, lcd, 
// toc do cao nhung chi dung cho cac ic trong mot bo mach, hoat dong theo master-slave
// bus SPI co 4 duong tin hieu:
// SCLK: Serial clock
// MOSI: master out, slave in hoac SDI
// MISO: master in , slave out hoac SDO
// SS: slave select

// Cach truyen va nhan du lieu:
// Moi xung tren SCLK, thi mot bit trong master truyen sang slave thong qua MOSI
// dong thoi mot bit trong thanh gi du lieu cua slave truyen qua cho master thong qua MISO
// Co 4 mode: 

sbit SPI_SCLK = P2^0;
sbit SPI_MOSI = P2^1;
sbit SPI_MISO = P2^2;
sbit SPI _CS = P2^3;

void SPI_Init();
void SPI_Write_One_Byte(unsigned char b);
unsigned char SPI_Read_One_Byte();
void main()
{
	while(1)
	{
	
	}
}
// ham khoi tao cho giao tiep SPI
void SPI_Init()
{
	SPI_CS = 1; // chua hoat dong
	SPI_SCLK = 0; // chua cap xung
	SPI_MISO = 1; // khoi tao de doc du lieu ve
}

//ham truyen du lieu tu master sang slave
void SPI_Write_One_Byte(unsigned char b)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		if(b & 0x80 != 0)
		{
			SPI_MOSI = 1;
		}else
		{
			SPI_MOSI = 0;
		}
		SPI_SCLK = 1; //CHO PHEP TRUYEN NHAN DU LIEU
		SPI_SCLK = 0; // DUNG CAP XUNG
		b <<= 1; //dich dan den bit thu 6
	}
}
//ham doc du lieu tu slave cho master
unsigned char SPI_Read_One_Byte()
{
	unsigned char i, b;
	for(i = 0; i < 8; i++)
	{
		b <<= 1;
		SPI_SCLK = 1;
		// check bit doc la bit 1 hay bit 0
		if(SPI_MISO)
		{
			b |= 0x01;
		}
		SPI_SCLK = 0;
	}
	return b;
}