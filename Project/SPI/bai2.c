#include <REGX52.H>
#include "../../Lib/delay.h"

// gioi thieu ve eeprom 25LC256
// cap nguon 5V va clock 10MHz
// Giao tiep noi tep theo chuan SPI va hoat dong o hai mode 0 va 1

// So do chan: datasheet

// du lieu di tu 8051 qua eeprom, SI noi voi MOSI, S0 noi voi MISO
sbit SPI_SCLK = P2^0;
sbit SPI_MOSI = P2^1;
sbit SPI_MISO = P2^2;
sbit SPI _CS = P2^3;

void SPI_Init();
void SPI_Write_One_Byte(unsigned char b);
unsigned char SPI_Read_One_Byte();
void eeprom_25LCxxx_Write(unsigned int address, unsigned char b);
unsigned char  eeprom_25LCxxx_Read(unsigned int address);
unsigned char eeprom_25LCxxx_WIP();

void main()
{
	SPI_Init();
	
	//muon ghi nhieu lan thi dung ham delay hoac su dung phuong phap kiem tra trang thai cua eeprom neu khong se khong thuc hien duoc
	// su dung flag status cua eeprom
	eeprom_25LCxxx_Write(0, 0x55);
	P1 = eeprom_25LCxxx_Read(0);
	while(1)
	{
	
	}
}

//ham kiem tra trang thai cua eeprom
unsigned char eeprom_25LCxxx_WIP()
{
	unsigned char result;
	
	SPI_CS = 0;
	SPI_Write_One_Byte(0x05);
	result = SPI_Read_One_Byte();
	SPI_CS = 1;
	
	return result & 0x01; //chi xet bit thap nhat cua thanh ghi trang thai
}
//ham read voi eeprom
unsigned char  eeprom_25LCxxx_Read(unsigned int address)
{
	unsigned char b;
	
	SPI_CS = 0;
	SPI_Write_One_Byte(0x30);
	SPI_Write_One_Byte( address>> 8); // GUI 8BIT CAO CUA ADDRESS
	SPI_Write_One_Byte(address & 0x00FF); // gui 8 byte thap
	b = SPI_Read_One_Byte();
	SPI_CS = 1;
	
	return b;
}
//ham thao tac voi eeprom: ghi mot byte vao eeprom tai dia chi address
// tra datasheet cua eeprom 25LCxxx de code function write
void eeprom_25LCxxx_Write(unsigned int address, unsigned char b)
{
	SPI_CS = 0;
	SPI_Write_One_Byte(0x06); //gui lenh WREN
	SPI_CS = 1;
	
	SPI_CS = 0;
	SPI_Write_One_Byte(0x02); //GUI LENH WRITE
	SPI_Write_One_Byte( address>> 8); // GUI 8BIT CAO CUA ADDRESS
	SPI_Write_One_Byte(address & 0x00FF); // gui 8 byte thap
	SPI_Write_One_Byte(b); //gui du lieu
	SPI_CS = 1;
	
	while(eeprom_25LCxxx_WIP());
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
		// check xem bit nhan la bit 0 hay bit 1
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
		// check bit gui la bit 1 hay bit 0
		if(SPI_MISO)
		{
			b |= 0x01;
		}
		SPI_SCLK = 0;
	}
	return b;
}
