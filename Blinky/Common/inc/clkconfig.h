/****************************************************************************
 *   $Id:: clkconfig.h 4065 2010-07-30 02:19:37Z usb00423                   $
 *   Project: NXP LPC11xx software example
 *
 *   Description:
 *     This file contains definition and prototype for clock configuration.
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
****************************************************************************/
#ifndef __CLKCONFIG_H 
#define __CLKCONFIG_H

#define WDTCLK_SRC_IRC_OSC          0
#define WDTCLK_SRC_MAIN_CLK         1
#define WDTCLK_SRC_WDT_OSC          2

#define CLKOUTCLK_SRC_IRC_OSC       0
#define CLKOUTCLK_SRC_SYS_OSC       1
#define CLKOUTCLK_SRC_WDT_OSC       2
#define CLKOUTCLK_SRC_MAIN_CLK      3

void WDT_CLK_Setup(uint32_t timer_num);
void CLKOUT_Setup(uint32_t timer_num);
#endif /* end __CLKCONFIG_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
