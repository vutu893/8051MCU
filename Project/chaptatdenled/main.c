#include <REGX52.H>
#include "../../Lib/delay.h"

void main()
{
	while(1)
	{
		P2_0 = !P2_0;
		delay_ms(500);
	}
}
	
