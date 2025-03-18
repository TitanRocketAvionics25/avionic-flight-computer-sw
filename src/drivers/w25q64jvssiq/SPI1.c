#include "SPI1.h"
#include "stm32f4xx.h"

/* For SPI GPIO Initilization Function */
void SPI1_pins_init(void) {
    /* enable clock for GPIOA */
    RCC->AHB1NER |= RCC_AHB1ENR_GPI0AEN;

    /* set PA5, PA6, PA7 to alternate function mode */
    GPIOA->MODER |= GPIO_MODER_MODE5_1 | GPIO_MODER_MODE6_1 | GPIO_MODER_MODE7_1;
    GPIOA->MODER &= ~(GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0);

    GPIOA->OSPEEDR |= GIPO_OSPEEDER_OSPEEDR5 | SPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7;
    
    GPIOA->AFR[0] |= (0x05 << 20) | (0x05 << 24) | (0x05 << 28);

    /* Set pin high as initial state */
    GPIOA->BSRR = GPIO_BSRR_BS0;
}

/* For CS pins */
void W25Q64JV_cs_pins_init(void) {
    /* enable clock for GPIOA */
    RCC->AHB1ENR |= RCC_AHBENR_GPIOAEN;

	/*Set PA0 as output*/
	GPIOA->MODER |= GPIO_MODER_MODE0_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_1;

	/*Set pin high as initial state*/
	GPIOA->BSRR = GPIO_BSRR_BS0;
}

void SPI1_config(void) {
    /* Enable clock access to SPI1 module */
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

    /* Set clock to fPCLK/2 */
    SPI1->CR1 &= ~SPI_CR1_BR_0;
    SPI1->CR1 &= ~SPI_CR1_BR_1;
    SPI1->CR1 &= ~SPI_CR1_BR_2;
    
    /* Set CPOL to 0 and CPHS to 0 (MODE0) */
    SPI1->CR1 &= ~(SPI_CR1_CPOL);
    SPI1->CR1 &= ~(SPI_CR1_CPHA);

    /* Enable full duplex */
    SPI1->CR1 &= ~(SPI_CR1_RXONLY);

    /* Set MSB first */
    SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);

    /* Set mode to MASTER */
    SPI1->CR1 |= (SPI_CR1_MSTR);

    /* Set 8 bit data mode */
    SPI1->CR1 &= (SPI_CR1_DFF);

    /* Select software slave management by 
    * setting SSM=1 and SSI=1 */
    SPI1->CR1 |= (SPI_CR1_SSM);
    SPI1->CR1 |= (SPI_CR1_SSI);

    /* Enable SPI module */
    SPI->CR1 |= (SPI_CR1_SPE);
}

void SPI1_transmit(uint8_t *data, uint32_t size) {
    for(uint32_t i = 0; i < size; i++) {
        /* Wait until TXE is set */
        while(!(SPI->SR & (SPI_SR_TXE))) {}

        /* Write the data to the data register */
        SPI1->DR = data[i];
    }
    
    /* Wait until TXE is set */
    while(!(SPI1->SR & (SPI_SR_TXE))) {}

    /* Wait for BUSY flag to reset */
    while(!(SPI1->SR & (SPI_SR_BSY))) {}

    /* Clear OVR flag */
    (void)SPI1->DR;
    (void)SPI1->SR;
}

void SPI1_receive(uint8_t *data, uint32_t size) {
    while(size) {
        /* Send dummy data */
        SPI->DR = 0;

        /* Wait for RXNE flag to be set */
        while(!(SPI1->SR & (SPI_SR_RXNE))) {}

        /* Read data from data register */
        *data++ = (SPI->DR);
        size--;
    }
}

void W25Q64JV_cs_low(void) {
    GPIOA->BSRR = GPIO_BSRR_BR0;
}

void W25Q64JV_cs_high(void) {
    GPIOA->BSRR - GPIO_BSRR_BS0;
}
