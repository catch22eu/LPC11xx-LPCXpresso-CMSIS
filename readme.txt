/*****************************************************************************
 *   readme.txt:  Description of the LPC11xx Example Software Package
 *
 *   Copyright(C) 2010, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *
 *   2012.07.11 ver  1.01   (1) SWD communication failure during debug session issue fixed
 *							(2) timer16.c has been changed. PIO10_10/SCK0/CT16B0_MAT2 intialization has been disabled. User should enable if necessary.
 *							(3) As a consequence, the following projects have been changed ADC, SSP.
 *							(4) PMU project modified: Sleep/DeepSleep mode configuration changed. Read-me modified.
 ******************************************************************************/

/*****************************************************************************/
Software that is described herein is for illustrative purposes only which 
provides customers with programming information regarding the products.
This software is supplied "AS IS" without any warranties. NXP Semiconductors 
assumes no responsibility or liability for the use of the software, conveys no 
license or title under any patent, copyright, or mask work right to the 
product. NXP Semiconductors reserves the right to make changes in the 
software without notification. NXP Semiconductors also make no representation 
or warranty that such application will be suitable for the specified use without 
further testing or modification.
/*****************************************************************************/


The Description of the Example software
===================

This example demonstrates the use of build-in peripherals on the NXP
LPC11xx family microcontrollers.

The Example software includes, common library, peripheral APIs, and test modules
for the APIs. The common library include startup file, standard definition and
header files, processor specific setup module, generic interrupt related APIs, 
timer routine. The peripheral directories include, ADC, GPIO, timer, SPI, I2C, 
Watchdog timer, UART, external interrupt, various USB class drivers ,etc.

Depending on the configuration of LPC11xx, it may include a CAN controller
or a USB Device controller, or none of them. The header file of register 
definition, LPC11xx.h, the clock configuration, and the NVIC APIs, includes 
both CAN and USB, but may not apply to the MCU you are using.
  

Some external components, such as I2C temperature, SPI serial EEPROM, will be 
required to add on the board in order to complete the test below.



The directory tree and content of the sample software
===================

common
    -- inc
	-- lpc11xx.h		CMSIS Cortex-M0 Core Peripheral Access Layer Header 
				File for NXP LPC11xx Device Series 
	-- core_cm0.h		CMSIS Cortex-M0 Core Peripheral Access Layer Header File
	-- system_LPC11xx.h	CMSIS Cortex-M0 Device Peripheral Access Layer Header 
				File for the NXP LPC11xx Device Series
	-- type.h		Type definition Header file for NXP LPC11xx Family
	-- systick.h		Cortex M0 Systemtick header and definition 
	-- gpio.h		GPIO setting and I/O pin connfigured as external interrupt
				definition
	-- uart.h		UART setting header and definiton
	-- timer16.h		16-bit TIMER setting header and definition
	-- timer32.h		32-bit TIMER setting header and definition
	-- clkconfig.h          clock configuration header and definition  
    -- src
	-- core_cm0.c		CMSIS Cortex-M0 Core Peripheral Access Layer Source File
	-- startup_LPC11xx.s	CMSIS Cortex-M0 Core Device Startup File 
           			for the NXP LPC11xx Device Series
	-- system_LPC11xx.c	CMSIS Cortex-M0 Device Peripheral Access Layer Source
    				File for the NXP LPC11xx Device Series
	-- gpio.c		GPIO setting APIs and I/O pin connfigured as external 
				interrupt and interrupt handler
	-- uart.c		UART setting API and interrupt handler
	-- timer16.c		16-bit TIMER setting APIs and interrupt handler
	-- timer32.c		32-bit TIMER setting APIs and interrupt handler
	-- clkconfig.c		Misc. clock configuration setting and APIs in addition
				to system_lpc11xx.c  

Blinky
    -- blinky.c			General test, GPIO, Timer and NVIC test module, note: 
				API modules are in the COMMON directory and 
				shared and used by some other peripheral testing.

ADC
    -- adc.h			ADC header
    -- adc.c			ADC APIs
    -- adctest.c		ADC controller test module

GPIO
    -- gpiotest.c		External interrupt test module, APIs are 
				from COMMON directory

Systick
    -- systick.c		ARM Cortext M0 Core system tick test module, APIs 
				are from COMMON directory
                
I2C
    -- i2c.h			I2C header
    -- i2c.c			I2C APIs
    -- i2ctest.c		I2C test module

I2CSlave
    -- i2cslave.h		I2C slave header
    -- i2cslave.c		I2C slave APIs
    -- i2cslvtst.c		I2C slave test module

Timer32
    -- timer32test.c		32-bit Timer test module, note: API modules
				are in the COMMON directory and 
				shared and used by some other peripheral testing.

PWM
    -- pwmtest.c		PWM test module, note: PWM API modules
				are in the COMMON directory, shared and used 
				by some other peripheral testing.

UART
    -- uarttest.c		UART test module, note: UART API modules
				are in the COMMON directory, shared and used 
				by some other peripheral testing.
RS485
    -- rs485.h			RS485 header
    -- rs485.c			RS485 APIs
    -- rs485test.c		RS485 test module
WDT
    -- wdt.h			Watchdog timer header
    -- wdt.c			Watchdog timer APIs
    -- wdttest.c		Watchdog timer test module

CAN
    -- can.h			CAN header
    -- can.c			CAN APIs
    -- cantest.c		CAN test module

CAN on_chip
    -- rom_driver_CAN.h		CAN on-chip API function header
    -- rom_drivers.h		ROM drivers header
    -- main.c			CAN on-chip test module

CANopen on_chip
    -- rom_driver_CAN.h		CAN on-chip API function header
    -- rom_drivers.h		ROM drivers header
    -- main.c			CAN on-chip test module

