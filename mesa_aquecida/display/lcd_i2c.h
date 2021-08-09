#ifndef _LCD_H
#define _LCD_H


#include <stdio.h>
#include <stdint.h>

#include "../lib/bits.h"

#define PCF_ADDR 0x27           //endereço do periérico com os 8 bits ( 0100 A2 A1 A0 0 ) LSB deve ser 0 para escrita
#define NIBBLE_DADOS_I2C    1   //0 para via de dados do LCD nos 4 LSBs do PORT empregado (Px0-D4, Px1-D5, Px2-D6, Px3-D7)
                                //1 para via de dados do LCD nos 4 MSBs do PORT empregado (Px4-D4, Px5-D5, Px6-D6, Px7-D7)

#define BL_I2C          3     // Bit para ligar/desligar o Backlight
#define E_I2C           2     // Bit de Habilitacao do LCD (enable)
#define RW_I2C          1     // Bit para informar escrita ou leitura
#define RS_I2C          0     // Bit para informar se o dado e uma instrucao ou caracter


enum {LCD_CMD = 0, LCD_DATA = 1  };

void init();

/* Comandos e escrita estatica */
void SendCmd(uint8_t c, uint8_t cd);
void WriteString(char *c);

void TurnOffBacklight();
void TurnOnBacklight();


#endif
