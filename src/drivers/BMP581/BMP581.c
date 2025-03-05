#include "BMP581.h"
#include "BMP581_defs.h"

#include <stddef.h>

static BMP581Interface interface = { NULL };

BMP581Status BMP581_SetInterface( BMP581Interface* inter )
{
    if ( inter->i2cWrite && inter->i2cRead )
    {
        interface = *inter;
        return BMP581_SUCCESS;
    }
    return BMP581_FAIL;
};

void BMP581_Read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize )
{
    uint8_t dataBuff[ 2 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = startAddr;

    interface.i2cRead( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}

void BMP581_Write( uint8_t devAddr, uint8_t addr, uint8_t data )
{
    uint8_t dataBuff[ 3 ] = { 0 };

    dataBuff[ 0 ] = devAddr << 1;
    dataBuff[ 1 ] = addr;
    dataBuff[ 2 ] = data;

    interface.i2cWrite( dataBuff, sizeof( dataBuff ) );
}

