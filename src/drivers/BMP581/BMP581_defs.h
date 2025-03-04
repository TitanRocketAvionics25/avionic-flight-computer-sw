#ifndef __BMP581_DEFS_H__
#define __BMP581_DEFS_H__

// Register address definitions
#define BMP581_CMD              0x7E

#define BMP581_OSR_EFF          0x38
#define BMP581_ODR_CONFIG       0x37
#define BMP581_OSR_CONFIG       0x36
#define BMP581_OOR_CONFIG       0x35
#define BMP581_OOR_RANGE        0x34
#define BMP581_OOR_THR_P_MSB    0x33
#define BMP581_OOR_THR_P_LSB    0x32
#define BMP581_DSP_IIR          0x31
#define BMP581_DSP_CONFIG       0x30

#define BMP581_NVM_DATA_MSB     0x2D
#define BMP581_NVM_DATA_LSB     0x2C
#define BMP581_NVM_ADDR         0x2B

#define BMP581_FIFO_DATA        0x29
#define BMP581_STATUS           0x28
#define BMP581_INT_STATUS       0x27

#define BMP581_PRESS_DATA_MSB   0x22
#define BMP581_PRESS_DATA_LSB   0x21
#define BMP581_PRESS_DATA_XLSB  0x20
#define BMP581_TEMP_DATA_MSB    0x1F
#define BMP581_TEMP_DATA_LSB    0x1E
#define BMP581_TEMP_DATA_XLSB   0x1D

#define BMP581_FIFO_SEL         0x18
#define BMP581_FIFO_COUNT       0x17
#define BMP581_FIFO_CONFIG      0x16
#define BMP581_INT_SOURCE       0x15
#define BMP581_INT_CONFIG       0x14
#define BMP581_DRIVE_CONFIG     0x13

#define BMP581_CHIP_STATUS      0x11

#define BMP581_REV_ID           0x02
#define BMP581_CHIP_ID          0x01

#endif
