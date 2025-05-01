#ifndef W25Q64JVSSIQ_H_
#define W25Q64JVSSIQ_H_

#include "stdint.h"

/* Soft reset the flash */
void W25Q64JV_reset(void);

/* Return ID of the chip */
uint32_t W25Q64JV_readID(void);

/*
 * @brief This funtion will set hte number of sectors for W25Q64JVSSIQ
 * @param sector_num is the number of sectos available in W25Q65JVSSIQ
 * @return nothing
 * @see datasheet for number of sectors 
 */
void W25Q64JV_number_of_sector(uint16_t sector_num);

/*
 * @brief This function will read from W25Q64JVSSIQ
 * @param sector: sector number of the flash
 * @param offset: offset of the memory location to read
 * @param *r_data: pointer to the buffer that will store data that's read
 * @param size: size of data to be read
 * @return nothing 
 */
void W25Q64JV_read(uint32_t sector, uint8_t offset, uint8_t *r_data, uint32_t size);

/*
 * @brief This function will erase a sector of memory from W25Q64JVSSIQ
 * @param sector: sector number of flash
 * @return nothing
 */
void W25Q64JV_erase_sector(uint16_t sector);

/*
 * @brief This function will write to W25Q64JVSSIQ
 * @param sector: sector number of the flash
 * @param offset: offset of the memory location to read
 * @param *data_tx: pointer to the buffer that holds the data to be written
 * @param size: size of the the data to be written.
 * @return nothing
 */

void W25Q64JV_write(uint32_t page, uint16_t offset, uint8_t *data, uint32_t size);

#endif /* W25Q64JVSSIQ_H_ */
