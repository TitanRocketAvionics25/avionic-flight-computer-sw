#ifndef __delay_H__
#define __delay_H__

#include "stdint.h"

void delay_init(uint32_t freq);

uint64_t milliseconds();

void delay(uint32_t time);

#endif
