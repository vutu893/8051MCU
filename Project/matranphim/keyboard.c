#include <REGX52.H>
#include "../../Lib/delay.h"

//bai tap ve ma tran phim 4x4
#define LED_PORT P2
sbit led1 = P3^0;
sbit led2 = P3^1;

unsigned char led7seq[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
sbit ROW1 = P1^0;
sbit ROW2 = P1^1;
sbit ROW3 = P1^2;
sbit ROW4= P1^3;
sbit COL1 = P1^4;
sbit COL2 = P1^5;
sbit COL3 = P1^6;
sbit COL4 = P1^7;

unsigned char pressKey()
{
	unsigned char key;
	key = 0;
	ROW1 = 0;
	if(COL1 == 0) key = 1;
	if(COL2 == 0) key = 2;
	if(COL3 == 0) key = 3;
	if(COL4 == 0) key = 4;
	ROW1 = 1;
	
	ROW2 = 0;
	if(COL1 == 0) key = 5;
	if(COL2 == 0) key = 6;
	if(COL3 == 0) key = 7;
	if(COL4 == 0) key = 8;
	ROW2 = 1;
	
	ROW3 = 0;
	if(COL1 == 0) key = 9;
	if(COL2 == 0) key = 10;
	if(COL3 == 0) key = 11;
	if(COL4 == 0) key = 12;
	ROW3 = 1;
	
	ROW4 = 0;
	if(COL1 == 0) key = 13;
	if(COL2 == 0) key = 14;
	if(COL3 == 0) key = 15;
	if(COL4 == 0) key = 16;
	ROW4 = 1;
	
	return key;
}
void main()
{
	unsigned char key, tmp;
	led1 = led2 = 1;
	while(1)
	{
		key = pressKey();
		if(key != 0)
		{
			tmp = key;
		}
		LED_PORT = led7seq[tmp /10];
		led1 = 0;
		delay_ms(1);
		led1 = 1;
		
		LED_PORT = led7seq[tmp % 10];
		led2 = 0;
		delay_ms(1);
		led2  = 1;
	}
}

