#include "delay.h"
#include "stm2f4xx.h"

#define CTRL_ENABLE         (1U << 0)
#define CTRL_CLKSRC         (1U << 2)
#define CTRL_COUNTFLAG      (1U << 16)
#define CTRL_TICKINT        (1U << 1)

volatile uint64_t mil;

void delay_init(uint32_t freq) {
    SysTick->LOAD = (freq/1000) - 1;

    /* Clear systick current value register */
    SysTick->VAL = 0;

    /* Enable systick and select internal clk src */
    SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

    /* Enable systick interrupt */
    SysTick->CTRL |= CTRL_TICKINT;
}

uint64_t milliseconds() {
    __disable_irq();
    uint64_t ml = mil;
    __enable_irq();
    return ml;
}

void delay(uint32_t time) {
    uint64_t start = milliseconds();
    while((milliseconds() - start) < (time + 1));
}

void SysTick_Handler(void) {
    mil++;
}
