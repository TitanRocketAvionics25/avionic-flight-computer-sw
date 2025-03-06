#ifndef __BMP581_H__
#define __BMP581_H__


#include <stdint.h>


typedef enum
{
    BMP581_SUCCESS,
    BMP581_FAIL
} bmp581_status_t;


// Defines i2c interaction callbacks
//
// i2c_write : write bytes over i2c
//      data : data buffer to write
//      size : size of total data in bytes
// 
// i2c_read  : write then read bytes over i2c
//      data     : data buffer to write
//      dataSize : size of total data to write
//      rxBuff   : buffer to received data
//      rxSize   : size of expected bytes back
typedef struct
{
    void ( *i2c_write )( uint8_t* data, uint16_t size );
    void ( *i2c_read  )( uint8_t* data, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );
} bmp581_t;


// Read registers starting from an address
//
// NOTE: the bmp581 auto increments the address so that multiple sequential registers can be read
//       in one transaction
//
// startAddr : register address to begin read from
//
// rxBuff    : buffer to hold read back bytes
//
// rxSize    : total bytes to read
//
// bmp       : bmp581 instance
void bmp581_read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmp581_t* bmp );


// Write to a single register
//
// addr    : register address to write to
//
// data    : data to write into register
//
// bmp     : bmp581 instance
void bmp581_write( uint8_t addr, uint8_t data, bmp581_t* bmp );


#endif
