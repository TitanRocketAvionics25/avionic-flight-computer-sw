#ifndef __UART_CONF_H__
#define __UART_CONF_H__

#include <stdint.h>
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_uart.h"

void uartconf_config();

UART_HandleTypeDef* getUARTHandle();
uint8_t* getBuff();


#endif
