/*
 * 04_main_simple_clock_g2553.c
 *
 *  Created on: Mar 23, 2020
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <msp430.h> 

#include "wdt.h"
#include "temperatura.h"
#include "display/lcd_i2c.h"
#include "lib/i2c_master_g2452.h"


#ifndef __MSP430G2452__
#error "Clock system not supported for this device"
#endif


#define CLOCK_8MHz

void init_clock_system();


/**
 * main.c
 */

int main(void)
{
    volatile unsigned int i;
    char string[16];

    /* Stop watchdog timer */
    WDTCTL = WDTPW | WDTHOLD;

    init_i2c_master_mode();

    __enable_interrupt();

    LcdIinit();
    init_hardware_temperatura();

    while(1){

        volatile uint8_t set_point = get_set_point();
        volatile uint8_t temperature = get_temp();
        volatile uint8_t on_off = get_on_off();

        snprintf(string, sizeof(string), "%d C    %d C ", temperature, set_point);

        SendCmd(LCD_LINE_0, LCD_CMD);
        WriteString(string);

        SendCmd(LCD_LINE_1, LCD_CMD);

        if (on_off){
            WriteString("On ");

            if (temperature > set_point)
                turn_off();
            else if (temperature < set_point)
                turn_on();
        }
        else {

            WriteString("Off");
            turn_off();
        }

        delay_wdt();
        //__delay_cycles(100000);

    }

    return 0;
}



/**
 * @brief  Configura sistema de clock para usar o Digitally Controlled Oscillator (DCO).
 *         Utililiza-se as calibrações internas gravadas na flash.
 *         Exemplo baseado na documentação da Texas: msp430g2xxx3_dco_calib.c
 * @param  none
 *
 * @retval none
 */
void init_clock_system(){

#ifdef CLOCK_1MHz
    /* Se calibração foi apagada, para aplicação */
    if (CALBC1_1MHZ==0xFF)
        while(1);
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
#endif

#ifdef CLOCK_8MHz

    /* Se calibração foi apagada, para aplicação */
    if (CALBC1_8MHZ==0xFF)
        while(1);

    DCOCTL = 0;
    BCSCTL1 = CALBC1_8MHZ;
    DCOCTL = CALDCO_8MHZ;

    /* Outras fonte de clock devem ser configuradas também *
     * de acordo com a aplicação  */
#endif

#ifdef CLOCK_12MHz
    /* Se calibração foi apagada, para aplicação */
    if (CALBC1_12MHZ==0xFF)
        while(1);
    DCOCTL = 0;
    BCSCTL1 = CALBC1_12MHZ;
    DCOCTL = CALDCO_12MHZ;
#endif

#ifdef CLOCK_16MHz
    /* Se calibração foi apagada, para aplicação */
    if (CALBC1_16MHZ==0xFF)
        while(1);
    DCOCTL = 0;
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
#endif

}
