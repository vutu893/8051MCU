//mode1: truyen nhan du lieu bat dong bo, co the thay doi toc do baud
//Qua trinh truyen du lieu mode 1: gui B start luon bang 0 khi ket thuc la B stopp
//de gui 1 byte thi gui 10B 
//Khoi tao thanh ghi TMOD la 0010xxxxB de thiet lap toc do Baund dung timer 1
//baud rate = timer1 overflow rate : 32
//dung virtual terminal de debug
#include <REGX52.H>

//tan so cua thach anh la 11.0592MHz

//Check RI = 1 de biet vi dieu khien san sang doc du lieu
void Uart_Init()
{
	//khoi tao UART o mode 1, 9600baud
	SM0 = 0;
	SM1 = 1;
	
	//khoi tao toc do baud
	TMOD = 0x20; //timer 1 hoat dong o che do 8bit tu dong nap lai
	TH1 = 0xFD; //ma nap vao thanh ghi de co toc do baud la 9600
	TR1 = 1; //timer bat dau chay
	
	TI = 1;
	REN = 1; //cho phep nhan du lieu
}
char Uart_Data_Ready()
{
	return RI;
}
//doc du lieu tu ngoai vi
char Uart_Read()
{
	RI = 0;
	return SBUF;
}
//viet du lieu ra ngoai vi
void Uart_Write(char c)
{
	while(TI == 0);
	TI = 0;
	SBUF = c;
}
//viet mot chuoi ki tu ngoai vi
void Uart_Write_Text(char *str)
{
	unsigned char i = 0;
	while(str[i]!= 0)
	{
		Uart_Write(str[i]);
		i++;
	}
}

void main()
{	
	char i;
	Uart_Init();
	
	while(1)
	{
		Uart_Write_Text("Nhap vao ki tu in thuong: ");
		//check xem da xuat het du lieu o tren chua
		while(Uart_Data_Ready() == 0);
		i = Uart_Read();
		i = i - 32;
		Uart_Write_Text("-->");
		Uart_Write(i);
		Uart_Write_Text("\r\n");
	}
}

