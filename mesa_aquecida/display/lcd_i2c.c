/*
 * lcd_i2c.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Renan Augusto Starke
 *
 *      Adaptado de AVR e Arduino: Técnicas de Projeto, 2a ed. - 2012.
 *      Instituto Federal de Santa Catarina
 */


#include <stdio.h>
#include <msp430.h>

#include "lcd_i2c.h"

#include "../lib/i2c_master_g2452.h"

/* Variável byte de comando I2C
 * 0x08 -> Habilitação do Backlight */
uint8_t transmitData = 0x08;

volatile uint8_t data_i2c = 0;

void EnablePulse();

void EnablePulse(){
    SET_BIT(transmitData, E_I2C);
    i2c_write_single_byte(PCF_ADDR, transmitData);
    CLR_BIT(transmitData, E_I2C);
    i2c_write_single_byte(PCF_ADDR, transmitData);
}


/**
  * @brief  Envia um dado estático para o display: caractere ou comando.
  * @param c: valor do comando.
  * @param cd: 0 para comando. 1 para caractere.
  *
  * @retval Nenhum
  */
void SendCmd(uint8_t c, uint8_t cd)				//c é o dado  e cd indica se é instrução ou caractere
{
	if(cd==0)
		CLR_BIT(transmitData, RS_I2C);
	else
		SET_BIT(transmitData, RS_I2C);

	//primeiro nibble de dados - 4 MSB
	#if (NIBBLE_DADOS_I2C)								//compila código para os pinos de dados do LCD nos 4 MSB do PORT
	    transmitData = (transmitData & 0x0F)|(0xF0 & c);
	#else											//compila código para os pinos de dados do LCD nos 4 LSB do PORT
		data_i2c = (data_i2c & 0xF0)|(c>>4);
	#endif
	
    EnablePulse();

	//segundo nibble de dados - 4 LSB
	#if (NIBBLE_DADOS_I2C)								//compila código para os pinos de dados do LCD nos 4 MSB do PORT
	    transmitData = (transmitData & 0x0F) | (0xF0 & (c<<4));
	#else											//compila código para os pinos de dados do LCD nos 4 LSB do PORT
		data_i2c = (data_i2c & 0xF0) | (0x0F & c);
	#endif
	
	EnablePulse();
	
	if((cd==0) && (c<4))				//se for instrução de retorno ou limpeza espera LCD estar pronto
	    _delay_cycles(200000);
}

/**
  * @brief  Configura hardware: verificar lcd.h para mapa de pinos e nible de dados.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void LcdIinit()
{
    /* 0x08 -> Bit para habilitação do backlight */
    transmitData = 0x08;

    /* Configura pinos de controle */
    SET_BIT(transmitData, RS_I2C);
    SET_BIT(transmitData, E_I2C);

    /* Configure pinos de dados */
    #if (NIBBLE_DADOS_I2C)
        data_i2c |=  0xF0;
    #else
        data_i2c |=  0x0F;
    #endif

    i2c_write_single_byte(PCF_ADDR, transmitData);

    CLR_BIT(transmitData, RS_I2C);	//RS em zero indicando que o dado para o LCD será uma instrução
    CLR_BIT(transmitData, E_I2C);	//pino de habilitação em zero

    i2c_write_single_byte(PCF_ADDR, transmitData);

     _delay_cycles(200000);

    #if (NIBBLE_DADOS_I2C)
         transmitData = (transmitData & 0x0F) | 0x30;
    #else
        data_i2c = (data_i2c & 0xF0) | 0x03;
    #endif

     EnablePulse();			//habilitação respeitando os tempos de resposta do LCD
     _delay_cycles(200000);
     EnablePulse();
     _delay_cycles(200000);
     EnablePulse();	/*até aqui ainda é uma interface de 8 bits.
                    Muitos programadores desprezam os comandos acima, respeitando apenas o tempo de
                    estabilização da tensão (geralmente funciona). Se o LCD não for inicializado primeiro no
                    modo de 8 bits, haverá problemas se o microcontrolador for inicializado e o display já o tiver sido.*/

    //interface de 4 bits, deve ser enviado duas vezes (a outra está abaixo)
    #if (NIBBLE_DADOS_I2C)
        transmitData = (transmitData & 0x0F) | 0x20;
    #else
        data_i2c = (data_i2c & 0xF0) | 0x02;
    #endif

    EnablePulse();
    SendCmd(0x28,0); 		//interface de 4 bits 2 linhas (aqui se habilita as 2 linhas)
                            //são enviados os 2 nibbles (0x2 e 0x8)
    SendCmd(0x08,0);		//desliga o display
    SendCmd(0x01,0);		//limpa todo o display
    SendCmd(0x0C,0);		//mensagem aparente cursor inativo não piscando
    SendCmd(0x80,0);		//inicializa cursor na primeira posição a esquerda - 1a linha
}


void TurnOffBacklight(){
    transmitData = 0;
    i2c_write_single_byte(PCF_ADDR, transmitData);
}

void TurnOnBacklight(){
    /* 0x08 -> Bit para habilitação do backlight */
    transmitData = 0x08;
    i2c_write_single_byte(PCF_ADDR, transmitData);
}


/**
  * @brief  Escreve um string estática (sem printf) no LCD.
  * @param c: ponteiro para a string em RAM
  *
  * @retval Nenhum
  */
void WriteString(char *c)
{
   for (; *c!=0;c++) SendCmd(*c, LCD_DATA);
}
