/*****************************************************************
 * @file    main.c
 * @author  Sanchitha Dias
 * @date    12/11/2024
 * @brief   Main application for testing the Magnetometer
******************************************************************/
/******************************************************************
*********                       Includes                  *********
******************************************************************/
#include "Board.h"
#include "Defines.h"

#include "i2c_hal.h"
#include "lis3mdl_reg.h"
/******************************************************************
*********                  Local Defines                  *********
******************************************************************/

/******************************************************************
*********                Local Enumerations               *********
******************************************************************/

/******************************************************************
*********                  Local Objects                  *********
******************************************************************/

/******************************************************************
*********                  Local Variables                *********
******************************************************************/

/******************************************************************
*********          Local Function Definitions             *********
******************************************************************/

/******************************************************************
*********              Application Firmware               *********
******************************************************************/
void main()
{
    uint8_t bus_address = LIS3MDL_ID;
    int16_t data_raw_magnetic;
    uint8_t who_am_i, rst, int_pin_state = PROPERTY_DISABLE;
    lis3mdl_fs_t dev_full_scale = LIS3MDL_16_GAUSS;
    lis3mdl_om_t device_data_rate = LIS3MDL_LP_Hz625;

    /* Initialize mems driver interface */
    stmdev_ctx_t dev_ctx;
    dev_ctx.write_reg = i2c_write;
    dev_ctx.read_reg = i2c_read;
    dev_ctx.handle = &bus_address;

    /* Check device ID */
    lis3mdl_device_id_get(&dev_ctx, &who_am_i);

    if (who_am_i != LIS3MDL_ID)
    {
        while (1); /*manage here device not found */
    }

    /* Restore default configuration */
    lis3mdl_reset_set(&dev_ctx, PROPERTY_ENABLE);

    do
    {
        lis3mdl_reset_get(&dev_ctx, &rst);
    } while (rst);

    /* Get full scale */
    lis3mdl_full_scale_get(&dev_ctx, &dev_full_scale);

    printf("1 - Device's Full Scale: %d\r\n", dev_full_scale);

    /* Get Output Data Rate */
    lis3mdl_data_rate_get(&dev_ctx, &device_data_rate);

    printf("2 - Device’s Current Output Data Rate: %d\r\n", device_data_rate);

    device_data_rate = LIS3MDL_UHP_1Hz25;

    /* Set Output Data Rate */
    lis3mdl_data_rate_set(&dev_ctx, device_data_rate);

    /* Get Output Data Rate */
    lis3mdl_data_rate_get(&dev_ctx, &device_data_rate);

    printf("3 - Device’s New Output Data Rate: %d\r\n", device_data_rate);

    lis3mdl_int_generation_get(&dev_ctx, &int_pin_state);

    printf("4 - Device’s Current Interrupt Pin State: %d\r\n", int_pin_state);

    lis3mdl_int_generation_set(&dev_ctx, PROPERTY_ENABLE);

    lis3mdl_int_generation_get(&dev_ctx, &int_pin_state);

    printf("5 - Device’s Interrupt Pin State After Enabling: %d\r\n", int_pin_state);

    lis3mdl_int_generation_set(&dev_ctx, PROPERTY_DISABLE);

    lis3mdl_int_generation_get(&dev_ctx, &int_pin_state);

    printf("6 - Device’s Interrupt Pin State After Disabling: %d\r\n", int_pin_state);

    lis3mdl_read_reg(&dev_ctx, LIS3MDL_OUT_X_L, (uint8_t *) data_raw_magnetic, 2);

    printf("7 - X-Axis Raw Data: %d\r\n", data_raw_magnetic);

    lis3mdl_read_reg(&dev_ctx, LIS3MDL_OUT_Y_L, (uint8_t *) data_raw_magnetic, 2);

    printf("8 - Y-Axis Raw Data: %d\r\n", data_raw_magnetic);

    lis3mdl_read_reg(&dev_ctx, LIS3MDL_OUT_Z_L, (uint8_t *) data_raw_magnetic, 2);

    printf("9 - Z-Axis Raw Data: %d\r\n", data_raw_magnetic);

    return;
}
/******************************************************************
*********                       EOF                       *********
*******************************************************************
********* Dev. by Sanchitha Dias (sanchithadias@gmail.com)*********
******************************************************************/