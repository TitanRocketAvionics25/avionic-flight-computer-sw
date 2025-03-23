#include "sx127x.h"
#include "sx127x_defs.h"


#define RW_MASK 0x80
#define WRITE_BUFF_SIZE 2
#define ADDR 0
#define DATA 1


void sx127x_read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, sx127x_t* sx )
{
    uint8_t dataBuff = startAddr & ~RW_MASK;
    sx->spi_read( &dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}


uint8_t sx127x_read_byte( uint8_t addr, sx127x_t* sx )
{
    uint8_t received = 0;
    sx127x_read( addr, &received, sizeof( received ), sx );
    return received;
}


void sx127x_write( uint8_t startAddr, uint8_t* data, uint16_t dataSize, sx127x_t* sx )
{
    uint8_t dataBuff[ WRITE_BUFF_SIZE ] = { 0 };
    dataBuff[ ADDR ] = startAddr | RW_MASK;
    dataBuff[ DATA ] = data[ 0 ];
    sx->spi_write( dataBuff, sizeof( dataBuff ) );

    if ( dataSize > 1 )
    {
        sx->spi_write( &data[ 1 ], dataSize - 1 );
    }
}


void sx127x_write_byte( uint8_t addr, uint8_t data, sx127x_t* sx )
{
    sx127x_write( addr, &data, sizeof( data ), sx );
}
