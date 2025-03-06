#include "BMP581.h"
#include "BMP581_defs.h"

#include <stddef.h>


void BMP581_Read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, BMP581_t* bmp )
{
    uint8_t dataBuff[ 2 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = startAddr;

    bmp->i2cRead( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}

void BMP581_Write( uint8_t devAddr, uint8_t addr, uint8_t data, BMP581_t* bmp )
{
    uint8_t dataBuff[ 3 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = addr;
    dataBuff[ 2 ] = data;

    bmp->i2cWrite( dataBuff, sizeof( dataBuff ) );
}

