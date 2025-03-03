#ifndef __BMI088_H__
#define __BMI088_H__

#include <stdint.h>

typedef enum
{
    BMI088_SUCCESS,
    BMI088_FAIL
} BMI088Status;

typedef struct
{
    void ( *i2cWrite )( uint8_t* data, uint16_t size );
    void ( *i2cRead  )( uint8_t* data, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );
} BMI088Interface;

BMI088Status BMI088_SetInterface( BMI088Interface* inter );

void BMI088_Read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize );

void BMI088_Write( uint8_t devAddr, uint8_t addr, uint8_t data );

#endif
