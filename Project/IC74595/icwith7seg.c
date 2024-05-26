#include <REGX52.H>
#include  "../../Lib/delay.h"
#include "../../Lib/IC74595.h"
//so luong phan tu trong buffer la so luong ic dung
// truong hop dung 1 ic
unsigned char led7seq[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void main()
{
	unsigned char i,j;
	unsigned char* buffer;
	while(1)
	{	
		for(i = 0; i < 10; i++)
		{
			buffer = &led7seq[i];
			IC74595_out(buffer, 9);
			delay_ms(1000);
		}
		
	}
}
