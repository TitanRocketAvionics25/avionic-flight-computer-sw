#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_gpio.h"

// PB8 - I2C1_SCL (AF04)
// PB9 - I2C1_SDA (AF04)
void HAL_I2C_MspInit( I2C_HandleTypeDef *hi2c )
{
    if ( hi2c->Instance == I2C1 )
    {
        __HAL_RCC_I2C1_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();

        GPIO_InitTypeDef imuI2C =
        {
            .Pin = GPIO_PIN_8 | GPIO_PIN_9,
            .Mode = GPIO_MODE_AF_OD,
            .Alternate = GPIO_AF4_I2C1,
            .Pull = GPIO_PULLUP,
            .Speed = GPIO_SPEED_FREQ_VERY_HIGH
        };

        HAL_GPIO_Init( GPIOB, &imuI2C );
    }
}
