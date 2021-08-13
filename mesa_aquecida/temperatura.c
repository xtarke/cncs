/*
 * temperatura.c
 *
 *  Created on: Aug 10, 2021
 *      Author: Renan Augusto Starke
 */

#include <msp430.h>
#include <stdint.h>

#include "lib/bits.h"
#include "lib/gpio.h"

#define BUTTON_PORTS P2
#define BUTTON_ON_OFF BIT0
#define BUTTON_INC BIT1
#define BUTTON_DEC BIT2

#define BUTTON_SAMPLES (2)

/* Local buffers for simple digital filter */
static volatile uint16_t adc_buffer[8] = {0};
static volatile uint16_t sum_adc = 0;

static volatile uint8_t on_off = 0;
static volatile uint8_t set_point = 60;

void init_hardware_temperatura(){

    /* Buttons config */
    PORT_REN(BUTTON_PORTS) |= (BUTTON_ON_OFF | BUTTON_INC | BUTTON_DEC);
    PORT_OUT(BUTTON_PORTS) |= (BUTTON_ON_OFF | BUTTON_INC | BUTTON_DEC);


    /* Timer triggered, repeated channel 2 */
    ADC10CTL1 = ADC10DIV_3 + INCH_3 + SHS_1 + CONSEQ_2;
    /* REF=2.5V*/
    ADC10CTL0 = SREF_1 + ADC10SHT_3 + REF2_5V + ADC10IE + REFON + ADC10ON;

    /* Delay to allow Ref to settle */
    _delay_cycles(5000);

    TACCR0 = 30;                              // Delay to allow Ref to settle
    TACCTL0 |= CCIE;


    ADC10CTL0 |= ENC;
    /* Toggle trigger ADC on TAR = 0 (CCR1 = 0) */
    TACCTL1 = OUTMOD_4;
    /* SMCLK, Continuous up mode, SMCLK / 2  */
    TACTL =  TASSEL_2 | MC_2 ;



}


uint16_t get_temp(){
    return sum_adc >> 3;
}

uint8_t get_on_off(){
    return on_off;
}

uint8_t get_set_point(){
    return set_point;
}


/* ADC10 Interrupt Service Routine */
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC10_VECTOR))) ADC10_ISR (void)
#else
#error Compiler not supported!
#endif
{
    static uint8_t i = 0;
    uint16_t adc_value = ADC10MEM;

    sum_adc -=  adc_buffer[i];
    adc_buffer[i] = adc_value;
    sum_adc += adc_value;
    i++;
    i = i & 0x7;

    CPL_BIT(P1OUT,BIT1);
}

/* TimerA Interrupt Service Routine */
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TA0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) ta0_isr (void)
#else
#error Compiler not supported!
#endif
{
    /* Debug
    CPL_BIT(P1OUT,BIT0); */

    static uint8_t counter = BUTTON_SAMPLES;

    /* Se botão apertado: borda de descida */
    if (!TST_BIT(PORT_IN(BUTTON_PORTS), BUTTON_ON_OFF))  {
        /* Se contagem = 0, debounce terminado */
        if (!(--counter)) {
            /* Colocar aqui código da aplicação referente ao botão */
            CPL_BIT(on_off,BIT0);

            /* Acorda função main */
            __bic_SR_register_on_exit(LPM0_bits);

        }
    }
    else if (!TST_BIT(PORT_IN(BUTTON_PORTS), BUTTON_INC))  {
        /* Se contagem = 0, debounce terminado */
        if (!(--counter)) {
            /* Colocar aqui código da aplicação referente ao botão */
            set_point++;

            /* Acorda função main */
            __bic_SR_register_on_exit(LPM0_bits);

        }
    }
    else if (!TST_BIT(PORT_IN(BUTTON_PORTS), BUTTON_DEC))  {
        /* Se contagem = 0, debounce terminado */
        if (!(--counter)) {
            /* Colocar aqui código da aplicação referente ao botão */
            set_point--;

            /* Acorda função main */
            __bic_SR_register_on_exit(LPM0_bits);

        }
    }
    else
        counter = BUTTON_SAMPLES;
}


