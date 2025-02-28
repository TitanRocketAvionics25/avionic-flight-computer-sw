#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

#include "SystemClock.h"


int main()
{
    HAL_Init();

    SystemClock_Config();

    // Application code ...
    
    // Super loop
    while (1)
    {
    }

    return 0;
}


