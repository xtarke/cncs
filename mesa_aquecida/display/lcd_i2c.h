#ifndef _LCD_H
#define _LCD_H


#include <stdio.h>
#include <stdint.h>

#include "../lib/bits.h"

/* Endereço do periérico com os 8 bits ( 0100 A2 A1 A0 0 ) LSB deve ser 0 para escrita */
#define PCF_ADDR 0x27

/* 0 para via de dados do LCD nos 4 LSBs do PORT empregado (Px0-D4, Px1-D5, Px2-D6, Px3-D7)
 * 1 para via de dados do LCD nos 4 MSBs do PORT empregado (Px4-D4, Px5-D5, Px6-D6, Px7-D7) */
#define NIBBLE_DADOS_I2C    1

/* Bit para ligar/desligar o Backlight */
#define BL_I2C          BIT3
/* Bit de Habilitacao do LCD (enable) */
#define E_I2C           BIT2
/* Bit para informar escrita ou leitura */
#define RW_I2C          BIT1
/* Bit para informar se o dado e uma instrucao ou caracter */
#define RS_I2C          BIT0

enum DISPLAY_CMDS {
    LCD_TURN_OFF = 0x08,
    LCD_CLEAR = 0x01,
    LCD_LINE_0 = 0x80,
    LCD_LINE_1 = 0xC0
};

enum {LCD_CMD = 0, LCD_DATA = 1  };

void LcdIinit();

/* Comandos e escrita estatica */
void SendCmd(uint8_t c, uint8_t cd);
void WriteString(char *c);

void TurnOffBacklight();
void TurnOnBacklight();


#endif
