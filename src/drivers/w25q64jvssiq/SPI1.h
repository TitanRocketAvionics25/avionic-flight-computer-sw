#ifndef SPI1_H_
#define SPI1_H_

#include "stdint.h"

void SPI1_pins_init(void);

void W25Q64JV_cs_pins_init(void);

void SPI1_config(void);

void SPI1_transmit(uint8_t *data, uint32_t size);

void SPI1_receive(uint8_t *data, uint32_t size);

void W25Q64JV_cs_low(void);

void W25Q64JV_cs_high(void);

#endif /* SPI1_H_ */
