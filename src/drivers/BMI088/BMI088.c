#include "BMI088.h"
#include "BMI088_defs.h"

#include <stddef.h>

void BMI088_Read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, BMI088_t* bmi )
{
    uint8_t dataBuff[ 2 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = startAddr;

    bmi->i2cRead( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}

void BMI088_Write( uint8_t devAddr, uint8_t addr, uint8_t data, BMI088_t* bmi )
{
    uint8_t dataBuff[ 3 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = addr;
    dataBuff[ 2 ] = data;

    bmi->i2cWrite( dataBuff, sizeof( dataBuff ) );
}
