#include <REGX52.H>
#include "../../Lib/delay.h"

//bai2: dung mode0 mo rong ngo vao voi ic74165
//ta se dung it chan di vi du: 8 nut nhan ma chi mat 3 chan de ket noi voi vdk
void main()
{
	//che do 0
	SM1 = SM0 = 0;
	
	//cho phep nhan du lieu
	REN = 1;
	while(1)
	{
		//tao xung chot du lieu ngo vao 74165
		P3_2 = 0;
		P3_2 = 1;
		
		RI = 0;
		while(RI == 0);
		//du lieu nhan ve
		P2 = SBUF;	
	}
}
