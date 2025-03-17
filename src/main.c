#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "sysclk.h"

#define APB1_HZ 30E6

int main()
{
    HAL_Init();

    sysclk_config();

    UsartPrint_Init( APB1_HZ );

    // Application code ...

    // Super loop
    while (1)
    {
    }

    return 0;
}


