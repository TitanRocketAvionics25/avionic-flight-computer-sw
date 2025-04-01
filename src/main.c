#include <stdio.h>
#include <stdint.h>

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "sysclk.h"
#include "i2cconf.h"
#include "spiconf.h"

#include "bmi088.h"
#include "bmi088_defs.h"

#include "bmp581.h"
#include "bmp581_defs.h"

#include "sx127x.h"
#include "sx127x_defs.h"

#include "stm32f4xx_hal_gpio.h"

#define APB1_HZ 32E6

#define PORT        GPIOA

#define MARGIN      500.f

#define YELLOW_IO   GPIO_PIN_5
#define GREEN_IO    GPIO_PIN_6
#define BLUE_IO     GPIO_PIN_7
#define RED_IO      GPIO_PIN_8

#define YELLOW_T    100700.f
#define GREEN_T     99608.f
#define BLUE_T      96244.f
#define RED_T       71201.f


void gpio_config()
{
    GPIO_InitTypeDef leds =
    {
        .Pin = YELLOW_IO | GREEN_IO | BLUE_IO | RED_IO,
        .Mode = GPIO_MODE_OUTPUT_PP
    };
    HAL_GPIO_Init( PORT, &leds );
    HAL_GPIO_WritePin( PORT, YELLOW_IO, GPIO_PIN_RESET );
    HAL_GPIO_WritePin( PORT, GREEN_IO, GPIO_PIN_RESET );
    HAL_GPIO_WritePin( PORT, BLUE_IO, GPIO_PIN_RESET );
    HAL_GPIO_WritePin( PORT, RED_IO, GPIO_PIN_RESET );
}

float c_to_f( float c )
{
    return ( c * ( float )( 9.f/5.f ) ) + 32.f;
}

float pa_to_inhg( float pa )
{
    return ( float )( pa / 3386.f );
}

float pa_to_psi( float pa )
{
    return pa / 6895.f;
}

void determinte_led_state( float press, float goal, float margin, uint16_t led )
{
    if ( ( ( goal + margin ) > press ) && ( press > ( goal - margin ) ) )
        HAL_GPIO_WritePin( PORT, led, GPIO_PIN_SET );
    else 
        HAL_GPIO_WritePin( PORT, led, GPIO_PIN_RESET );
}

int main()
{
    HAL_Init();

    sysclk_config();

    UsartPrint_Init( APB1_HZ );

    // Application code ...
    //gpio_config();
    //i2cconf_config();
    //bmp581_t bmp =
    //{
    //    .i2c_write = i2cconf_write,
    //    .i2c_read  = i2cconf_read
    //};

    //bmp581_non_stop_mode( &bmp );
    //bmp581_enable_press( &bmp );

    //// Super loop
    //while (1)
    //{
    //    float press = bmp581_get_press( &bmp );
    //    determinte_led_state( press, YELLOW_T, MARGIN, YELLOW_IO );
    //    determinte_led_state( press, GREEN_T , MARGIN, GREEN_IO  );
    //    determinte_led_state( press, BLUE_T  , MARGIN, BLUE_IO   );
    //    determinte_led_state( press, RED_T   , MARGIN, RED_IO    );
    //    printf("press_psi: %f\n", press);
    //}
   


    i2cconf_config();
    bmi088_t bmi = 
    {
        .i2c_write = i2cconf_write,
        .i2c_read  = i2cconf_read
    };

    bmi088_acc_enable( &bmi );
    bmi088_acc_active_mode( &bmi );

    bmi088_acc_t acc = { 0 };
    while (1)
    {
        bmi088_get_acc( &acc, BMI088_ACC_RANGE_6G, &bmi );

        printf( "x: %f\n", acc.x );
        printf( "y: %f\n", acc.y );
        printf( "z: %f\n", acc.z );
        printf("\n");
        HAL_Delay( 500 );
    }



    //spiconf_config();
    //sx127x_t sx =
    //{
    //    .spi_write   = spiconf_write,
    //    .spi_read    = spiconf_read,
    //    .spi_cs_set  = spiconf_set_cs,
    //    .rst_pin_set = spiconf_set_rst
    //};

    //sx127x_lora_mode( &sx );
    //sx127x_pa_boost( &sx );
    //sx127x_set_coding_rate( SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr5, &sx );
    //sx127x_set_freq( 915E6, &sx );
    //sx127x_set_bandwidth( SX127X_LORA_REG_MODEM_CONFIG1_BW_125_KHZ, &sx );
    //sx127x_set_spreading_factor( SX127X_LORA_REG_MODEM_CONFIG2_SF_128_CPS, &sx );
    //sx127x_set_explicit_header_mode( &sx );
    //sx127x_crc_enable( &sx );
    //sx127x_max_fifo( &sx );
    //uint8_t packet[50] = { 0 };

    //sx127x_rxcontinuous_mode( &sx );
    //while ( 1 )
    //{
    //    uint8_t size = sx127x_receive_packet( packet, sizeof( packet ), &sx );
    //    printf( "packet: " );
    //    for ( uint8_t i = 0; i < size; i++ )
    //    {
    //        printf( "%X,", packet[ i ] );
    //    }
    //    printf("\n");
    //}

    //uint8_t count = 0;
    //while ( 1 )
    //{
    //    sx127x_transmit_packet( packet, 30, &sx );
    //    printf( "Sent packet: " );
    //    for ( uint8_t i = 0; i < 30; i++ )
    //    {
    //        printf( "%X,", packet[ i ] );
    //        packet[ i ] = count;
    //    }
    //    printf("\n");
    //    count++;
    //}

    return 0;
}


