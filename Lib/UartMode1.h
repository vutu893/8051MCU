#ifndef _UARTMODE1_H_
#define _UARTMODE1_H_

void Uart_Init();
void Uart_Write(char c);
char Uart_Data_Ready();
char Uart_Read();
void Uart_Write_Text(char * str);

#endif