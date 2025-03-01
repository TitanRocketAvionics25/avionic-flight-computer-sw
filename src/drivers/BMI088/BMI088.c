#include "BMI088.h"
#include "BMI088_defs.h"

#include <stddef.h>

BMI088Interface interface = { NULL };

BMI088Status BMI088_SetInterface( BMI088Interface* inter )
{
    if ( inter->i2cWrite && inter->i2cRead )
    {
        interface = *inter;
        return SUCCESS;
    }
    return FAIL;
};

void BMI088_Read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize )
{
    uint8_t dataBuff[ 2 ] = { 0 };

    dataBuff[ 0 ] = SLAVE_ADDRESS << 1;
    dataBuff[ 1 ] = startAddr;

    interface.i2cRead( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}
