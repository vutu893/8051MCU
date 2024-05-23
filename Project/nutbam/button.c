#include <REGX52.H>
#include "../../Lib/delay.h"
#include "port.h"

void main()
{	
	BUTTON_PIN = 1;
	while(1)
	{
		if(BUTTON_PIN == 0){
			//chong doi phim
			delay_ms(20);
			if(BUTTON_PIN == 0)
			{
				LED_PIN = ~LED_PIN;
				//doi cho nha nut bam 
				while(BUTTON_PIN == 0);
			}
		}
	}
}
