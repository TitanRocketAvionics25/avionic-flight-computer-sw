#include "stm32f4xx.h"

#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"

void HAL_UART_MspInit( UART_HandleTypeDef* huart )
{
    if ( huart->Instance == USART1 )
    {
        // Enable UART1 interface clock.
        __HAL_RCC_USART1_CLK_ENABLE();

        // Enable clock for UART1 GPIOS and configure for
        // UART1 (AF7), pull-up
        // PB6: UART1 TX
        // PB7: UART1 RX
        __HAL_RCC_GPIOB_CLK_ENABLE();
        GPIO_InitTypeDef uart1Gpio = { 0 };
        uart1Gpio.Pin       = GPIO_PIN_6 | GPIO_PIN_7;
        uart1Gpio.Alternate = GPIO_AF7_USART1;
        uart1Gpio.Mode      = GPIO_MODE_AF_PP;
        uart1Gpio.Pull      = GPIO_NOPULL;
        uart1Gpio.Speed     = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init( GPIOB, &uart1Gpio );

        // NVIC Configuration.
        HAL_NVIC_SetPriorityGrouping( NVIC_PRIORITYGROUP_4 );
        HAL_NVIC_SetPriority( USART1_IRQn, 1 , 1 );
        HAL_NVIC_EnableIRQ( USART1_IRQn );
    }
}
