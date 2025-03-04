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

#endif
