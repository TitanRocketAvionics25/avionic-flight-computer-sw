#ifndef __BMI088_H__
#define __BMI088_H__


#include <stdint.h>


typedef enum
{
    BMI088_SUCCESS,
    BMI088_FAIL
} bmi088_status_t;


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
} bmi088_t;


// Raw acceleration data in LSB units.
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
} bmi088_acc_raw_t;


// Acceleration data in mg units.
typedef struct
{
    float x;
    float y;
    float z;
} bmi088_acc_t;


// Raw angular velocity data in LSB units.
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
} bmi088_gyro_raw_t;


// Angular velocity data in deg/s units.
typedef struct
{
    float x;
    float y;
    float z;
} bmi088_gyro_t;


// Read registers starting from an address
//
// NOTE: the bmi088 auto increments the address so that multiple sequential registers can be read
//       in one transaction
//
// devAddr   : slave address of device
//
// startAddr : register address to begin read from
//
// rxBuff    : buffer to hold read back bytes
//
// rxSize    : total bytes to read
//
// bmi       : bmi088 instance
void bmi088_read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmi088_t* bmi );


// Read a single byte within register address.
//
// devAddr : slave address of device
//
// addr    : register address to read
//
// return  : data byte within register address
uint8_t bmi088_read_byte( uint8_t devAddr, uint8_t addr, bmi088_t* bmi );


// Write to a single register
//
// devAddr : slave address of device
//
// addr    : register address to write to
//
// data    : data to write into register
//
// bmi     : bmi088 instance
void bmi088_write( uint8_t devAddr, uint8_t addr, uint8_t data, bmi088_t* bmi );


// Enable accelerometer portion of device.
void bmi088_acc_enable( bmi088_t* bmi );


// Place accelerometer into active mode.
void bmi088_acc_active_mode( bmi088_t* bmi );


// Set accelerometer range.
//
// range : desired range macro (see define file)
void bmi088_acc_range( uint8_t range, bmi088_t* bmi );


// Get raw accelerometer data in LSB units.
//
// accRaw : struct to hold raw data
void bmi088_get_raw_acc( bmi088_acc_raw_t* accRaw, bmi088_t* bmi );


// Get accelerometer reading in mg units.
//
// acc : struct to hold reading
void bmi088_get_acc( bmi088_acc_t* acc, uint8_t accRange, bmi088_t* bmi );


// Get raw gyroscope data in LSB units.
//
// gyroRaw : struct to hold raw data
void bmi088_get_raw_gyro( bmi088_gyro_raw_t* gyroRaw, bmi088_t* bmi );


// Get gyroscope reading in deg/s units.
//
// gyro : struct to hold reading
void bmi088_get_gyro( bmi088_gyro_t* gyro, uint8_t gyroRangeFullScale, bmi088_t* bmi );


#endif
