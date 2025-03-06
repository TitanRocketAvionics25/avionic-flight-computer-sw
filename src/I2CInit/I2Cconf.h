#ifndef __I2C_CONF_H__
#define __I2C_CONF_H__

#include <stdint.h>

void I2Cconf_Config();

void I2Cconf_Read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );

void I2Cconf_Write( uint8_t* dataOut, uint16_t dataSize );

#endif
