//ma tran 7x5: 7 hang, 5coy
//ic dem 74hc245 vi mot chan cua vi xu ly chi nhan duoc 10mA trong khi trong ma tran cac led noi song song ==> can dem cho chan vxl cung nhu luc xuat dong
//dung dem dao uln2803
#include <REGX52.H>
#include "../../Lib/delay.h"

unsigned char font5x7_0[] = {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E};

void main()
{	
	unsigned char i;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			P0 = font5x7_0[i];
			P3 = 0x01 << i;
			delay_ms(1);
			P3 = 0x00;
		}
	}
}

