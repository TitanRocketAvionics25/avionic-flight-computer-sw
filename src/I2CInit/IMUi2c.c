#include "IMUi2c.h"

#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

static I2C_HandleTypeDef IMUhi2c = { 0 };

void IMUi2c_Config()
{
    IMUhi2c.Instance             = I2C1;
    IMUhi2c.Init.ClockSpeed      = 10240;
    IMUhi2c.Init.DutyCycle       = I2C_DUTYCYCLE_2;
    IMUhi2c.Init.OwnAddress1     = 0;
    IMUhi2c.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    IMUhi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    IMUhi2c.Init.OwnAddress2     = 0;
    IMUhi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    IMUhi2c.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

    HAL_I2C_Init( &IMUhi2c );
}

void IMUi2c_Read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize )
{
    HAL_I2C_Mem_Read( &IMUhi2c, dataOut[ dataSize - 2], dataOut[ dataSize - 1 ], 
                      I2C_MEMADD_SIZE_8BIT, rxBuff, rxSize, HAL_MAX_DELAY );
}

void IMUi2c_Write( uint8_t* dataOut, uint16_t dataSize )
{
    HAL_I2C_Master_Transmit( &IMUhi2c, dataOut[ 0 ], dataOut + 1, dataSize - 1, HAL_MAX_DELAY );
}
