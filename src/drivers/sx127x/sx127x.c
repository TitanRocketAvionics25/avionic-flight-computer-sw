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


void sx127x_write( uint8_t addr, uint8_t data, sx127x_t* sx )
{
    uint8_t dataBuff[ WRITE_BUFF_SIZE ] = { 0 };
    dataBuff[ ADDR ] = addr | RW_MASK;
    dataBuff[ DATA ] = data;
    sx->spi_write( dataBuff, sizeof( dataBuff ) );
}
