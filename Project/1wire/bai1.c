#include <REGX52.H>
#include "../../Lib/delay.h"

#define DS18B20_SKIPROM 0xCC
#define DS18B20_CONVERT_T  0x44
#define DS18B20_READ_SCRATCH_PAD 0xBE


sbit DS18B20_PIN = P1^0;

// gioi thieu ve giao tiep 1 wire: serial protocol
// 1 wire master control one or more wire slave
// 1 wire slave has 64 bit ID and include: 8-bit family code( quy dinh loai thiet bi) va 8 - bit de kiem tra loi
// only transmit or recevie in one time
// su dung 1 wire voi cam bien nhiet do DS18B20

void delay_us(unsigned int t);
unsigned char DS18B20_Reset();
void DS18B20_Write1();
void DS18B20_Write0();
void DS18B20_Write_Bit(unsigned char b);
unsigned char DS18B20_Read_Bit();
void DS18B20_Write_Byte(unsigned char b);
unsigned char DS18B20_Read_Byte();
	
void main()
{
	unsigned int temp;
	TMOD |= 0x01; // timer 0 hoat dong o che do 1: dinh thoi 16bit
	while(1)
	{
		//doc du lieu tu cam bien ds18b20
		while(DS18B20_Reset());
		DS18B20_Write_Byte(DS18B20_SKIPROM);
		DS18B20_Write_Byte(DS18B20_CONVERT_T);
		
		delay_ms(750);
		
		while(DS18B20_Reset());
		DS18B20_Write_Byte(DS18B20_SKIPROM);
		DS18B20_Write_Byte(DS18B20_READ_SCRATCH_PAD);
		
		temp = DS18B20_Read_Byte();
		temp = (DS18B20_Read_Byte() << 8) | temp;
	}
}

//ham delay us su dung timer 0
void delay_us(unsigned int t)
{
	unsigned int load_value;
	
	load_value = 65536 - t;
	TH0 = load_value >> 8;
	TL0 = load_value & 0x00FF;
	TR0 = 1;
	while(!TR0);
	TR0 = 0;
	TF0 = 0;
}
//ham reset cho one wire
unsigned char DS18B20_Reset()
{
	unsigned char result;
	
	DS18B20_PIN = 0;
	delay_us(480);
	
	DS18B20_PIN = 1;
	delay_us(70);
	
	result = DS18B20_PIN;
	
	delay_us(410);
	
	return result; // result = 1 thi khong hoat dong, nguoc lai thi cam bien co tra ve result
}

//ham write 1
void DS18B20_Write1()
{
	DS18B20_PIN = 0;
	delay_us(6);
	
	DS18B20_PIN = 1;
	delay_us(64);
}
//ham write 0
void DS18B20_Write0()
{
	DS18B20_PIN = 0;
	delay_us(60);
	
	DS18B20_PIN = 1;
	delay_us(10);
}

//ham write
void DS18B20_Write_Bit(unsigned char b)
{
	if(b == 1)
	{
		DS18B20_Write1();
	}else
	{
		DS18B20_Write0();
	}
}

//ham doc du lieu
unsigned char DS18B20_Read_Bit()
{
	unsigned char result;
	
	DS18B20_PIN = 0;
	delay_us(6);
	
	DS18B20_PIN = 1;
	delay_us(9);

	result = DS18B20_PIN;
	delay_us(55);
	
	return result;
}

// ham write 1 byte
void DS18B20_Write_Byte(unsigned char b)
{
	unsigned char i = 8;
	while(i--)
	{
		DS18B20_Write_Bit( b & 0x01);
		b >>= 1;
	}
}

//ham read 1 byte
unsigned char DS18B20_Read_Byte()
{
	unsigned char i = 0, result = 0;
	while(i--)
	{
		result >>= 1;
		result |= (DS18B20_Read_Bit() << 7);
	}
	return result;
}

//