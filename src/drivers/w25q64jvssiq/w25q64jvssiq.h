#ifndef W25Q64JVSSIQ_H_
#define W25Q64JVSSIQ_H_

#include "stdint.h"

/* Soft reset the flash */
void W25Q64JV_reset(void);

/* Return ID of the chip */
uint32_t W25Q64JV_readID(void);


#endif /* W25Q64JVSSIQ_H_ */
