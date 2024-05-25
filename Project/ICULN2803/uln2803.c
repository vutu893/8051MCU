#include <REGX52.H>
#include "../../Lib/delay.h"

//dung icunl2803 de dieu khien relay khi chi dung 1 IO cua MCU 
//thuc te dieu khien relay mo bang cach cho logic 0 o IO MCU ==> 2 chan ra cua IC dieu khien 1 relay
//CHAN COM CUA IC DE BAO VE IC

sbit BTN = P1^0;

sbit RELAY = P2^0;
void main()
{
	while(1)
	{
		if(BTN == 0)
		{
				delay_ms(20);
				if(BTN == 0)
				{
					RELAY = !RELAY;
					while(BTN == 0);
				}
		}
	}
}
