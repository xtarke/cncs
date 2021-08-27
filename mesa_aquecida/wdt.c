/*
 * wdt.c
 *
 *  Created on: Aug 23, 2021
 *      Author: xtarke
 */

#include <msp430.h>
#include <stdint.h>

#include "wdt.h"
#include "lib/bits.h"

volatile uint16_t counter = 0;

/* Sleep for approximate 320 ms */
void delay_wdt()
{
    counter = 10;
    /* 32ms interval (default) @ 1MHZ */
    WDTCTL = WDT_MDLY_32;
    /* Ativa IRQ do Watchdog */
    IE1 |= WDTIE;

    __bis_SR_register(LPM0_bits + GIE);

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
    counter--;

    /* Wake up after the delay */
    if (!counter){
        WDTCTL = WDTPW | WDTHOLD;
        /* CPL_BIT(P1OUT, BIT0); */
        __bic_SR_register_on_exit(CPUOFF);
    }

}
