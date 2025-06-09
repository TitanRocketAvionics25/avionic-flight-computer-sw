#include "uartconf.h"

#include <stdio.h>

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_uart.h"

static UART_HandleTypeDef huart1 = { 0 };

void uartconf_config()
{
    huart1.Instance          = USART1;

    huart1.Init.BaudRate     = 38400;
    huart1.Init.WordLength   = UART_WORDLENGTH_8B;
    huart1.Init.StopBits     = UART_STOPBITS_1;
    huart1.Init.Parity       = UART_PARITY_NONE;
    huart1.Init.Mode         = UART_MODE_RX;
    huart1.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    huart1.hdmarx = NULL;

    HAL_UART_Init( &huart1 );
}

static uint8_t charBuff;

uint8_t* getBuff()
{
    return &charBuff;
}

UART_HandleTypeDef* getUARTHandle()
{
    return &huart1;
}

void USART1_Handler()
{
    HAL_UART_IRQHandler( &huart1 );
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_5 );
    HAL_UART_Receive_IT( &huart1, &charBuff, 1 );
}

// Executed during receive process
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
}
