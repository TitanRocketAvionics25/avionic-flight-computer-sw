#ifndef __BMP581_DEFS_H__
#define __BMP581_DEFS_H__


#define BMP581_SLAVE_ADDRESS    0x47

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


// Bit width definitions
#define BMP581_1BIT             0x1U
#define BMP581_2BIT             0x3U
#define BMP581_3BIT             0x7U
#define BMP581_4BIT             0xFU
#define BMP581_5BIT             0x1FU
#define BMP581_6BIT             0x3FU


// Register Bit Definitions
#define BMP581_OSR_EFF_T_Pos                        0U
#define BMP581_OSR_EFF_T_Msk                        BMP581_3BIT << BMP581_OSR_EFF_T_Pos
#define BMP581_OSR_EFF_P_Pos                        3U
#define BMP581_OSR_EFF_P_Msk                        BMP581_3BIT << BMP581_OSR_EFF_P_Pos
#define BMP581_OSR_EFF_IS_VALID_Pos                 7U
#define BMP581_OSR_EFF_IS_VALID_Msk                 BMP581_1BIT << BMP581_OSR_EFF_IS_VALID_Pos

#define BMP581_ODR_CONFIG_PWR_MODE_Pos              0U
#define BMP581_ODR_CONFIG_PWR_MODE_Msk              BMP581_2BIT << BMP581_ODR_CONFIG_PWR_MODE_Pos
#define BMP581_ODR_CONFIG_ODR_Pos                   2U
#define BMP581_ODR_CONFIG_ODR_Msk                   BMP581_5BIT << BMP581_ODR_CONFIG_ODR_Pos
#define BMP581_ODR_CONFIG_DEEP_DIS_Pos              7U
#define BMP581_ODR_CONFIG_DEEP_DIS_Msk              BMP581_1BIT << BMP581_ODR_CONFIG_DEEP_DIS_Pos

#define BMP581_OSR_CONFIG_T_Pos                     0U
#define BMP581_OSR_CONFIG_T_Msk                     BMP581_3BIT << BMP581_OSR_CONFIG_T_Pos
#define BMP581_OSR_CONFIG_P_Pos                     3U
#define BMP581_OSR_CONFIG_P_Msk                     BMP581_3BIT << BMP581_OSR_CONFIG_P_Pos
#define BMP581_OSR_CONFIG_PRESS_EN_Pos              6U
#define BMP581_OSR_CONFIG_PRESS_EN_Msk              BMP581_1BIT << BMP581_OSR_CONFIG_PRESS_EN_Pos

#define BMP581_OOR_CONFIG_THR_P_Pos                 0U
#define BMP581_OOR_CONFIG_THR_P_Msk                 BMP581_1BIT << BMP581_OOR_CONFIG_THR_P_Pos
#define BMP581_OOR_CONFIG_CNT_LIM_Pos               6U
#define BMP581_OOR_CONFIG_CNT_LIM_MSK               BMP581_2BIT << BMP581_OOR_CONFIG_CNT_LIM_Pos

#define BMP581_DSP_IIR_SET_T_Pos                    0U
#define BMP581_DSP_IIR_SET_T_Msk                    BMP581_3BIT << BMP581_DSP_IIR_SET_T_Pos
#define BMP581_DSP_IIR_SET_P_Pos                    3U
#define BMP581_DSP_IIR_SET_P_Msk                    BMP581_3BIT << BMP581_DSP_IIR_SET_P_Pos

#define BMP581_DSP_CONFIG_IRR_FLUSH_FORCED_EN_Pos   2U
#define BMP581_DSP_CONFIG_IRR_FLUSH_FORCED_EN_Msk   BMP581_1BIT << BMP581_DSP_CONFIG_IRR_FLUSH_FORCED_EN_Pos
#define BMP581_DSP_CONFIG_SHDW_SEL_IIR_T_Pos        3U
#define BMP581_DSP_CONFIG_SHDW_SEL_IIR_T_Msk        BMP581_1BIT << BMP581_DSP_CONFIG_SHDW_SEL_IIR_T_Pos
#define BMP581_DSP_CONFIG_FIFO_SEL_IIR_T_Pos        4U
#define BMP581_DSP_CONFIG_FIFO_SEL_IIR_T_Msk        BMP581_1BIT << BMP581_DSP_CONFIG_FIFO_SEL_IIR_T_Pos
#define BMP581_DSP_CONFIG_SHDW_SEL_IIR_P_Pos        5U
#define BMP581_DSP_CONFIG_SHDW_SEL_IIR_P_Msk        BMP581_1BIT << BMP581_DSP_CONFIG_SHDW_SEL_IIR_P_Pos
#define BMP581_DSP_CONFIG_FIFO_SEL_IIR_P_Pos        6U
#define BMP581_DSP_CONFIG_FIFO_SEL_IIR_P_Msk        BMP581_1BIT << BMP581_DSP_CONFIG_FIFO_SEL_IIR_P_Pos
#define BMP581_DSP_CONFIG_OOR_SEL_IIR_P_Pos         7U
#define BMP581_DSP_CONFIG_OOR_SEL_IIR_P_Msk         BMP581_1BIT << BMP581_DSP_CONFIG_OOR_SEL_IIR_P_Pos

#define BMP581_NVM_ADDR_ROW_ADDR_Pos                0U
#define BMP581_NVM_ADDR_ROW_ADDR_Msk                BMP581_6BIT << BMP581_NVM_ADDR_ROW_ADDR_Pos
#define BMP581_NVM_ADDR_PROG_EN_Pos                 6U
#define BMP581_NVM_ADDR_PROG_EN_Msk                 BMP581_1BIT << BMP581_NVM_ADDR_PROG_EN_Pos

#define BMP581_STATUS_CORE_RDY_Pos                  0U
#define BMP581_STATUS_CORE_RDY_Msk                  BMP581_1BIT << BMP581_STATUS_CORE_RDY_Pos
#define BMP581_STATUS_NVM_RDY_Pos                   1U
#define BMP581_STATUS_NVM_RDY_Msk                   BMP581_1BIT << BMP581_STATUS_NVM_RDY_Pos
#define BMP581_STATUS_NVM_ERR_Pos                   2U
#define BMP581_STATUS_NVM_ERR_Msk                   BMP581_1BIT << BMP581_STATUS_NVM_ERR_Pos
#define BMP581_STATUS_NVM_CMD_ERR_Pos               3U
#define BMP581_STATUS_NVM_CMD_ERR_Msk               BMP581_1BIT << BMP581_STATUS_NVM_CMD_ERR_Pos

#define BMP581_INT_STATUS_DRDY_Pos                  0U
#define BMP581_INT_STATUS_DRDY_Msk                  BMP581_1BIT << BMP581_INT_STATUS_DRDY_Pos
#define BMP581_INT_STATUS_FIFO_FULL_Pos             1U
#define BMP581_INT_STATUS_FIFO_FULL_Msk             BMP581_1BIT << BMP581_INT_STATUS_FIFO_FULL_Pos
#define BMP581_INT_STATUS_FIFO_THS_Pos              2U
#define BMP581_INT_STATUS_FIFO_THS_Msk              BMP581_1BIT << BMP581_INT_STATUS_FIFO_THS_Pos
#define BMP581_INT_STATUS_OOR_P_Pos                 3U
#define BMP581_INT_STATUS_OOR_P_Msk                 BMP581_1BIT << BMP581_INT_STATUS_OOR_P_Pos
#define BMP581_INT_STATUS_POR_Pos                   4U
#define BMP581_INT_STATUS_POR_Msk                   BMP581_1BIT << BMP581_INT_STATUS_POR_Pos

#define BMP581_FIFO_SEL_FRAME_Pos                   0U
#define BMP581_FIFO_SEL_FRAME_Msk                   BMP581_2BIT << BMP581_FIFO_SEL_FRAME_Pos
#define BMP581_FIFO_SEL_DEC_Pos                     2U
#define BMP581_FIFO_SEL_DEC_Msk                     BMP581_3BIT << BMP581_FIFO_SEL_DEC_Pos

#define BMP581_FIFO_COUNT_Pos                       0U
#define BMP581_FIFO_COUNT_Msk                       BMP581_6BIT << BMP581_FIFO_COUNT_Pos

#define BMP581_FIFO_CONFIG_THRESH_Pos               0U
#define BMP581_FIFO_CONFIG_THRESH_Msk               BMP581_5BIT << BMP581_FIFO_CONFIG_THRESH_Pos
#define BMP581_FIFO_CONFIG_MODE_Pos                 5U
#define BMP581_FIFO_CONFIG_MODE_Msk                 BMP581_1BIT << BMP581_FIFO_CONFIG_MODE_Pos

#define BMP581_INT_SOURCE_DRDY_EN_Pos               0U
#define BMP581_INT_SOURCE_DRDY_EN_Msk               BMP581_1BIT << BMP581_INT_SOURCE_DRDY_EN_Pos
#define BMP581_INT_SOURCE_FIFO_FULL_EN_Pos          1U
#define BMP581_INT_SOURCE_FIFO_FULL_EN_Msk          BMP581_1BIT << BMP581_INT_SOURCE_FIFO_FULL_EN_Pos
#define BMP581_INT_SOURCE_FIFO_THS_EN_Pos           2U
#define BMP581_INT_SOURCE_FIFO_THS_EN_Msk           BMP581_1BIT << BMP581_INT_SOURCE_FIFO_THS_EN_Pos
#define BMP581_INT_SOURCE_OOR_P_EN_Pos              3U
#define BMP581_INT_SOURCE_OOR_P_EN_Msk              BMP581_1BIT << BMP581_INT_SOURCE_OOR_P_EN_Pos

#define BMP581_INT_CONFIG_MODE_Pos                  0U
#define BMP581_INT_CONFIG_MODE_Msk                  BMP581_1BIT << BMP581_INT_CONFIG_MODE_Pos
#define BMP581_INT_CONFIG_POL_Pos                   1U
#define BMP581_INT_CONFIG_POL_Msk                   BMP581_1BIT << BMP581_INT_CONFIG_POL_Pos
#define BMP581_INT_CONFIG_OD_Pos                    2U
#define BMP581_INT_CONFIG_OD_Msk                    BMP581_1BIT << BMP581_INT_CONFIG_OD_Pos
#define BMP581_INT_CONFIG_EN_Pos                    3U
#define BMP581_INT_CONFIG_EN_Msk                    BMP581_1BIT << BMP581_INT_CONFIG_EN_Pos
#define BMP581_INT_CONFIG_PAD_DRV_Pos               4U
#define BMP581_INT_CONFIG_PAD_DRV_Msk               BMP581_4BIT << BMP581_INT_CONFIG_PAD_DRV_Pos

#define BMP581_DRIVE_CONFIG_I2C_CSB_PUP_EN_Pos      0U
#define BMP581_DRIVE_CONFIG_I2C_CSB_PUP_EN_Msk      BMP581_1BIT << BMP581_DRIVE_CONFIG_I2C_CSB_PUP_EN_Pos
#define BMP581_DRIVE_CONFIG_SPI3_EN_Pos             1U
#define BMP581_DRIVE_CONFIG_SPI3_EN_Msk             BMP581_1BIT << BMP581_DRIVE_CONFIG_SPI3_EN_Pos
#define BMP581_DRIVE_CONFIG_PAD_IF_DRV_Pos          4U
#define BMP581_DRIVE_CONFIG_PAD_IF_DRV_Msk          BMP581_4BIT << BMP581_DRIVE_CONFIG_PAD_IF_DRV_Pos

#define BMP581_CHIP_STATUS_HIF_MODE_Pos             0U
#define BMP581_CHIP_STATUS_HIF_MODE_Msk             BMP581_2BIT << BMP581_CHIP_STATUS_HIF_MODE_Pos
#define BMP581_CHIP_STATUS_I3C_ERR_0_Pos            2U
#define BMP581_CHIP_STATUS_I3C_ERR_0_Msk            BMP581_1BIT << BMP581_CHIP_STATUS_I3C_ERR_0_Pos
#define BMP581_CHIP_STATUS_I3C_ERR_3_Pos            3U
#define BMP581_CHIP_STATUS_I3C_ERR_3_Msk            BMP581_1BIT << BMP581_CHIP_STATUS_I3C_ERR_3_Pos


// Parameter Definitons

// CMD parameter definitions
#define BMP581_CMD_1 0x5D
#define BMP581_CMD_2 0x69
#define BMP581_CMD_3 0x73
#define BMP581_CMD_4 0xA0
#define BMP581_CMD_5 0xA5
#define BMP581_CMD_6 0xB4
#define BMP581_CMD_7 0xB6

// ODR_CONFIG parameter definitions
#define BMP581_ODR_CONFIG_PWR_MODE_STNBY            0x0
#define BMP581_ODR_CONFIG_PWR_MODE_NORM             0x1
#define BMP581_ODR_CONFIG_PWR_MODE_FORCED           0x2
#define BMP581_ODR_CONFIG_PWR_MODE_NON_STOP         0x3

#define BMP581_ODR_CONFIG_ODR_240_HZ                0x00
#define BMP581_ODR_CONFIG_ODR_218pt537_HZ           0x01
#define BMP581_ODR_CONFIG_ODR_199pt111_HZ           0x02
#define BMP581_ODR_CONFIG_ODR_179pt200_HZ           0x03
#define BMP581_ODR_CONFIG_ODR_160_HZ                0x04
#define BMP581_ODR_CONFIG_ODR_149pt333_HZ           0x05
#define BMP581_ODR_CONFIG_ODR_140_HZ                0x06
#define BMP581_ODR_CONFIG_ODR_129pt855_HZ           0x07
#define BMP581_ODR_CONFIG_ODR_120_HZ                0x08
#define BMP581_ODR_CONFIG_ODR_110pt164_HZ           0x09
#define BMP581_ODR_CONFIG_ODR_100pt299_HZ           0x0A
#define BMP581_ODR_CONFIG_ODR_89pt6_HZ              0x0B
#define BMP581_ODR_CONFIG_ODR_80_HZ                 0x0C
#define BMP581_ODR_CONFIG_ODR_70_HZ                 0x0D
#define BMP581_ODR_CONFIG_ODR_60_HZ                 0x0E
#define BMP581_ODR_CONFIG_ODR_50pt056_HZ            0x0F
#define BMP581_ODR_CONFIG_ODR_45pt025_HZ            0x10
#define BMP581_ODR_CONFIG_ODR_40_HZ                 0x11
#define BMP581_ODR_CONFIG_ODR_35_HZ                 0x12
#define BMP581_ODR_CONFIG_ODR_30_HZ                 0x13
#define BMP581_ODR_CONFIG_ODR_25pt005_HZ            0x14
#define BMP581_ODR_CONFIG_ODR_20_HZ                 0x15
#define BMP581_ODR_CONFIG_ODR_15_HZ                 0x16
#define BMP581_ODR_CONFIG_ODR_10_HZ                 0x17
#define BMP581_ODR_CONFIG_ODR_5_HZ                  0x18
#define BMP581_ODR_CONFIG_ODR_4_HZ                  0x19
#define BMP581_ODR_CONFIG_ODR_3_HZ                  0x1A
#define BMP581_ODR_CONFIG_ODR_2_HZ                  0x1B
#define BMP581_ODR_CONFIG_ODR_1_HZ                  0x1C
#define BMP581_ODR_CONFIG_ODR_pt500_HZ              0x1D
#define BMP581_ODR_CONFIG_ODR_pt250_HZ              0x1E
#define BMP581_ODR_CONFIG_ODR_pt125_HZ              0x1F

// OSR_CONFIG parameter definitions
#define BMP581_OSR_CONFIG_OSR_T_1X                  0x0
#define BMP581_OSR_CONFIG_OSR_T_2X                  0x1
#define BMP581_OSR_CONFIG_OSR_T_4X                  0x2
#define BMP581_OSR_CONFIG_OSR_T_8X                  0x3
#define BMP581_OSR_CONFIG_OSR_T_16X                 0x4
#define BMP581_OSR_CONFIG_OSR_T_32X                 0x5
#define BMP581_OSR_CONFIG_OSR_T_64X                 0x6
#define BMP581_OSR_CONFIG_OSR_T_128X                0x7

#define BMP581_OSR_CONFIG_OSR_P_1X                  0x0
#define BMP581_OSR_CONFIG_OSR_P_2X                  0x1
#define BMP581_OSR_CONFIG_OSR_P_4X                  0x2
#define BMP581_OSR_CONFIG_OSR_P_8X                  0x3
#define BMP581_OSR_CONFIG_OSR_P_16X                 0x4
#define BMP581_OSR_CONFIG_OSR_P_32X                 0x5
#define BMP581_OSR_CONFIG_OSR_P_64X                 0x6
#define BMP581_OSR_CONFIG_OSR_P_128X                0x7

// OOR_CONFIG parameter definitions
#define BMP581_OOR_CONFIG_CNT_LIM_1                 0x0
#define BMP581_OOR_CONFIG_CNT_LIM_3                 0x1
#define BMP581_OOR_CONFIG_CNT_LIM_7                 0x2
#define BMP581_OOR_CONFIG_CNT_LIM_15                0x3

// DSP_IIR parameter definitions
#define BMP581_DSP_IIR_T_BYPASS                     0x0
#define BMP581_DSP_IIR_T_COEF_1                     0x1
#define BMP581_DSP_IIR_T_COEF_3                     0x2
#define BMP581_DSP_IIR_T_COEF_7                     0x3
#define BMP581_DSP_IIR_T_COEF_15                    0x4
#define BMP581_DSP_IIR_T_COEF_31                    0x5
#define BMP581_DSP_IIR_T_COEF_63                    0x6
#define BMP581_DSP_IIR_T_COEF_127                   0x7

#define BMP581_DSP_IIR_P_BYPASS                     0x0
#define BMP581_DSP_IIR_P_COEF_1                     0x1
#define BMP581_DSP_IIR_P_COEF_3                     0x2
#define BMP581_DSP_IIR_P_COEF_7                     0x3
#define BMP581_DSP_IIR_P_COEF_15                    0x4
#define BMP581_DSP_IIR_P_COEF_31                    0x5
#define BMP581_DSP_IIR_P_COEF_63                    0x6
#define BMP581_DSP_IIR_P_COEF_127                   0x7

// FIFO_SEL parameter definitions
#define BMP581_FIFO_SEL_FRAME_SEL_FIFO_NOT_EN       0x0
#define BMP581_FIFO_SEL_FRAME_SEL_TEMP_DATA         0x1
#define BMP581_FIFO_SEL_FRAME_SEL_PRESS_DATA        0x2
#define BMP581_FIFO_SEL_FRAME_SEL_PRESS_TEMP_DATA   0x3

// FIFO_CONFIG parameter definitions
#define BMP581_FIFO_CONFIG_THRESH_DISABLE           0x0
#define BMP581_FIFO_CONFIG_THRESH_31_FRAMES         0x1F

#define BMP581_FIFO_CONFIG_MODE_STREAM_TO_FIFO      0x0
#define BMP581_FIFO_CONFIG_MODE_STOP_ON_FULL        0x1

// DRIVE_CONFIG parameter definitions
#define BMP581_DRIVE_CONFIG_SPI3_EN_4_WIRE_MODE     0x0
#define BMP581_DRIVE_CONFIG_SPI3_EN_3_WIRE_MODE     0x1

#define BMP581_CHIP_STATUS_HIF_MODE_I2C_ONLY        0x0
#define BMP581_CHIP_STATUS_HIF_MODE_SPI1_SPI2       0x1
#define BMP581_CHIP_STATUS_HIF_MODE_SPI0_SPI3       0x2
#define BMP581_CHIP_STATUS_HIF_MODE_SPI_I2C         0x3

#endif
