#include <stdio.h>

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "i2cconf.h"
#include "spiconf.h"

#include "sysclk.h"
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
    
    spiconf_config();
    sx127x_t sx =
    {
        .spi_write   = spiconf_write,
        .spi_read    = spiconf_read,
        .spi_cs_set  = spiconf_set_cs,
        .rst_pin_set = spiconf_set_rst
    };

    sx127x_write_byte( SX127X_REG_OP_MODE, 0x05, &sx );
    sx127x_write_byte( SX127X_REG_OP_MODE, 0x05, &sx );
    while ( 1 )
    {
        printf("%02X\n", sx127x_read_byte( SX127X_REG_OP_MODE, &sx ));
        HAL_Delay(500);
    }

    return 0;
}


