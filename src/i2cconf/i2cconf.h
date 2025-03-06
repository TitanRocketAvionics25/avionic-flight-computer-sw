#ifndef __I2C_CONF_H__
#define __I2C_CONF_H__

#include <stdint.h>

void i2cconf_config();

void i2cconf_read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );

void i2cconf_write( uint8_t* dataOut, uint16_t dataSize );

#endif
