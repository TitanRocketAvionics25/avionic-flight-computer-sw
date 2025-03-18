#include "w25q64jvssiq.h"
#include "SPI1.h"

/* Software reset requires two instructions Enable Reset (66h) and
* Reset (99h) and take approximately 30µS. No instructions 
* are accepted during */

void W25Q64JV_reset(void) {
    uint8_t t_data[2];
    t_data[0] = 0x66; // Enable Reset (66h)
    t_data[1] = 0x99; // Reset (99h)

    W25Q64JV_cs_low();
    SPI1_transmit(t_data, 2);
    W25Q64JV_cs_high();
}

/* Reads JEDEC ID */

uint32_t W25Q64JV_readID(void) {
    uint8_t t_data = 0x9f; // Instruction for JEDEC ID. 
    uint8_t r_data[3];

    W25Q64JV_cs_low();
    SPI1_transmit(&t_data, 1);
    SPI1_receive(r_data, 3);
    W25Q64JV_cs_high();


    /* Manufacturer ID : Memory Type ID : Capacity ID */
    return ((r_data[0] << 16) | (r_data[1] << 8)| r_data[2]);
}


/*
 * init bolierplate
 *
 * int main(void) {
 *  dealy_init(16000000);
 *  SPI1_pins_init();
 *  W25Q64JV_cs_pins_init();
 *  SPI1_config();
 *  W25Q64JV_reset();
 *  delay(10)
 *  
 * }
*/
