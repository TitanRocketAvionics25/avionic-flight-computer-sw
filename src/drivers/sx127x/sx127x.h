#ifndef __SX127X_H__
#define __SX127X_H__

#include <stdint.h>


// Define SPI transaction callbacks.
//
// spi_write : transmit data over bus
//      data : data to transmit
//      size : size of data
//
// spi_read : transmit command then receive data over bus
//      data     : command to send onto bus before read
//      dataSize : size of command
//      rxBuff   : buffer to hold received data
//      rxSize   : size of receiveing buffer
//
// spi_cs_set : set state of chip select pin
//      state : chip select state (0 = low, 1 = high)
//
// rst_pin_set : set state of reset pin
//      state : reset pin state (0 = low, 1 = high)
// NOTE: should be left high during operation, a switch of low to high
// can be used to perform reset of device
typedef struct 
{
    void ( *spi_write   )( uint8_t* data, uint16_t size );
    void ( *spi_read    )( uint8_t* data, uint8_t* rxBuff, uint16_t size );
    void ( *spi_cs_set  )( uint8_t state );
    void ( *rst_pin_set )( uint8_t state );
} sx127x_t;


// Functions with the parameter 'sx127x_t* sx' refer to the sx127x instance to operate on.


// Read out multiple bytes from registers from a starting point.
// NOTE: The sx127x auto increments the received register address after the first full frame.
//
// startAddr : register address to begin read from
//
// rxBuff    : array buffer to write received data into
//
// rxSize    : size of receiving buffer
void sx127x_read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, sx127x_t* sx );


// Read a single byte from a register address. Acts as a wrapper for the above function.
//
// addr   : register address to read
//
// return : register address data
uint8_t sx127x_read_byte( uint8_t addr, sx127x_t* sx );


// Write multiple bytes to sequential register addresses from a starting point. 
// NOTE: The sx127x auto increments the received register address after the first full frame.
//
// startAddr : register address to begin write from
//
// data      : data buffer to write into register addresses
//
// dataSize  : size in bytes of data buffer to be written 
void sx127x_write( uint8_t startAddr, uint8_t* data, uint16_t dataSize, sx127x_t* sx );


// Write a single byte into a register address. Acts as a wrapper for the above function.
//
// addr : register address to write to
//
// data : data to write into register address
void sx127x_write_byte( uint8_t addr, uint8_t data, sx127x_t* sx );


#endif
