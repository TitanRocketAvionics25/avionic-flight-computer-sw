#ifndef __IMU_SPI_H__
#define __IMU_SPI_H__

#include <stdint.h>

void IMUSpi_Config();

void IMUSpi_Read( uint8_t* dataOut, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );

void IMUSpi_Write( uint8_t* dataOut, uint16_t dataSize );

#endif
