#include <REGX52.H>

//timer 2 tao ra xung clock o chan p1^0

void main()
{
	//cau hinh che do generate clock
	T2CON = 0x00;
	T2MOD = 0x02;
	
	//TAO TAN SO 1KHz
	RCAP2H = 0xF4;
	RCAP2L = 0x48;
	
	TR2 = 1;
	while(1)
	{
		
	}
}
