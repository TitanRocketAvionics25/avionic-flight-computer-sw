#include "w25q64jvssiq.h"
#include "../../spiconf/spiconf.h"
#include "SPI1.h"
#include "delay.h"

uint16_t number_of_sectors;

/* Software reset requires two instructions Enable Reset (66h) and
* Reset (99h) and take approximately 30µS. No instructions 
* are accepted during */

void W25Q64JV_reset(void) {
    uint8_t data_tx[2];
    data_tx[0] = 0x66; // Enable Reset (66h)
    data_tx[1] = 0x99; // Reset (99h)

    spiconf_set_cs(0);
    spiconf_write(data_tx, 2);
    spiconf_set_cs(1);
}

/* Reads JEDEC ID */

uint32_t W25Q64JV_readID(void) {
    uint8_t data_tx = 0x9f; // Instruction for JEDEC ID. 
    uint8_t data_read[3];

    spiconf_set_cs(0);
    spiconf_write(&data_tx, 1);
    spiconf_read(data_read, 3);
    spiconf_set_cs(1);


    /* Manufacturer ID : Memory Type ID : Capacity ID */
    return ((data_read[0] << 16) | (data_read[1] << 8)| data_read[2]);
}

void W25Q64JV_number_of_sector(uint16_t sector_num) {
    number_of_sectors = sector_num;
}

void W25Q64JV_read(uint32_t sector, uint8_t offset, uint8_t *data_read, uint32_t size) {
    uint8_t data_tx[4];
    uint32_t mem_addr = (sector * 256) + offset;

    spiconf_set_cs(0);

    data_tx[0] = 0x03; // Enable read
    data_tx[1] = (mem_addr >> 16) & 0xFF; // MSB of mem_addr
    data_tx[2] = (mem_addr >> 8) & 0xFF;
    data_tx[3] = (mem_addr) & 0xFF; // LSB of mem_addr

    spiconf_write(data_tx, 4);
    spiconf_read(data_read, size);
    spiconf_set_cs(1);
}

static void write_enable(void) {
    uint8_t data_tx = 0x06; // Enable write
    spiconf_set_cs(0);
    spiconf_write(&data_tx, 1);
    spiconf_set_cs(1);
    delay(5); //5ms delay
}

static void write_disable(void) {
    uint8_t data_tx = 0x04;
    spiconf_set_cs(0);
    spiconf_write(&data_tx, 1);
    spiconf_set_cs(1);
    delay(5);
}

void W25Q64JV_erase_sector(uint16_t sector) {
    uint8_t data_tx[4]; 
    uint32_t mem_addr = sector * 16 * 256;

    write_enable();

    data_tx[0] = 0x20; //Erase Sector
    data_tx[1] = (mem_addr >> 16) & 0xFF; // MSB of mem_addr
    data_tx[2] = (mem_addr >> 8) & 0xFF; 
    data_tx[3] = (mem_addr) & 0xFF; // LSB of mem_addr
    
    spiconf_set_cs(0);
    spiconf_write(data_tx, 4);
    spiconf_set_cs(1);

    delay(500); // 400ms delay max for sector erase. Just to be sure 500ms.

    write_disable();
}

static uint32_t bytes_to_write (uint32_t size, uint16_t offset) {
    if ((size + offset) < 256 ) {
        return size;
    } else {
        return (256 - offset);
    }
}

void W25Q64JV_write(uint32_t page, uint16_t offset, uint8_t *data, uint32_t size) {
    uint8_t data_tx[260];
    uint32_t page_starting = page;
    uint32_t page_ending = page_starting + ((size + offset - 1) / 256);
    uint32_t page_nums = page_ending - page_starting;
    
    uint16_t sector_starting = page_starting / 16;
    uint16_t sector_ending = page_ending / 16;
    uint16_t sector_nums = sector_ending - sector_starting + 1;

    for (uint16_t i = 0; i < sector_nums; i++) {
        W25Q64JV_erase_sector(sector_starting++);
    }

    uint32_t idx_data = 0;
    for (uint32_t i = 0; i < page_nums; i++) {
        uint32_t mem_addr = (page_starting * 256) + offset;
        uint16_t bytes_remaining = bytes_to_write(size, offset);
        
        uint32_t idx_data_tx = 0;
        write_enable();

        data_tx[0] = 0x02; //page program
        data_tx[1] = (mem_addr >> 16) & 0xFF;
        data_tx[2] = (mem_addr >> 8) & 0xFF; 
        data_tx[3] = (mem_addr) & 0xFF;
        
        idx_data_tx = 5;

        uint16_t bytes_to_send = bytes_remaining + idx_data_tx;

        for (uint16_t j = 0; j < bytes_remaining; j++) {
            data_tx[idx_data_tx++] = data[j + idx_data];
        }

        spiconf_set_cs(0);
        spiconf_write(data_tx, bytes_to_send);
        spiconf_set_cs(1);

        page_starting++;
        offset = 0;
        size = size - bytes_remaining;
        idx_data = idx_data + bytes_remaining;

        delay(5); 
        write_disable();
    }

}


/*
 * 128 blocks (64KB)
 * 1 block = 16 sectors (4KB)
 * 1 sector = 16 pages (256 bytes)
 *
 */

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
