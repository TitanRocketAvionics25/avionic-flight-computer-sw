#ifndef __IMU_I2C_H__
#define __IMU_I2C_H__

#include <stdint.h>

void IMUi2c_Config();

void IMUi2c_Read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );

void IMUi2c_Write( uint8_t* dataOut, uint16_t dataSize );

#endif
