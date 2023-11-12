/*****************************************************************
 * @file    i2c_hal.h
 * @author  Sanchitha Dias
 * @date    12/11/2024
 * @brief   Contains all the interfaces of I2C communication of
 *          the Magnetometer Test Application.
******************************************************************/
#ifndef I2C_HAL_H
#define I2C_HAL_H

#include "board.h"
#include "stdint.h"

extern int32_t i2c_read(uint8_t bus_address, uint8_t register_address, uint8_t *buffer,
uint16_t length);

extern int32_t i2c_write(uint8_t bus_address, uint8_t register_address, uint8_t *data,
uint16_t length);

#endif
/******************************************************************
*********                       EOF                       *********
*******************************************************************
********* Dev. by Sanchitha Dias (sanchithadias@gmail.com)*********
******************************************************************/