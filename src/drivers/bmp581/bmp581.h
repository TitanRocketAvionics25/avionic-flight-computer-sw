#ifndef __BMP581_H__
#define __BMP581_H__

#include <stdint.h>

typedef enum
{
    BMP581_SUCCESS,
    BMP581_FAIL
} bmp581_status_t;

typedef struct
{
    void ( *i2c_write )( uint8_t* data, uint16_t size );
    void ( *i2c_read  )( uint8_t* data, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );
} bmp581_t;

void bmp581_read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmp581_t* bmp );

void bmp581_write( uint8_t devAddr, uint8_t addr, uint8_t data, bmp581_t* bmp );

#endif
