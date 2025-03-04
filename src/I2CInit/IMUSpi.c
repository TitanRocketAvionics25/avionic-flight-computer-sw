#include "IMUSpi.h"

#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

static I2C_HandleTypeDef IMUhspi = { 0 };

void IMUSpi_Config()
{
    IMUhspi.Instance             = I2C1;
    IMUhspi.Init.ClockSpeed      = 10240;
    IMUhspi.Init.DutyCycle       = I2C_DUTYCYCLE_2;
    IMUhspi.Init.OwnAddress1     = 0;
    IMUhspi.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    IMUhspi.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    IMUhspi.Init.OwnAddress2     = 0;
    IMUhspi.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    IMUhspi.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

    HAL_I2C_Init( &IMUhspi );
}

void IMUSpi_Read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize )
{
    HAL_I2C_Mem_Read( &IMUhspi, dataOut[ dataSize - 2], dataOut[ dataSize - 1 ], 
                      I2C_MEMADD_SIZE_8BIT, rxBuff, rxSize, HAL_MAX_DELAY );
}

void IMUSpi_Write( uint8_t* dataOut, uint16_t dataSize )
{
    HAL_I2C_Master_Transmit( &IMUhspi, dataOut[ 0 ], dataOut + 1, dataSize - 1, HAL_MAX_DELAY );
}
