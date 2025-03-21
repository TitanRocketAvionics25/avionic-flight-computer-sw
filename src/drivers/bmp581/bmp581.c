#include "bmp581.h"
#include "bmp581_defs.h"

#include <stddef.h>

// Buffer sizes
#define READ_BUFF_SIZE  2
#define WRITE_BUFF_SIZE 3
#define TEMP_BUFF_SIZE  3
#define PRESS_BUFF_SIZE 3

// Indexes for I2C transmission buffers
#define SLAVE_ADDR      0
#define REG_ADDR        1
#define DATA            2

// Indexes for temperature and pressure data
#define XLSB            0
#define LSB             1
#define MSB             2

// TTP stand for "to the power"
#define TWO_TTP_16      65536.f
#define TWO_TTP_6       64.f


void bmp581_read(  uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, bmp581_t* bmp )
{
    uint8_t dataBuff[ READ_BUFF_SIZE ] = { 0 };

    dataBuff[ SLAVE_ADDR ] = BMP581_SLAVE_ADDRESS << 1;
    dataBuff[ REG_ADDR   ] = startAddr;

    bmp->i2c_read( dataBuff, sizeof( dataBuff ), rxBuff, rxSize );
}


uint8_t bmp581_read_byte( uint8_t addr, bmp581_t* bmp )
{
    uint8_t reading;
    bmp581_read( addr, &reading, sizeof( reading ), bmp );
    return reading;
}


void bmp581_write( uint8_t addr, uint8_t data, bmp581_t* bmp )
{
    uint8_t dataBuff[ WRITE_BUFF_SIZE ] = { 0 };

    dataBuff[ SLAVE_ADDR ] = BMP581_SLAVE_ADDRESS << 1;
    dataBuff[ REG_ADDR   ] = addr;
    dataBuff[ DATA       ] = data;

    bmp->i2c_write( dataBuff, sizeof( dataBuff ) );
}


void bmp581_disable_deep_standby( bmp581_t* bmp )
{
    uint8_t cmd = bmp581_read_byte( BMP581_ODR_CONFIG, bmp ) | 
                                  ( 1 << BMP581_ODR_CONFIG_DEEP_DIS_Pos );
    bmp581_write( BMP581_ODR_CONFIG, cmd, bmp );
}


void bmp581_standby_mode( bmp581_t* bmp )
{
    uint8_t cmd = bmp581_read_byte( BMP581_ODR_CONFIG, bmp ) & 
                                 ~( BMP581_ODR_CONFIG_PWR_MODE_Msk );
    cmd |= ( BMP581_ODR_CONFIG_PWR_MODE_STNBY << BMP581_ODR_CONFIG_PWR_MODE_Pos );

    bmp581_write( BMP581_ODR_CONFIG, cmd, bmp );
}


void bmp581_normal_mode( bmp581_t* bmp )
{
    bmp581_standby_mode( bmp );
    // After the above the power mode bits are zero'ed so no need to rezero them
    uint8_t cmd = bmp581_read_byte( BMP581_ODR_CONFIG, bmp ) | 
                                  ( BMP581_ODR_CONFIG_PWR_MODE_NORM << 
                                    BMP581_ODR_CONFIG_PWR_MODE_Pos );

    bmp581_write( BMP581_ODR_CONFIG, cmd, bmp );
}


void bmp581_non_stop_mode( bmp581_t* bmp )
{
    bmp581_standby_mode( bmp );
    // After the above the power mode bits are zero'ed so no need to rezero them
    uint8_t cmd = bmp581_read_byte( BMP581_ODR_CONFIG, bmp ) | 
                                  ( BMP581_ODR_CONFIG_PWR_MODE_NON_STOP << 
                                    BMP581_ODR_CONFIG_PWR_MODE_Pos );

    bmp581_write( BMP581_ODR_CONFIG, cmd, bmp );
}


void bmp581_enable_press( bmp581_t* bmp )
{
    uint8_t cmd = bmp581_read_byte( BMP581_OSR_CONFIG, bmp ) | 
                                  ( 1 << BMP581_OSR_CONFIG_PRESS_EN_Pos );

    bmp581_write( BMP581_OSR_CONFIG, cmd, bmp );
}


int32_t bmp581_get_raw_temp( bmp581_t* bmp )
{
    uint8_t rx[ TEMP_BUFF_SIZE ] = { 0 };
    bmp581_read( BMP581_TEMP_DATA_XLSB, rx, sizeof( rx ), bmp );
    return ( int32_t )( ( rx[ MSB ] << 16 ) | ( rx[ LSB ] << 8 ) | rx[ XLSB ] );
}


uint32_t bmp581_get_raw_press( bmp581_t* bmp )
{
    uint8_t rx[ PRESS_BUFF_SIZE ] = { 0 };
    bmp581_read( BMP581_PRESS_DATA_XLSB, rx, sizeof( rx ), bmp );
    return ( uint32_t )( ( rx[ MSB ] << 16 ) | ( rx[ LSB ] << 8 ) | rx[ XLSB ] );
}


float bmp581_get_temp( bmp581_t* bmp )
{
    return bmp581_get_raw_temp( bmp ) / TWO_TTP_16;
}


float bmp581_get_press( bmp581_t* bmp )
{
    return bmp581_get_raw_press( bmp ) / TWO_TTP_6;
}
