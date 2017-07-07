/****************************************************************************
 *   $Id:: i2ctest.c 9374 2012-04-19 22:58:18Z nxp41306                     $
 *   Project: NXP LPC11xx I2C example
 *
 *   Description:
 *     This file contains I2C test modules, main entry, to test I2C APIs.
 *
 ****************************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.

* Permission to use, copy, modify, and distribute this software and its 
* documentation is hereby granted, under NXP Semiconductors' 
* relevant copyright in the software, without fee, provided that it 
* is used in conjunction with NXP Semiconductors microcontrollers.  This 
* copyright, permission, and disclaimer notice must appear in all copies of 
* this code.
****************************************************************************/
#include "LPC11xx.h"			/* LPC11xx Peripheral Registers */
#include "type.h"
#include "i2c.h"

extern volatile uint32_t I2CCount;
extern volatile uint8_t I2CMasterBuffer[BUFSIZE];
extern volatile uint8_t I2CSlaveBuffer[BUFSIZE];
extern volatile uint32_t I2CMasterState;
extern volatile uint32_t I2CReadLength, I2CWriteLength;

/*******************************************************************************
**   Main Function  main()
*******************************************************************************/
int main (void)
{
  uint32_t i;

	SystemCoreClockUpdate();  

  if ( I2CInit( (uint32_t)I2CMASTER ) == FALSE )	/* initialize I2c */
  {
	while ( 1 );				/* Fatal error */
  }

  /* In order to start the I2CEngine, the all the parameters 
  must be set in advance, including I2CWriteLength, I2CReadLength,
  I2CCmd, and the I2cMasterBuffer which contains the stream
  command/data to the I2c slave device. 
  (1) If it's a I2C write only, the number of bytes to be written is 
  I2CWriteLength, I2CReadLength is zero, the content will be filled 
  in the I2CMasterBuffer. 
  (2) If it's a I2C read only, the number of bytes to be read is 
  I2CReadLength, I2CWriteLength is 0, the read value will be filled 
  in the I2CMasterBuffer. 
  (3) If it's a I2C Write/Read with repeated start, specify the 
  I2CWriteLength, fill the content of bytes to be written in 
  I2CMasterBuffer, specify the I2CReadLength, after the repeated 
  start and the device address with RD bit set, the content of the 
  reading will be filled in I2CMasterBuffer index at 
  I2CMasterBuffer[I2CWriteLength+2]. 
  
  e.g. Start, DevAddr(W), WRByte1...WRByteN, Repeated-Start, DevAddr(R), 
  RDByte1...RDByteN Stop. The content of the reading will be filled 
  after (I2CWriteLength + two devaddr) bytes. */

  /* Write SLA(W), address and one data byte */
  I2CWriteLength = 6;
  I2CReadLength = 0;
  I2CMasterBuffer[0] = PCF8594_ADDR;
  I2CMasterBuffer[1] = 0x00;		/* address */
  I2CMasterBuffer[2] = 0x55;		/* Data0 */
  I2CMasterBuffer[3] = 0xAA;		/* Data1 */
  I2CMasterBuffer[4] = 0x12;		/* Data0 */
  I2CMasterBuffer[5] = 0x34;		/* Data1 */
  I2CEngine();

  /* Be careful with below fixed delay. From device to device, or
  even same device with different write length, or various I2C clock, 
  below delay length may need to be changed accordingly. Having 
  a break point before Write/Read start will be helpful to isolate 
  the problem. */
  for ( i = 0; i < 0x200000; i++ );	/* Delay after write */

  for ( i = 0; i < BUFSIZE; i++ )
  {
	I2CSlaveBuffer[i] = 0x00;
  }
  /* Write SLA(W), address, SLA(R), and read one byte back. */
  I2CWriteLength = 2;
  I2CReadLength = 4;
  I2CMasterBuffer[0] = PCF8594_ADDR;
  I2CMasterBuffer[1] = 0x00;		/* address */
  I2CMasterBuffer[2] = PCF8594_ADDR | RD_BIT;
  I2CEngine();

  /* Check the content of the Master and slave buffer */
  while ( 1 );
}

/******************************************************************************
**                            End Of File
******************************************************************************/
