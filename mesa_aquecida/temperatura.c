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

#define POWER_PORT  P1
#define POWER_PIN   BIT3

#define BUTTON_SAMPLES (2)


const uint8_t ntc_table[] = {86, 86,85,85,85,85,85,84,84,84,84,83,83,83,83,83,82,82,82,82,82,81,81,81,81,80,80,80,80,80,79,79,79,79,79,78,78,78,
    78,78,77,77,77,77,77,76,76,76,76,76,75,75,75,75,75,75,74,74,74,74,74,73,73,73,73,73,72,72,72,72,72,72,71,71,71,
    71,71,71,70,70,70,70,70,69,69,69,69,69,69,68,68,68,68,68,68,67,67,67,67,67,67,66,66,66,66,66,66,66,65,65,65,65,65,
    65,64,64,64,64,64,64,64,63,63,63,63,63,63,62,62,62,62,62,62,62,61,61,61,61,61,61,61,60,60,60,60,60,60,60,59,59,59,
    59,59,59,59,59,58,58,58,58,58,58,58,58,57,57,57,57,57,57,57,56,56,56,56,56,56,56,56,55,55,55,55,55,55,55,55,55,54,
    54,54,54,54,54,54,54,54,53,53,53,53,53,53,53,53,52,52,52,52,52,52,52,52,52,52,51,51,51,51,51,51,51,51,51,50,50,50,
    50,50,50,50,50,50,50,49,49,49,49,49,49,49,49,49,49,49,48,48,48,48,48,48,48,48,48,48,48,47,47,47,47,47,47,47,47,47,
    47,47,46,46,46,46,46,46,46,46,46,46,46,46,45,45,45,45,45,45,45,45,45,45,45,45,44,44,44,44,44,44,44,44,44,44,44,44,
    44,43,43,43,43,43,43,43,43,43,43,43,43,43,43,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,41,41,41,41,41,41,41,41,
    41,41,41,41,41,41,41,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,
    39,39,39,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,
    37,37,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,
    35,35,35,35,35,35,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,33,33,33,33,33,33,33,33,33,
    33,33,33,33,33,33,33,33,33,33,33,33,33,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
    30,30,30,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,28,28,28,28,28,28,28,28,28,28,28,28,28,28,
    28,28,28,28,28,28,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,26,26,26,
    26,26,26,26,26,26,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
    24,24,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,21,21,21,21,21,21,
    21,21,21,21,21,21,21,20,20,20,20,20,20,20,20,20,20,20,20,20,19,19,19,19,19,19,19,19,19,19,19,19,19,18,18,18,18,18,
    18,18,18,18,18,18,18,17,17,17,17,17,17,17,17,17,17,17,16,16,16,16,16,16,16,16,16,16,16,15,15,15,15,15,15,15,15,15,15,14};




/* Local buffers for simple digital filter */
static volatile uint16_t adc_buffer[8] = {0};
static volatile uint16_t sum_adc = 0;

static volatile uint8_t on_off = 0;
static volatile uint8_t set_point = 40;

void init_hardware_temperatura(){

    /* Buttons config */
    PORT_REN(BUTTON_PORTS) = (BUTTON_ON_OFF | BUTTON_INC | BUTTON_DEC);
    PORT_OUT(BUTTON_PORTS) = (BUTTON_ON_OFF | BUTTON_INC | BUTTON_DEC);

    PORT_DIR(POWER_PORT) |= POWER_PIN;
    SET_BIT(PORT_OUT(POWER_PORT), POWER_PIN);


    /* Timer triggered, repeated channel 2 */
    ADC10CTL1 = ADC10DIV_3 + INCH_0 + SHS_1 + CONSEQ_2;
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
    int16_t data = (sum_adc >> 3) - 100;

    uint16_t temp = 0;

    if (data < 0)
        temp = ntc_table[0];
    else if (data > 800)
        temp = ntc_table[799];
    else
        temp = ntc_table[data];

    return temp;
}

uint8_t get_on_off(){
    return on_off;
}

uint8_t get_set_point(){
    return set_point;
}

void turn_on(){
    CLR_BIT(PORT_OUT(POWER_PORT),POWER_PIN);
}

void turn_off(){
    SET_BIT(PORT_OUT(POWER_PORT),POWER_PIN);
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

            if (on_off)
                CLR_BIT(PORT_OUT(POWER_PORT),POWER_PIN);
            else
                SET_BIT(PORT_OUT(POWER_PORT),POWER_PIN);

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


