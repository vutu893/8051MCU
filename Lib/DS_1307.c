/*------------------------------------------------------------------*-
		Rtc_Ds1307.c
	---------------------------------------
		- Written by Nguyen Thanh Dang
		- Date Created:	16/05/2012
		- Last Modifer: 16/05/2012
		- Require:	
			* Include Soft_I2C. Ex:
				#include"Soft_I2C.h"	
			* Use LX51 (Option for Target - Device tab - 
				Use Extended Linker (LX51)...)
			* Use REMOVEUNUSED linker directive (Option for Target - 
				LX51 Misc tab - Misc controls: RU)
-*------------------------------------------------------------------*/
#include <REGX52.H>
#include"port.h"
#include"I2C.h"
#include"DS_1307.h"

/*-------------------------------------*-
	Ds1307_Init
	- Description
		Allow Ds1307 run
-*-------------------------------------*/
void Ds1307_Init()
{
 	unsigned char tmp;
	tmp = Ds1307_Read(0x00);
	tmp &= 0x7F;
	Ds1307_Write(0x00,tmp);		
}

/*-------------------------------------*-
	Ds1307_Write function
	- Description
		Write a byte into address
	- Parameters:
		add: Address
		dat: Data
-*-------------------------------------*/
void Ds1307_Write(unsigned char add, unsigned char dat)
{
	I2C_Start();
	I2C_Write(0xD0);
	I2C_Write(add); 
	I2C_Write(dat); 
	I2C_Stop();
}

/*-------------------------------------*-
	Ds1307_Read function
	- Description
		Read a byte at address
	- Parameters
		add - Address
	- Return
		1 byte at Address
-*-------------------------------------*/
unsigned char Ds1307_Read(unsigned char add)
{
	unsigned char dat;
	I2C_Start();
	I2C_Write(0xD0); 
	I2C_Write(add);
	I2C_Start(); 
	I2C_Write(0xD1); 
	dat = I2C_Read(0);
	I2C_Stop();
	return dat;
}

/*-------------------------------------*-
	Ds1307_Read_Time
	- Description
		Get hour, minute, second in BCD format 
	- Paramaters
	  	&hour 	-  
		&minute - 
		&second -  
		&mode	- Mode 12/24h (12 or 24)
	- return mode 24/12
		0 - AM
		1 - PM
-*-------------------------------------*/
bit Ds1307_Read_Time(unsigned char * hour, unsigned char * minute, 
	unsigned char * second, unsigned char * mode)
{
	unsigned char h_tmp, m_tmp, s_tmp;
	bit am_pm;
	I2C_Start();
	I2C_Write(0xD0); 
	I2C_Write(0x00);
	I2C_Start(); 
	I2C_Write(0xD1); 
	s_tmp = I2C_Read(1);
	m_tmp = I2C_Read(1);
	h_tmp = I2C_Read(0);
	I2C_Stop();

	s_tmp &= 0x7F;
	*second = (s_tmp>>4)*10+(s_tmp&0x0F);
	m_tmp &= 0x7F;
	*minute = (m_tmp>>4)*10+(m_tmp&0x0F);

	if(h_tmp & 0x40) 		// Mode 12h
	{
		*mode = 12;
		if(h_tmp & 0x20)
		{
		 	am_pm = 1;		// PM
		}
		else
		{
		 	am_pm = 0;
		}
		h_tmp &= 0x1F;
	 	*hour = (h_tmp>>4)*10+(h_tmp&0x0F);
	}
	else
	{
		*mode = 24;
		h_tmp &= 0x3F;
	 	*hour = (h_tmp>>4)*10+(h_tmp&0x0F);
		if(*hour<12)
		{
		 	am_pm = 0;		// AM
		}
		else
		{
		 	am_pm = 1;
		}
	}	
	return am_pm;
}

/*------------------------------------------------------------------*-
		Ds1307_Write_Time
	---------------------------------------
		- Description
			Write Hour, minute, second, mode, am/pm into Ds1307
		- Parameters
			hour, minute, second in decimal format
			mode: 12/14
			apm: 0 - AM, 1 - PM
-*------------------------------------------------------------------*/
void Ds1307_Write_Time(unsigned char hour, unsigned minute, 
	unsigned char second, unsigned char mode, bit apm)
{
	second = ((second/10)<<4)|(second%10);
	minute = ((minute/10)<<4)|(minute%10);
	hour   = ((hour  /10)<<4)|(hour  %10);
	if(mode==12)
	{
		hour |= 0x40;
		if(apm)		// PM
		{
			hour |= 0x20;
		}
	}
	I2C_Start();
	I2C_Write(0xD0);
	I2C_Write(0x00); 
	I2C_Write(second); 
	I2C_Write(minute);
	I2C_Write(hour);
	I2C_Stop();
}

/*-------------------------------------*-
	Ds1307_Read_Time
	- Description
		Read day, date, month, year from Ds1307
	- Parameters
		&date, &day, &month, &year
	-  	
-*-------------------------------------*/
void Ds1307_Read_Date(unsigned char * day, unsigned char * date, 
	unsigned char * month, unsigned char * year)
{
	I2C_Start();
	I2C_Write(0xD0); 
	I2C_Write(0x03);
	I2C_Start(); 
	I2C_Write(0xD1); 
	*day  = I2C_Read(1);
	*date = I2C_Read(1);
	*month= I2C_Read(1);
	*year = I2C_Read(0);
	I2C_Stop();
	*day &= 0x07;
	*date &= 0x3F;
	*date = (*date>>4)*10 + (*date & 0x0F);
	*month &= 0x1F;
	*month = (*month>>4)*10 + (*month & 0x0F);
	*year = (*year>>4)*10 + (*year & 0x0F);	
}

/*-------------------------------------*-
	Ds1307_Write_Date
	- Description
		Write day, date, month, year into Ds1307
	- Parameters
		day, date, month, year
-*-------------------------------------*/
void Ds1307_Write_Date(unsigned char day, unsigned char date, 
	unsigned char month, unsigned char year)
{
	date 	= ((date/10)<<4)  | (date%10);
	month 	= ((month/10)<<4) | (month%10);
	year	= ((year/10)<<4)  | (year%10);

	I2C_Start();
	I2C_Write(0xD0);
	I2C_Write(0x03); 
	I2C_Write(day); 
	I2C_Write(date);
	I2C_Write(month);
	I2C_Write(year);
	I2C_Stop();
}

/*-------------------------------------*-
	Ds1307_Write_Bytes
	- Description
		Write array of byte begin at address
	- Parameters
		add: Start Address
		buff: Pointer to Write Buffer
		len:  Number of byte to Write
-*-------------------------------------*/
void Ds1307_Write_Bytes(unsigned char add, unsigned char * buff,
	unsigned char len)
{
	unsigned char i=0;

	I2C_Start();
	I2C_Write(0xD0);
	I2C_Write(add);
	for(i=0;i<len;i++)
	{ 	 
		I2C_Write(buff[i]); 
	} 
	I2C_Stop();
}

/*-------------------------------------*-
	Ds1307_Read_Bytes
	- Description
	 	Read array of byte into buff at add
	- Parameters
		add: Start Address
		buff: Pointer to Read Buffer
		len:  Number of byte to Read
-*-------------------------------------*/
void Ds1307_Read_Bytes(unsigned char add,unsigned char * buff,
	unsigned char len)
{
 	unsigned char i;

	I2C_Start();
	I2C_Write(0xD0); 
	I2C_Write(add);
	I2C_Start();
	I2C_Write(0xD1);
	for(i=0;i<len-1;i++)
	{ 
		buff[i]  = I2C_Read(1);
	}
	buff[i]  = I2C_Read(0);
	I2C_Stop();
}

/*------------------------------------------------------------------*-
	--- Ket thuc file ---------------------
-*------------------------------------------------------------------*/
