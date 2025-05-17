#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "sysclk.h"
#include "i2cconf.h"
#include "spiconf.h"
#include "uartconf.h"

#include "bmi088.h"
#include "bmi088_defs.h"

#include "bmp581.h"
#include "bmp581_defs.h"

#include "sx127x.h"
#include "sx127x_defs.h"

#define APB1_HZ 32000000U

#define TEST_CODE
#include "stm32f4xx_hal_uart.h"

uint8_t c = 0;
int main()
{
    HAL_Init();

    sysclk_config();

    UsartPrint_Init( APB1_HZ );

#ifdef TEST_CODE

    GPIO_InitTypeDef led = { 0 };
    led.Pin = GPIO_PIN_5;
    led.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init( GPIOA, &led );
    HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_SET );

    uartconf_config();   
    HAL_UART_Receive_IT( getUARTHandle(), &c, 1 );
    while(1);

#endif

#ifdef APPLICATION_CODE

    // Application code ...

    // I2C bus for bmp581 and bmi088 setup.
    i2cconf_config();

    // Pressure sensor setup.
    bmp581_t bmp =
    {
        .i2c_write = i2cconf_write,
        .i2c_read  = i2cconf_read
    };
    bmp581_non_stop_mode( &bmp );
    bmp581_enable_press( &bmp );

    // Inertial measurement unit setup.
    bmi088_t bmi = 
    {
        .i2c_write = i2cconf_write,
        .i2c_read  = i2cconf_read
    };
    bmi088_acc_enable( &bmi );
    bmi088_acc_active_mode( &bmi );

    // SPI bus setup for sx127x.
    spiconf_config();

    // Radio tranceiver setup.
    sx127x_t sx =
    {
        .spi_write   = spiconf_write,
        .spi_read    = spiconf_read,
        .spi_cs_set  = spiconf_set_cs,
        .rst_pin_set = spiconf_set_rst
    };
    sx127x_lora_mode( &sx );
    sx127x_pa_boost( &sx );
    sx127x_set_coding_rate( SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr5, &sx );
    sx127x_set_freq( 915E6, &sx );
    sx127x_set_bandwidth( SX127X_LORA_REG_MODEM_CONFIG1_BW_125_KHZ, &sx );
    sx127x_set_spreading_factor( SX127X_LORA_REG_MODEM_CONFIG2_SF_128_CPS, &sx );
    sx127x_set_explicit_header_mode( &sx );
    sx127x_crc_enable( &sx );
    sx127x_max_fifo( &sx );

    // Radio transmission packet.
    uint8_t packet[29] = { 0 };

    // Sensor data.
    float press = 0.0f;
    bmi088_acc_t acc = { 0 };
    bmi088_gyro_t gyro = { 0 };

    // Main loop.
    while (1)
    {
        // Get sensor data.
        bmi088_get_acc( &acc, BMI088_ACC_RANGE_6G, &bmi );
        bmi088_get_gyro( &gyro, BMI088_GYRO_RANGE_2000_DEG_S, &bmi );
        press = bmp581_get_press( &bmp );


        // Assemble packet for transmission.
        uint8_t* i = packet;

        memcpy( i, &press, sizeof( press ) );
        i += sizeof( press );

        memcpy( i, &acc.x, sizeof( acc.x ) );
        i += sizeof( acc.x );

        memcpy( i, &acc.y, sizeof( acc.y ) );
        i += sizeof( acc.y );

        memcpy( i, &acc.z, sizeof( acc.z ) );
        i += sizeof( acc.z );

        memcpy( i, &gyro.x, sizeof( gyro.x ) );
        i += sizeof( gyro.x );

        memcpy( i, &gyro.y, sizeof( gyro.y ) );
        i += sizeof( gyro.y );

        memcpy( i, &gyro.z, sizeof( gyro.z ) );
        i += sizeof( gyro.z );


        // Transmit packet.
        sx127x_transmit_packet( packet, sizeof( packet ), &sx );
        printf( "Sent packet: " );
        for ( uint8_t i = 0; i < sizeof( packet ); i++ )
        {
            printf( "%X,", packet[ i ] );
        }
        printf("\n");



        printf( "%f,%f,%f,%f,%f,%f,%f\n", press, acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z );
        HAL_Delay( 10 );
    }

#endif

    return 0;
}

