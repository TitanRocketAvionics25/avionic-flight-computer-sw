#include "bmi088.h"
#include "bmi088_defs.h"

#include <stddef.h>

void bmi088_read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmi088_t* bmi )
{
    uint8_t dataBuff[ 2 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = startAddr;

    bmi->i2c_read( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}

void bmi088_write( uint8_t devAddr, uint8_t addr, uint8_t data, bmi088_t* bmi )
{
    uint8_t dataBuff[ 3 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = addr;
    dataBuff[ 2 ] = data;

    bmi->i2c_write( dataBuff, sizeof( dataBuff ) );
}
