
#include <REGX52.H>
#include "ADC0808.h"
#include "port.h"

void ADC0808_Init()
{
	ADC0808_START = 0;
	ADC0808_ALE = 0;
	ADC0808_OE = 0;
}
//ham ADC0808 co 1 tham so la dia chi cua IC
//cac gia tri khoi tao cua cac chan phai xem o time diagram cua IC
unsigned char ADC0808_Read(unsigned char address)
{
	unsigned char kq;
	
	//Chon dia chi cho ic thong qua 3 chan chon dia chi
	ADC0808_ADDA = address & 0x01;
	ADC0808_ADDB = address & 0x02;
	ADC0808_ADDC = address & 0x04;
	
	//Khoi dong IC thong qua cac chan start , ale: dung de chot dia chi
	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;
	
	//doi cho den khi chan EOC dao gia tri
	while(ADC0808_EOC);
	while(!ADC0808_EOC);
	
	//BAT DAU NHAN DU LIEU TU ADC0808
	ADC0808_OE = 1;
	kq = ADC0808_DATA;
	ADC0808_OE = 0;
	
	return kq;
}
