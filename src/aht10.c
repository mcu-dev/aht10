/**
 ******************************************************************************
 * @file    aht10.c
 * @author  - Anthony E.Raterta
 * @version V1.0.0
 * @date    22 -Jan-2025
 * @brief   Contains all the functionalities to control the AHT10
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

#include "aht10.h"

/**
 * @brief Write a register value from the BMP180.
 *
 * @param dev_addr The register address to write the value from.
 * @param data_buffer Pointer to the buffer containing the data to be written.
 *
 * @return
 *   - 0 on success.
 *   - Non-zero error code on failure.
 */

int8_t aht10_write_register_value(uint8_t dev_addr, uint8_t *data_buffer) {
  return i2c_write_bytes(dev_addr, data_buffer);
}

/**
 * @brief Read a register value from the BMP180.
 *
 * @param address The register address to read the value from.
 * @param val Pointer to a variable to store the read register value.
 *
 * @return
 *   - 0 on success.
 *   - Non-zero error code on failure.
 */
int8_t aht10_read_register_value(uint8_t address, uint8_t *val) {
  if (i2c_read_byte(AHT10_I2C_ADDRESS, address, val) !=
      AHT10_STATUS_SUCCESS) {
    return AHT10_STATUS_API_ERR;
  }
  return AHT10_STATUS_SUCCESS;
}

int8_t aht10_setup(aht10_dev *device, aht10_init_param init_param) {
  int8_t ret = 0;

  if (!i2c_init()) {
    return AHT10_STATUS_INIT_ERR;
  }

  return ret;
}