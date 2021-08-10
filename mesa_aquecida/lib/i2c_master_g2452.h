/*
 * i2c_master_g2553.h
 *
 *  Created on: May 28, 2020
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#ifndef LIB_I2C_MASTER_G2452_H_
#define LIB_I2C_MASTER_G2452_H_

#include <stdint.h>

void init_i2c_master_mode();
uint8_t i2c_write_single_byte(uint8_t dev_addr, uint8_t byte);

#endif /* LIB_I2C_MASTER_G2452_H_ */
