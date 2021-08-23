/*
 * wdt.c
 *
 *  Created on: Aug 23, 2021
 *      Author: xtarke
 */

#include <msp430.h>

#include "wdt.h"
#include "lib/bits.h"


void delay_wdt()
{
     WDTCTL = WDT_ADLY_250;

     /* Ativa IRQ do Watchdog */
     IE1 |= WDTIE;
     __bis_SR_register(CPUOFF + GIE);
}


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(WDT_VECTOR))) watchdog_timer (void)
#else
#error Compiler not supported!
#endif
{
    __bic_SR_register_on_exit(CPUOFF);

    CLR_BIT(IE1,WDTIE);

}
