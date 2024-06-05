//firmwar connect I2C
/*------------------------------------------------------------------*-
		Soft_I2c.c
	---------------------------------------
		- Written by Nguyen Thanh Dang
		- Created date: 	16/05/2012
		- Last Modified: 	16/05/2012
		- Require: 
			* Declare hardware connections (in Port.h). 
			* Define USE_SOFT_I2C_DELAY when you want reduce frequency of I2C
			* Use LX51 (Option for Target - Device tab - 
				Use Extended Linker (LX51)...)
			* Use REMOVEUNUSED linker directive (Option for Target - 
				LX51 Misc tab - Misc controls: RU) 
-*------------------------------------------------------------------*/

#include <REGX52.H>
#include"port.h"
#include"I2c.h"
#include"intrins.h"

#ifdef	USE_I2C_DELAY
	#message "Soft I2C - USE_SOFT_I2C_DELAY"
	#define I2C_Delay()	{_nop_();_nop_();_nop_();_nop_();_nop_();}
#else
	#define I2C_Delay()
#endif

/*-------------------------------------*-
	Prototype for Local Function
-*-------------------------------------*/
bit I2C_Get_Ack();
void I2C_Ack();
void I2C_Nak();

/*-------------------------------------*-
	Soft_I2c_Init
-*-------------------------------------*/
void I2C_Init()
{
 	I2C_SCL=1;
	I2C_SDA=1;
}

/*-------------------------------------*-
	Soft_I2c_Start
-*-------------------------------------*/
void I2C_Start()
{
	I2C_SCL = 1;
	I2C_Delay();
	I2C_SDA = 0;
	I2C_Delay();
	I2C_SCL = 0;
}

/*-------------------------------------*-
	Soft_I2c_Get_Ack - Local Function 
	- return
		0 - ACK
		1 - NAK 
-*-------------------------------------*/
bit I2C_Get_Ack()
{
	bit result;
  I2C_SDA = 1;
	I2C_Delay();
  I2C_SCL = 1;
	I2C_Delay();
	result = I2C_SDA;
  I2C_SCL = 0;
	return result;
}

/*-------------------------------------*-
	Soft_I2c_Write
	- return
		0: ACK - No Error
		1: NAK - Error
-*-------------------------------------*/
bit I2C_Write(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	  I2C_SDA = (bit)(dat&0x80);	
	  I2C_SCL = 1;
		I2c_Delay();
		I2C_SCL = 0;
	  dat<<=1;
	}
	return(Soft_I2c_Get_Ack());
}

/*-------------------------------------*-
	Soft_I2c_Ack - Local Function
-*-------------------------------------*/
void I2C_Ack()
{
	I2C_SDA = 0;
	I2C_Delay();
	I2C_SCL = 1;
	I2C_Delay();
  I2C_SCL = 0;
}

/*-------------------------------------*-
	I2C_Nak - Local Function	
-*-------------------------------------*/
void I2C_Nak()
{
  I2C_SDA = 1;
	I2C_Delay();
  I2C_SCL = 1;
	I2C_Delay();
  I2C_SCL = 0;
}

/*-------------------------------------*-
	I2C_Read function
	- Tham so
		ack: 0 - Master tao NAK sau khi truyen
			 1 - Master tao ACK sau khi truyen
-*-------------------------------------*/
unsigned char I2C_Read(bit ack)
{
   unsigned char i, dat=0;
   for(i=0;i<8;i++)
	{
	  I2C_SDA = 1;
		I2C_Delay();
	  I2C_SCL = 1;
		I2C_Delay();
	    dat <<= 1;
		if(I2C_SDA)
		{
		 	dat |= 0x01;
		}
			I2C_SCL = 0;
    }
	if(ack)
	{
	 	I2C_Ack();
	}
	else
	{
	 	I2C_Nak();
	}
  return dat;
}

/*-------------------------------------*-
	Soft_I2c_Stop function
-*-------------------------------------*/
void I2C_Stop()
{ 	
	I2C_SDA = 0;
	I2C_Delay();
	I2C_SCL = 1;
	I2C_Delay();
	I2C_SDA = 1;
}
/*------------------------------------------------------------------*-
	--- Ket thuc file ---------------------
-*------------------------------------------------------------------*/
