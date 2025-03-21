#ifndef __BMP581_H__
#define __BMP581_H__


#include <stdint.h>


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


// Functions with the parameter bmp581_t* bmp refer to the bmp581 instance to use


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
void bmp581_read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmp581_t* bmp );


// Read single byte within register address
//
// addr   : register address to read
//
// return : register data
uint8_t bmp581_read_byte( uint8_t addr, bmp581_t* bmp );


// Write to a single register
//
// addr    : register address to write to
//
// data    : data to write into register
void bmp581_write( uint8_t addr, uint8_t data, bmp581_t* bmp );


// Disable the deep standby the chip goes into upon startup
void bmp581_disable_deep_standby( bmp581_t* bmp );


// Enter standby mode
void bmp581_standby_mode( bmp581_t* bmp );


// Enter normal mode
void bmp581_normal_mode( bmp581_t* bmp );


// Enter non-stop/continuous mode
void bmp581_non_stop_mode( bmp581_t* bmp );


// Enable pressure measurements (off at startup)
void bmp581_enable_press( bmp581_t* bmp );


// Get raw temperature reading
//
// return : raw temperature
int32_t bmp581_get_raw_temp( bmp581_t* bmp );


// Get raw pressure reading
//
// return : raw pressure
uint32_t bmp581_get_raw_press( bmp581_t* bmp );


// Get converted temperature reading in degrees celsius
//
// return : temperature [deg C]
float bmp581_get_temp( bmp581_t* bmp );


// Get converted pressure reading in pascals
//
// return pressure [Pa]
float bmp581_get_press( bmp581_t* bmp );


#endif
