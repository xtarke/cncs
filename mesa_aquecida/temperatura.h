/*
 * temperatura.h
 *
 *  Created on: Aug 10, 2021
 *      Author: xtarke
 */

#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

#include <stdint.h>

void init_hardware_temperatura();

uint16_t get_temp();
uint8_t get_on_off();
uint8_t get_set_point();

void turn_on();
void turn_off();

#endif /* TEMPERATURA_H_ */
