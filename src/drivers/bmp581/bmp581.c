#include "bmp581.h"
#include "bmp581_defs.h"

#include <stddef.h>


void bmp581_read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmp581_t* bmp )
{
    uint8_t dataBuff[ 2 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = startAddr;

    bmp->i2c_read( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}

void bmp581_write( uint8_t devAddr, uint8_t addr, uint8_t data, bmp581_t* bmp )
{
    uint8_t dataBuff[ 3 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = addr;
    dataBuff[ 2 ] = data;

    bmp->i2c_write( dataBuff, sizeof( dataBuff ) );
}

