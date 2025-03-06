#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "sysclk.h"


int main()
{
    HAL_Init();

    sysclk_config();

    UsartPrint_Init();

    // Application code ...

    // Super loop
    while (1)
    {
    }

    return 0;
}


