#ifndef __BMI088_H__
#define __BMI088_H__

#include <stdint.h>

typedef enum
{
    BMI088_SUCCESS,
    BMI088_FAIL
} bmi088_status_t;

typedef struct
{
    void ( *i2c_write )( uint8_t* data, uint16_t size );
    void ( *i2c_read  )( uint8_t* data, uint16_t dataSize, uint8_t* rxBuff, uint16_t rxSize );
} bmi088_t;

void bmi088_read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmi088_t* bmi );

void bmi088_write( uint8_t devAddr, uint8_t addr, uint8_t data, bmi088_t* bmi );

#endif
