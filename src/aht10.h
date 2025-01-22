
/**
 ******************************************************************************
 * @file    aht10.h
 * @author  - Anthony E.Raterta
 * @version V1.0.0
 * @date    22-Jan-2025
 * @brief   Contains all the prototypes for the aht10.C
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 mcu-dev
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#ifndef AHTH10_H
#define AHTH10_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "utils/i2c.h"
#include "utils/utils.h"

/*******************************STATUSES***************************************/
typedef enum {
  AHT10_STATUS_SUCCESS   = 0,
  AHT10_STATUS_API_ERR   = -1,
  AHT10_STATUS_INPUT_ERR = -2,
  AHT10_STATUS_INIT_ERR  = -3,
} AHT10_RETURN_STATUS;

/*****************************ID REGISTERS*************************************/

#define AHT10_I2C_ADDRESS 0x38

/**********************************HANDLES*************************************/

typedef struct {
  bool is_Setup;
} aht10_dev;

typedef struct {
  bool is_Setup;
} aht10_init_param;

int8_t aht10_write_register_value(uint8_t dev_addr, uint8_t *data_buffer);

int8_t aht10_multiple_write_register_value(uint8_t dev_addr,
                                           uint8_t *data_buffer,
                                           uint32_t bytecount);

int8_t aht10_read_register_value(uint8_t address, uint8_t *val);

int8_t aht10_setup(aht10_dev *device, aht10_init_param init_param);

#endif /*AHTH10_H*/