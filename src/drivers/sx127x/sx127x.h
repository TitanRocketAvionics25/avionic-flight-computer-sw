#ifndef __SX127X_H__
#define __SX127X_H__

#include <stdint.h>

typedef struct 
{
    void ( *spi_write  )( uint8_t* data, uint16_t size );
    void ( *spi_read   )( uint8_t* data, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );
    void ( *spi_cs_set )( uint8_t state );
} sx127x_t;


void sx127x_read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, sx127x_t* sx );

//void sx127x_read_byte( uint8_t addr, sx127x_t* sx );

void sx127x_write( uint8_t addr, uint8_t data, sx127x_t* sx );

#endif
