#include <stdio.h>

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "i2cconf.h"

#include "sysclk.h"
#include "bmp581.h"
#include "bmp581_defs.h"

#include "stm32f4xx_hal_gpio.h"

#define APB1_HZ 30E6

#define PORT        GPIOA

#define YELLOW_IO   GPIO_PIN_5
#define YELLOW_L    0.f
#define YELLOW_H    60.f

#define GREEN_IO    GPIO_PIN_6
#define GREEN_L     0.f
#define GREEN_H     60.f

#define BLUE_IO     GPIO_PIN_7
#define BLUE_L      0.f
#define BLUE_H      60.f

#define RED_IO      GPIO_PIN_8
#define RED_L       0.f
#define RED_H       60.f


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

void determinte_led_state( float press, float min, float max, uint16_t led )
{
    if ( ( press > min ) && ( press < max ) )
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
    gpio_config();
    i2cconf_config();
    bmp581_t bmp =
    {
        .i2c_write = i2cconf_write,
        .i2c_read  = i2cconf_read
    };

    bmp581_non_stop_mode( &bmp );
    bmp581_enable_press( &bmp );

    // Super loop
    while (1)
    {
        float press_inhg = pa_to_inhg( bmp581_get_press( &bmp ) );
        determinte_led_state( press_inhg, YELLOW_L, YELLOW_H, YELLOW_IO );
        determinte_led_state( press_inhg, GREEN_L , GREEN_H , GREEN_IO  );
        determinte_led_state( press_inhg, BLUE_L  , BLUE_H  , BLUE_IO   );
        determinte_led_state( press_inhg, RED_L   , RED_H   , RED_IO    );
        printf("press_inhg: %f\n", press_inhg);
    }

    return 0;
}


