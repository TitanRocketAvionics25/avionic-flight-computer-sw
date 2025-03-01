#ifndef __BMI088_DEFS_H__
#define __BMI088_DEFS_H__

// Accelerometer Register Address Definitions
#define ACC_SOFTRESET       0x7EU
#define ACC_PWR_CTRL        0x7DU
#define ACC_PWR_CONF        0x7CU
#define ACC_SELF_TEST       0x6DU
#define INT_MAP_DATA        0x58U
#define INT2_IO_CTRL        0x54U
#define INT1_IO_CTRL        0x53U
#define ACC_FIFO_CONFIG_1   0x49U
#define ACC_FIFO_CONFIG_0   0x48U
#define FIFO_WTM_1          0x47U
#define FIFO_WTM_0          0x46U
#define FIFO_DOWNS          0x45U
#define ACC_RANGE           0x41U
#define ACC_CONF            0x40U
#define ACC_FIFO_DATA       0x26U
#define FIFO_LENGTH_1       0x25U
#define FIFO_LENGTH_0       0x24U
#define TEMP_LSB            0x23U
#define TEMP_MSB            0x22U
#define ACC_INT_STAT_1      0x1DU
#define SENSORTIME_2        0x1AU
#define SENSORTIME_1        0x19U
#define SENSORTIME_0        0x18U
#define ACC_Z_MSB           0x17U
#define ACC_Z_LSB           0x16U
#define ACC_Y_MSB           0x15U
#define ACC_Y_LSB           0x14U
#define ACC_X_MSB           0x13U
#define ACC_X_LSB           0x12U
#define ACC_STATUS          0x03U
#define ACC_ERR_REG         0x02U
#define ACC_CHIP_ID         0x00U


// Gyroscope Register Address Definitions
#define GYRO_FIFO_DATA      0x3FU
#define GYRO_FIFO_CONFIG_1  0x3EU
#define GYRO_FIFO_CONFIG_0  0x3DU
#define GYRO_SELF_TEST      0x3CU
#define FIFO_EXT_INT_S      0x34U
#define FIFO_WM_EN          0x1EU
#define INT3_INT4_IO_MAP    0x18U
#define INT3_INT4_IO_CONF   0x16U
#define GYRO_INT_CTRL       0x15U
#define GYRO_SOFTRESET      0x14U
#define GYRO_LMP1           0x11U
#define GYRO_BANDWIDTH      0x10U
#define GYRO_RANGE          0x0FU
#define FIFO_STATUS         0x0EU
#define GYRO_INT_STAT_1     0x0AU
#define RATE_Z_MSB          0x07U
#define RATE_Z_LSB          0x06U
#define RATE_Y_MSB          0x05U
#define RATE_Y_LSB          0x04U
#define RATE_X_MSB          0x03U
#define RATE_X_LSB          0x02U
#define GYRO_CHIP_ID        0x00U


// Accelerometer Register Bit Definitions
#define INT_MAP_DATA_INT1_FFULL_Pos                 0U
#define INT_MAP_DATA_INT1_FFULL_Msk                 0x1U << INT_MAP_DATA_INT1_FFULL_Pos
#define INT_MAP_DATA_INT1_FWM_Pos                   1U
#define INT_MAP_DATA_INT1_FWM_Msk                   0x1U << INT_MAP_DATA_INT1_FWM_Pos
#define INT_MAP_DATA_INT1_DRDY_Pos                  2U
#define INT_MAP_DATA_INT1_DRDY_Msk                  0x1U << INT_MAP_DATA_INT1_DRDY_Pos
#define INT_MAP_DATA_INT2_FFULL_Pos                 4U
#define INT_MAP_DATA_INT2_FFULL_Msk                 0x1U << INT_MAP_DATA_INT1_FFULL_Pos
#define INT_MAP_DATA_INT2_FWM_Pos                   5U
#define INT_MAP_DATA_INT2_FWM_Msk                   0x1U << INT_MAP_DATA_INT1_FWM_Pos
#define INT_MAP_DATA_INT2_DRDY_Pos                  6U
#define INT_MAP_DATA_INT2_DRDY_Msk                  0x1U << INT_MAP_DATA_INT1_DRDY_Pos

#define INT2_IO_CTRL_LVL_Pos                        1U
#define INT2_IO_CTRL_LVL_Msk                        0x1U << INT2_IO_CTRL_LVL_Pos
#define INT2_IO_CTRL_OD_Pos                         2U
#define INT2_IO_CTRL_OD_Msk                         0x1U << INT2_IO_CTRL_OD_Pos
#define INT2_IO_CTRL_OUT_Pos                        3U
#define INT2_IO_CTRL_OUT_Msk                        0x1U << INT2_IO_CTRL_OUT_Pos
#define INT2_IO_CTRL_IN_Pos                         4U
#define INT2_IO_CTRL_IN_Msk                         0x1U << INT2_IO_CTRL_IN_Pos

#define INT1_IO_CTRL_LVL_Pos                        1U
#define INT1_IO_CTRL_LVL_Msk                        0x1U << INT1_IO_CTRL_LVL_Pos
#define INT1_IO_CTRL_OD_Pos                         2U
#define INT1_IO_CTRL_OD_Msk                         0x1U << INT1_IO_CTRL_OD_Pos
#define INT1_IO_CTRL_OUT_Pos                        3U
#define INT1_IO_CTRL_OUT_Msk                        0x1U << INT1_IO_CTRL_OUT_Pos
#define INT1_IO_CTRL_IN_Pos                         4U
#define INT1_IO_CTRL_IN_Msk                         0x1U << INT1_IO_CTRL_IN_Pos

#define ACC_FIFO_CONFIG_1_INT2_EN_Pos               0U
#define ACC_FIFO_CONFIG_1_INT2_EN_Msk               0x1U << ACC_FIFO_CONFIG_1_INT2_EN_Pos
#define ACC_FIFO_CONFIG_1_INT1_EN_Pos               3U
#define ACC_FIFO_CONFIG_1_INT1_EN_Msk               0x1U << ACC_FIFO_CONFIG_1_INT1_EN_Pos
#define ACC_FIFO_CONFIG_1_EN_Pos                    6U
#define ACC_FIFO_CONFIG_1_EN_Msk                    0x1U << ACC_FIFO_CONFIG_1_EN_Pos

#define ACC_FIFO_CONFIG_0_MODE_Pos                  0U
#define ACC_FIFO_CONFIG_0_MODE_Msk                  0x1U << ACC_FIFO_CONFIG_0_MODE_Pos

#define FIFO_DOWNS_Pos                              4U
#define FIFO_DOWNS_Msk                              0x7U << FIFO_DOWNS_Pos

#define ACC_RANGE_Pos                               0U
#define ACC_RANGE_Msk                               0x3 << ACC_RANGE_Pos

#define ACC_CONF_ODR_Pos                            0U
#define ACC_CONF_ODR_Msk                            0xFU << ACC_CONF_ODR_Pos
#define ACC_CONF_BWP_Pos                            4U
#define ACC_CONF_BWP_Msk                            0xFU << ACC_CONF_BWP_Pos

#define ACC_INT_STAT_1_DRDY_Pos                     7U
#define ACC_INT_STAT_1_DRDY_Msk                     0x1U << ACC_INT_STAT_1_DRDY_Pos

#define ACC_STATUS_DRDY_Pos                         7U
#define ACC_STATUS_DRDY_Msk                         0x1U << ACC_STATUS_DRDY_Pos

#define ACC_ERR_REG_FATAL_ER_Pos                    0U
#define ACC_ERR_REG_FATAL_ER_Msk                    0x1U << ACC_ERR_REG_FATAL_ER_Pos
#define ACC_ERR_REG_ERROR_CODE_Pos                  2U
#define ACC_ERR_REG_ERROR_CODE_Msk                  0x3U << ACC_ERR_REG_ERROR_CODE_Pos


// Gyroscope Register Bit Definitions
#define GYRO_FIFO_CONFIG_0_WTR_MRK_LVL_Pos          0U
#define GYRO_FIFO_CONFIG_0_WTR_MRK_LVL_Msk          0x7FU << GYRO_FIFO_CONFIG_0_WTR_MRK_LVL_Pos

#define GYRO_SELF_TEST_TRIG_BIST_Pos                0U
#define GYRO_SELF_TEST_TRIG_BIST_Msk                0x1U << GYRO_SELF_TEST_TRIG_BIST_Pos
#define GYRO_SELF_TEST_BIST_RDY_Pos                 1U
#define GYRO_SELF_TEST_BIST_RDY_Msk                 0x1U << GYRO_SELF_TEST_BIST_RDY_Pos
#define GYRO_SELF_TEST_BIST_FAIL_Pos                2U
#define GYRO_SELF_TEST_BIST_FAIL_Msk                0x1U << GYRO_SELF_TEST_BIST_FAIL_Pos
#define GYRO_SELF_TEST_RATE_OK_Pos                  4U
#define GYRO_SELF_TEST_RATE_OK_Msk                  0x1U << GYRO_SELF_TEST_RATE_OK_Pos

#define FIFO_EXT_INT_S_FIFO_SRC_Pos                 4U
#define FIFO_EXT_INT_S_FIFO_SRC_Msk                 0x1U << FIFO_EXT_INT_S_FIFO_SRC_Pos
#define FIFO_EXT_INT_S_EN_FIFO_SYNC_Pos             5U
#define FIFO_EXT_INT_S_EN_FIFO_SYNC_Msk             0x1U << FIFO_EXT_INT_S_EN_FIFO_SYNC_Pos

#define INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Pos   0U
#define INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Msk   0x1U << INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Pos
#define INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT3_Pos   2U
#define INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT3_Msk   0x1U << INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT3_Pos
#define INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT4_Pos   5U
#define INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT4_Msk   0x1U << INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT4_Pos
#define INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT4_Pos   7U
#define INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT4_Msk   0x1U << INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Pos

#define INT3_INT4_IO_CONF_INT3_LVL_Pos              0U
#define INT3_INT4_IO_CONF_INT3_LVL_Msk              0x1U << INT3_INT4_IO_CONF_INT3_LVL_Pos
#define INT3_INT4_IO_CONF_INT3_OD_Pos               1U
#define INT3_INT4_IO_CONF_INT3_OD_Msk               0x1U << INT3_INT4_IO_CONF_INT3_OD_Pos
#define INT3_INT4_IO_CONF_INT4_LVL_Pos              2U
#define INT3_INT4_IO_CONF_INT4_LVL_Msk              0x1U << INT3_INT4_IO_CONF_INT3_LVL_Pos
#define INT3_INT4_IO_CONF_INT4_OD_Pos               3U
#define INT3_INT4_IO_CONF_INT4_OD_Msk               0x1U << INT3_INT4_IO_CONF_INT3_OD_Pos

#define GYRO_INT_CTRL_FIFO_INT_EN_Pos               6U
#define GYRO_INT_CTRL_FIFO_INT_EN_Msk               0x1U << GYRO_INT_CTRL_FIFO_INT_EN_Pos
#define GYRO_INT_CTRL_NEW_DATA_INT_EN_Pos           7U
#define GYRO_INT_CTRL_NEW_DATA_INT_EN_Msk           0x1U << GYRO_INT_CTRL_NEW_DATA_INT_EN_Pos

#define FIFO_STATUS_FRAME_COUNTER_Pos               0U
#define FIFO_STATUS_FRAME_COUNTER_Msk               0x7FU << FIFO_STATUS_FRAME_COUNTER_Pos
#define FIFO_STATUS_OVERRUN_Pos                     7U
#define FIFO_STATUS_OVERRUN_Msk                     0x1U << FIFO_STATUS_OVERRUN_Pos

#define GYRO_INT_STAT_1_FIFO_INT_Pos                4U
#define GYRO_INT_STAT_1_FIFO_INT_Msk                0x1U << GYRO_INT_STAT_1_FIFO_INT_Pos
#define GYRO_INT_STAT_1_DRDY_Pos                    7U
#define GYRO_INT_STAT_1_DRDY_Msk                    0x1U << GYRO_INT_STAT_1_DRDY_Pos

#endif
