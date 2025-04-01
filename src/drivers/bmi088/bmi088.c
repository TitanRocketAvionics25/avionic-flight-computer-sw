#include "bmi088.h"
#include "bmi088_defs.h"

#include <stddef.h>


// Buffer sizes.
#define READ_BUFF_SIZE  2
#define WRITE_BUFF_SIZE 3
#define ACC_BUFF_SIZE   6
#define GYRO_BUFF_SIZE  6

// Indexes for I2C transmission buffers.
#define SLAVE_ADDR      0
#define REG_ADDR        1
#define DATA            2

// Indexes for accelerometer and gyroscope data.
#define X_LSB           0
#define X_MSB           1
#define Y_LSB           2
#define Y_MSB           3
#define Z_LSB           4
#define Z_MSB           5


void bmi088_read( uint8_t devAddr, uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmi088_t* bmi )
{
    uint8_t dataBuff[ READ_BUFF_SIZE ] = { 0 };

    dataBuff[ SLAVE_ADDR ] = devAddr << 1;
    dataBuff[ REG_ADDR   ] = startAddr;

    bmi->i2c_read( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}


uint8_t bmi088_read_byte( uint8_t devAddr, uint8_t addr, bmi088_t* bmi )
{
    uint8_t reading = 0;
    bmi088_read( devAddr, addr, &reading, sizeof( reading ), bmi );
    return reading;
}


void bmi088_write( uint8_t devAddr, uint8_t addr, uint8_t data, bmi088_t* bmi )
{
    uint8_t dataBuff[ WRITE_BUFF_SIZE ] = { 0 };

    dataBuff[ SLAVE_ADDR ] = devAddr << 1;
    dataBuff[ REG_ADDR   ] = addr;
    dataBuff[ DATA       ] = data;

    bmi->i2c_write( dataBuff, sizeof( dataBuff ) );
}


void bmi088_acc_enable( bmi088_t* bmi )
{
    bmi088_write( BMI088_ACC_SLAVE_ADDRESS, BMI088_ACC_PWR_CTRL, 
                  BMI088_ACC_PWR_CTRL_ENABLE_ON, bmi );
}


void bmi088_acc_range( uint8_t range, bmi088_t* bmi )
{
    if ( range <= BMI088_ACC_RANGE_24G )
    {
        bmi088_write( BMI088_ACC_SLAVE_ADDRESS, BMI088_ACC_RANGE, 
                      range, bmi );
    }
}


void bmi088_acc_active_mode( bmi088_t* bmi )
{
    bmi088_write( BMI088_ACC_SLAVE_ADDRESS, BMI088_ACC_PWR_CONF, 
                  BMI088_ACC_PWR_CONF_ACTIVE_MODE, bmi );
}


void bmi088_get_raw_acc( bmi088_acc_raw_t* accRaw, bmi088_t* bmi )
{
    uint8_t acc[ ACC_BUFF_SIZE ] = { 0 };
    bmi088_read( BMI088_ACC_SLAVE_ADDRESS, BMI088_ACC_X_LSB, acc, sizeof( acc ), bmi );

    accRaw->x = ( int16_t )( ( acc[ X_MSB ] << 8 ) | acc[ X_LSB ] );
    accRaw->y = ( int16_t )( ( acc[ Y_MSB ] << 8 ) | acc[ Y_LSB ] );
    accRaw->z = ( int16_t )( ( acc[ Z_MSB ] << 8 ) | acc[ Z_LSB ] );
}


void bmi088_get_acc( bmi088_acc_t* acc, uint8_t accRange, bmi088_t* bmi )
{
    bmi088_acc_raw_t accRaw = { 0 };
    bmi088_get_raw_acc( &accRaw, bmi );

    // Two to the power of the content in acc_range register + 1.
    float twoPwr = 2;
    for ( uint8_t i = 0; i < accRange; i++ )
        twoPwr *= 2;

    // Calculation found in section 5.3.4 of datasheet.
    acc->x = ( float )( accRaw.x / 32768.f * 1000.f * twoPwr * 1.5f );
    acc->y = ( float )( accRaw.y / 32768.f * 1000.f * twoPwr * 1.5f );
    acc->z = ( float )( accRaw.z / 32768.f * 1000.f * twoPwr * 1.5f );
}


void bmi088_get_raw_gyro( bmi088_gyro_raw_t* gyroRaw, bmi088_t* bmi )
{
    uint8_t gyro[ GYRO_BUFF_SIZE ] = { 0 }; 
    bmi088_read( BMI088_GYRO_SLAVE_ADDRESS, BMI088_RATE_X_LSB, gyro, sizeof( gyro ), bmi );

    gyroRaw->x = ( int16_t )( ( gyro[ X_MSB ] << 8 ) | gyro[ X_LSB ] );
    gyroRaw->y = ( int16_t )( ( gyro[ Y_MSB ] << 8 ) | gyro[ Y_LSB ] );
    gyroRaw->z = ( int16_t )( ( gyro[ Z_MSB ] << 8 ) | gyro[ Z_LSB ] );
}


void bmi088_get_gyro( bmi088_gyro_t* gyro, uint8_t gyroRange, bmi088_t* bmi )
{
    bmi088_gyro_raw_t gyroRaw = { 0 };
    bmi088_get_raw_gyro( &gyroRaw, bmi );

    // Default value so step will become 1 if gyroRange is not an acceptable value.
    float fullScaleRange = 32767.f;
    switch ( gyroRange )
    {
        case BMI088_GYRO_RANGE_2000_DEG_S:
            fullScaleRange = 2000.f;
            break;
        case BMI088_GYRO_RANGE_1000_DEG_S:
            fullScaleRange = 1000.f;
            break;
        case BMI088_GYRO_RANGE_500_DEG_S:
            fullScaleRange = 500.f;
            break;
        case BMI088_GYRO_RANGE_250_DEG_S:
            fullScaleRange = 250.f;
            break;
        case BMI088_GYRO_RANGE_125_DEG_S:
            fullScaleRange = 125.f;
            break;
    }

    float step = fullScaleRange / 32767.f;

    // Calculation found in section 5.5.2 of datasheet.
    gyro->x = gyroRaw.x * step;
    gyro->y = gyroRaw.y * step;
    gyro->z = gyroRaw.z * step;
}

