#include "I2Cconf.h"

#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

static I2C_HandleTypeDef i2ch = { 0 };

void I2Cconf_Config()
{
    i2ch.Instance             = I2C1;
    i2ch.Init.ClockSpeed      = 10240;
    i2ch.Init.DutyCycle       = I2C_DUTYCYCLE_2;
    i2ch.Init.OwnAddress1     = 0;
    i2ch.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    i2ch.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    i2ch.Init.OwnAddress2     = 0;
    i2ch.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    i2ch.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

    HAL_I2C_Init( &i2ch );
}

void I2Cconf_Read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize )
{
    HAL_I2C_Mem_Read( &i2ch, dataOut[ dataSize - 2], dataOut[ dataSize - 1 ], 
                      I2C_MEMADD_SIZE_8BIT, rxBuff, rxSize, HAL_MAX_DELAY );
}

void I2Cconf_Write( uint8_t* dataOut, uint16_t dataSize )
{
    HAL_I2C_Master_Transmit( &i2ch, dataOut[ 0 ], dataOut + 1, dataSize - 1, HAL_MAX_DELAY );
}
