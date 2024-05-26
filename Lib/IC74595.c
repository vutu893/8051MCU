#include <REGX52.H>
#include "IC74595.h"
#include "port.h"
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



