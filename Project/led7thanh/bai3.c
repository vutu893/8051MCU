#include <REGX52.H>
#include "../../Lib/delay.h"

//bai3: IC giai ma 7447
//IC7447: dung 4 chan de hien thi led 7 doan (ma bcd sang led 7 doan)
// CHE DO HOAT DONG BINH THUONG: BI/RBO, RBI LT DE TRONG HOAC NOI VOI MUC CAO
// CHE DO BO SO 0: BI/RBO, LT TRONG, RBI noi voi muc 0
// CHAM BI/RBO O CHE DO BO 0 THI O MUC 0 KHI LA SO 0, NO DUNG DE NOI CAC IC 7447 VOI NHAU

void main()
{
	unsigned int dem = 0;
	unsigned char chuc, tram, dvi;
	unsigned char tam;
	while(1)
	{
		dvi = dem % 10;
		chuc = (dem%100) / 10;
		tram = dem / 100;
		
		//hang chuc day len 4b cao con dvi o 4 b thap
		tam = chuc << 4;
		tam |= dvi;
		P2 = tam;
		P3 = tram;
		
		delay_ms(500);
		dem++;
		dem %=1000;
	}
}
