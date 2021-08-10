/*
 *  i2c_master_g2553.c
 *
 *  Created on: May 28, 2020
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 *
 *
 *      - Biblioteca de comunicação I2C em modo Master
 *      - Baseado em msp430g2xx3_usci_i2c_standard_master.c de
 *      Nima Eskandari -- Texas Instruments Inc.
 *
 *                          .   .
 *                         /|\ /|\
 *               CI_xyz    10k 10k     MSP430G2452
 *              -------     |   |   -------------------
 *             |    SDA|<  -|---+->|P1.7/SDA           |-
 *             |       |    |      |                   |
 *             |       |    |      |                   |
 *             |       |    |      |                   |
 *             |    SCL|<----+-----|P1.6/SCL           |
 *              -------            |                   |
 *
 */
/* System includes */
#include <lib/i2c_master_g2452.h>
#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>

/* Project includes */


#ifndef __MSP430G2452__
#error "Library no supported/validated in this device."
#endif

typedef enum {
    START_CONDITION = 0,
    ADDR_ACK_NACK = 2,
    ADDR_PROCESS_ACK_NACK = 4,
    DATA_ACK_NACK = 6,
    DATA_PROCESS_ACK_NACK = 8,
    STOP_CONDITION = 10
} i2c_fsm_t;


struct i2c_status_t {
    /* Used to track the state of the software state machine*/
    i2c_fsm_t state;
    /* Device Addr */
    uint8_t device_addr;
    /* TX: Pointers and index */
    uint8_t byte_to_send;
};

/* Estado do módulo I2C */
volatile struct i2c_status_t i2c_status = {0};

void init_i2c_master_mode()
{
    /* P1.6 and P1.7 USCI mode */
    P1SEL |= BIT6 + BIT7;

    /* Enable internal pull-ups */
    P1OUT = BIT6 + BIT7;
    P1REN |= BIT6 + BIT7;

    /* Port & USI mode setup */
    USICTL0 = USIPE6+USIPE7+USIMST+USISWRST;
    /* Enable I2C mode & USI interrupt */
    USICTL1 = USII2C+USIIE;
    /* Setup USI clocks: SCL = SMCLK/8 (~125kHz) */
    USICKCTL = USIDIV_3+USISSEL_2+USICKPL;
    /* Disable automatic clear control */
    USICNT |= USIIFGCC;
    /* Enable USI */
    USICTL0 &= ~USISWRST;
    /* Clear pending flag */
    USICTL1 &= ~USIIFG;
}

int I2C_State = 0;

/**
  * @brief  Escreve um byte no barramento I2C.
  *         Utiliza IRQ de transmissão para o envio do byte.
  *
  *         Use com IRS habilitadas.
  *
  * @param  dev_addr: endereço I2C dos dispositivo.
  *         byte: byte a ser envidado.
  *
  * @retval i2c_mode: possíveis erros de transmissão.
  */
uint8_t i2c_write_single_byte(uint8_t dev_addr, uint8_t byte){

    while (i2c_status.state != START_CONDITION);

    i2c_status.state = START_CONDITION;
    i2c_status.device_addr = dev_addr << 1;
    i2c_status.byte_to_send = byte;

    /* Set flag and start communication */
    USICTL1 |= USIIFG;

    /* Sleep */
    LPM0;

    return i2c_status.state;
}



/******************************************************
// USI interrupt service routine
******************************************************/
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = USI_VECTOR
__interrupt void USI_TXRX (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USI_VECTOR))) USI_TXRX (void)
#else
#error Compiler not supported!
#endif
{
    switch(i2c_status.state)
    {
    /* Generate Start Condition & send address to slave */
    case START_CONDITION:
        /*  Generate Start Condition */
        USISRL = 0x00;
        USICTL0 |= USIGE+USIOE;
        USICTL0 &= ~USIGE;
        /* transmit address, R/W = 0 */
        USISRL = i2c_status.device_addr;
        USICNT = (USICNT & 0xE0) + 0x08;
        i2c_status.state = ADDR_ACK_NACK;
        break;

    /* Receive Address Ack/Nack bit */
    case ADDR_ACK_NACK:
        /* SDA = input */
        USICTL0 &= ~USIOE;
        /* Bit counter = 1, receive (N)Ack bit */
        USICNT |= 0x01;
        i2c_status.state = ADDR_PROCESS_ACK_NACK;
        break;

    /* Process Address Ack/Nack & handle data TX */
    case ADDR_PROCESS_ACK_NACK:
        /* SDA = output */
        USICTL0 |= USIOE;

        /* If Nack received, send stop */
        if (USISRL & 0x01)  {
            USISRL = 0x00;
            /* Bit counter = 1, SCL high, SDA low */
            USICNT |=  0x01;
            i2c_status.state = STOP_CONDITION;
        }
        else {
            /* Ack received, TX data to slave */
            USISRL = i2c_status.byte_to_send;
            /* Bit counter = 8, start TX */
            USICNT |=  0x08;
            i2c_status.state = DATA_ACK_NACK;
        }
        break;

    /* Receive Data Ack/Nack bit */
    case DATA_ACK_NACK:
        /* SDA = input */
        USICTL0 &= ~USIOE;
        /* Bit counter = 1, receive (N)Ack bit */
        USICNT |= 0x01;
        i2c_status.state = DATA_PROCESS_ACK_NACK;
        break;

    /* Process Data Ack/Nack & send Stop */
    case DATA_PROCESS_ACK_NACK:
        USICTL0 |= USIOE;

        /* ToDo: Error reporting
         * If Nack received
        if (USISRL & 0x01)
            P1OUT |= 0x01;
        // Ack received
        else
        {
            P1OUT &= ~0x01;
        }
        */

        /* Send stop */
        USISRL = 0x00;
        /* Bit counter = 1, SCL high, SDA low */
        USICNT |=  0x01;
        i2c_status.state = STOP_CONDITION;
        break;

    /* Generate Stop Condition */
    case STOP_CONDITION:
        /* USISRL = 1 to release SDA */
        USISRL = 0x0FF;
        /* Transparent latch enabled */
        USICTL0 |= USIGE;
        /* Latch/SDA output disabled */
        USICTL0 &= ~(USIGE+USIOE);
        i2c_status.state = START_CONDITION;
        LPM0_EXIT;
        break;
    }

    USICTL1 &= ~USIIFG;
}
