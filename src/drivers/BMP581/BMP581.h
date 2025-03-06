#ifndef __BMP581_H__
#define __BMP581_H__


#include <stdint.h>

typedef enum
{
    BMP581_SUCCESS,
    BMP581_FAIL
} BMP581Status;

typedef struct
{
    void ( *i2cWrite )( uint8_t* data, uint16_t size );
    void ( *i2cRead  )( uint8_t* data, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );
} BMP581_t;

void BMP581_Read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, BMP581_t* bmp );

void BMP581_Write( uint8_t devAddr, uint8_t addr, uint8_t data, BMP581_t* bmp );

#endif
