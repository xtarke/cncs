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
 *               CI_xyz    10k 10k     MSP430G2xx3
 *              -------     |   |   -------------------
 *             |    SDA|<  -|---+->|P1.7/UCB0SDA       |-
 *             |       |    |      |                   |
 *             |       |    |      |                   |
 *             |       |    |      |                   |
 *             |    SCL|<----+-----|P1.6/UCB0SCL       |
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

struct i2c_status_t {
    /* Used to track the state of the software state machine*/
    i2c_mode state;
    /* Device Addr */
    uint8_t device_addr;
    /* RX: Pointers and index */
    uint8_t *data_to_receive;
    uint8_t rx_byte_count;
    uint8_t rx_index;
    /* TX: Pointers and index */
    uint8_t *data_to_send;
    uint8_t tx_byte_count;
    uint8_t tx_index;
};

/* Estado do módulo I2C */
volatile struct i2c_status_t i2c_status = {0};

void init_i2c_master_mode()
{
    /* Muda P1.6 e P1.7 para modo USCI_B0 */
    P1SEL |= BIT6 + BIT7;

    /* Enable internal pull-ups */
    P1OUT = BIT6 + BIT7;
    P1REN |= BIT6 + BIT7;

    USICTL0 = USIPE6+USIPE7+USIMST+USISWRST; // Port & USI mode setup
    USICTL1 = USII2C+USIIE;              // Enable I2C mode & USI interrupt
    USICKCTL = USIDIV_3+USISSEL_2+USICKPL; // Setup USI clocks: SCL = SMCLK/8 (~125kHz)
    USICNT |= USIIFGCC;                  // Disable automatic clear control
    USICTL0 &= ~USISWRST;                // Enable USI
    USICTL1 &= ~USIIFG;                  // Clear pending flag
}

/**
  * @brief  Lê registradores de um dispositivo I2C.
  *         Utiliza IRQ de transmissão para o envio dos bytes.
  *
  *         Use com IRS habilitadas.
  *
  * @param  dev_addr: endereço I2C dos dispositivo.
  *         reg_addr: registrador inicial.
  *         count: número de bytes.
  *         data: vetor onde será armazenado os dados recebidos.
  *
  * @retval i2c_mode: possíveis erros de transmissão.
  */
i2c_mode i2c_master_read_reg(uint8_t dev_addr, uint8_t reg_addr, uint8_t count, uint8_t *data)
{
    /* Initialize state machine */
    i2c_status.state = TX_REG_ADDRESS_MODE;
    i2c_status.data_to_receive = data;

    i2c_status.device_addr = reg_addr;
    i2c_status.rx_byte_count = count;
    i2c_status.tx_byte_count = 0;
    i2c_status.rx_index = 0;
    i2c_status.tx_index = 0;

    /* Initialize slave address and interrupts */
//    UCB0I2CSA = dev_addr;
//    IFG2 &= ~(UCB0TXIFG + UCB0RXIFG);       // Clear any pending interrupts
//    IE2 &= ~UCB0RXIE;                       // Disable RX interrupt
//    IE2 |= UCB0TXIE;                        // Enable TX interrupt
//
//    UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition
    __bis_SR_register(CPUOFF + GIE);              // Enter LPM0 w/ interrupts

    return  i2c_status.state;
}



char MST_Data = 0xff;                     // Variable for transmitted data
char SLV_Addr = 0x27;                  // Address is 0x48 << 1 bit + 0 for Write
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
i2c_mode i2c_write_single_byte(uint8_t dev_addr, uint8_t byte){

    MST_Data = byte;

    /* Set flag and start communication */
    USICTL1 |= USIIFG;

    /* Sleep */
    LPM0;

}


/**
  * @brief  Escreve nos registradores de um dispositivo I2C.
  *         Utiliza IRQ de transmissão para o envio dos bytes.
  *
  *         Use com ISR habilitadas.
  *
  * @param  dev_addr: endereço I2C dos dispositivo.
  *         reg_addr: registrador inicial.
  *         reg_data: dados enviados. Devem permanacer estáticos durante a transmissão.
  *         count: número de bytes.
  *
  * @retval i2c_mode: possíveis erros de transmissão.
  */
i2c_mode i2c_master_write_reg(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count)
{
    /* Initialize state machine */
    i2c_status.state = TX_REG_ADDRESS_MODE;
    i2c_status.device_addr = reg_addr;
    i2c_status.data_to_send = reg_data;

    /* Use pointers from main:
     *
     * Copy register data to TransmitBuffer
     *
    CopyArray(reg_data, TransmitBuffer, count); */

    i2c_status.tx_byte_count = count;
    i2c_status.rx_byte_count = 0;
    i2c_status.rx_index = 0;
    i2c_status.tx_index = 0;

    /* Initialize slave address and interrupts */
//    UCB0I2CSA = dev_addr;
//    IFG2 &= ~(UCB0TXIFG + UCB0RXIFG);       // Clear any pending interrupts
//    IE2 &= ~UCB0RXIE;                       // Disable RX interrupt
//    IE2 |= UCB0TXIE;                        // Enable TX interrupt
//
//    UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition

    //__bis_SR_register(CPUOFF + GIE);       / Enter LPM0 w/ interrupts: Use no hardware real
    __bis_SR_register(GIE);                // Enable interrupts: Use no Proteus

    return i2c_status.state;
}


void CopyArray(uint8_t *source, uint8_t *dest, uint8_t count)
{
    uint8_t copyIndex = 0;
    for (copyIndex = 0; copyIndex < count; copyIndex++)
    {
        dest[copyIndex] = source[copyIndex];
    }
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
  switch(I2C_State)
    {
      case 0: // Generate Start Condition & send address to slave
              P1OUT |= 0x01;           // LED on: sequence start
              USISRL = 0x00;           // Generate Start Condition...
              USICTL0 |= USIGE+USIOE;
              USICTL0 &= ~USIGE;
              USISRL = SLV_Addr << 1;       // ... and transmit address, R/W = 0
              USICNT = (USICNT & 0xE0) + 0x08; // Bit counter = 8, TX Address
              I2C_State = 2;           // Go to next state: receive address (N)Ack
              break;

      case 2: // Receive Address Ack/Nack bit
              USICTL0 &= ~USIOE;       // SDA = input
              USICNT |= 0x01;          // Bit counter = 1, receive (N)Ack bit
              I2C_State = 4;           // Go to next state: check (N)Ack
              break;

      case 4: // Process Address Ack/Nack & handle data TX
              USICTL0 |= USIOE;        // SDA = output
              if (USISRL & 0x01)       // If Nack received...
              { // Send stop...
                USISRL = 0x00;
                USICNT |=  0x01;       // Bit counter = 1, SCL high, SDA low
                I2C_State = 10;        // Go to next state: generate Stop
                P1OUT |= 0x01;         // Turn on LED: error
              }
              else
              { // Ack received, TX data to slave...
                USISRL = MST_Data;     // Load data byte
                USICNT |=  0x08;       // Bit counter = 8, start TX
                I2C_State = 6;         // Go to next state: receive data (N)Ack
                P1OUT &= ~0x01;        // Turn off LED
              }
              break;

      case 6: // Receive Data Ack/Nack bit
              USICTL0 &= ~USIOE;       // SDA = input
              USICNT |= 0x01;          // Bit counter = 1, receive (N)Ack bit
              I2C_State = 8;           // Go to next state: check (N)Ack
              break;

      case 8: // Process Data Ack/Nack & send Stop
              USICTL0 |= USIOE;
              if (USISRL & 0x01)       // If Nack received...
                P1OUT |= 0x01;         // Turn on LED: error
              else                     // Ack received
              {
                MST_Data++;            // Increment Master data
                P1OUT &= ~0x01;        // Turn off LED
              }
              // Send stop...
              USISRL = 0x00;
              USICNT |=  0x01;         // Bit counter = 1, SCL high, SDA low
              I2C_State = 10;          // Go to next state: generate Stop
              break;

      case 10:// Generate Stop Condition
              USISRL = 0x0FF;          // USISRL = 1 to release SDA
              USICTL0 |= USIGE;        // Transparent latch enabled
              USICTL0 &= ~(USIGE+USIOE);// Latch/SDA output disabled
              I2C_State = 0;           // Reset state machine for next transmission
              LPM0_EXIT;               // Exit active for next transfer
              break;
    }

  USICTL1 &= ~USIIFG;                  // Clear pending flag
}
