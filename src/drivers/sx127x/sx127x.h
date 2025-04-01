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


// Hardware reset IC.
void sx127x_reset( sx127x_t* sx );


// Put tranceiver into sleep mode.
//
// NOTE: clears FIFO
void sx127x_sleep_mode( sx127x_t* sx );


// Put tranceiver into standby mode.
void sx127x_standby_mode( sx127x_t* sx );


// Put tranceiver into transmit mode.
void sx127x_tx_mode( sx127x_t* sx );


// Put tranceiver into continuous receive mode.
//
// NOTE: remains in receive mode until explicitly changed
void sx127x_rxcontinuous_mode( sx127x_t* sx );


// Put tranceiver into single receive mode.
//
// NOTE: receives one transmission and returns back to standby.
void sx127x_rxsingle_mode( sx127x_t* sx );


// Put tranceiver into long range (LoRa) mode.
void sx127x_lora_mode( sx127x_t* sx );


// Set radio frequency.
//
// freq: desired frequency in Hz
void sx127x_set_freq( uint64_t freq, sx127x_t* sx );


// Set implicit header mode.
void sx127x_set_implicit_header_mode( sx127x_t* sx );


// Set explicit header mode.
void sx127x_set_explicit_header_mode( sx127x_t* sx );


// Set radio coding rate.
//
// cr: desired coding rate macro (see define file)
void sx127x_set_coding_rate( uint8_t cr, sx127x_t* sx );


// Set radio bandwidth.
//
// bw: desired bandwidth macro (see define file)
void sx127x_set_bandwidth( uint8_t bw, sx127x_t* sx );


// Set radio spreading factor.
//
// sf: desired spreading factor macro (see define file)
void sx127x_set_spreading_factor( uint8_t sf, sx127x_t* sx );


// Enable CRC check.
void sx127x_crc_enable( sx127x_t* sx );


// Disable CRC check
void sx127x_crc_disable( sx127x_t* sx );


// Maximize FIFO space. The TX and RX FIFO pointers
// will both be placed at address 0x00 to obtain full 
// access to the FIFO space.
void sx127x_max_fifo( sx127x_t* sx );


// Select PA boost pin for output.
void sx127x_pa_boost( sx127x_t* sx );


// Transmit data.
//
// data: data to transmit
//
// size: size of transmission in bytes
void sx127x_transmit_packet( uint8_t* data, uint8_t size, sx127x_t* sx );


// Receive data.
//
// buffer: array buffer to place received data
//
// size  : size of buffer in bytes
uint8_t sx127x_receive_packet( uint8_t* buffer, uint8_t size, sx127x_t*sx );


#endif
