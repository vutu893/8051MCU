/*------------------------------------------------------------------*-
		Soft_I2c.h
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
#ifndef	_I2C_H_
#define _I2C_H_

// Init
void I2C_Init();

// Master generate Start signal
void I2C_Start();

// Master generate Stop signal
void I2C_Stop();

// Write data to Slaver, and get ACK/NACK from Slaver
bit I2C_Write(unsigned char dat);

// Read data from Slaver
unsigned char I2C_Read(bit ack);

#endif
/*------------------------------------------------------------------*-
	--- Ket thuc file ---------------------
-*------------------------------------------------------------------*/
