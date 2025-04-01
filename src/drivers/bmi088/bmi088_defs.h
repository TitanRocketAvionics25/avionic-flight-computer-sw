#ifndef __BMI088_DEFS_H__
#define __BMI088_DEFS_H__

#define BMI088_ACC_SLAVE_ADDRESS   0x19U
#define BMI088_GYRO_SLAVE_ADDRESS  0x69U

// Accelerometer Register Address Definitions
#define BMI088_ACC_SOFTRESET       0x7EU
#define BMI088_ACC_PWR_CTRL        0x7DU
#define BMI088_ACC_PWR_CONF        0x7CU
#define BMI088_ACC_SELF_TEST       0x6DU
#define BMI088_INT_MAP_DATA        0x58U
#define BMI088_INT2_IO_CONF        0x54U
#define BMI088_INT1_IO_CONF        0x53U
#define BMI088_ACC_FIFO_CONFIG_1   0x49U
#define BMI088_ACC_FIFO_CONFIG_0   0x48U
#define BMI088_FIFO_WTM_1          0x47U
#define BMI088_FIFO_WTM_0          0x46U
#define BMI088_FIFO_DOWNS          0x45U
#define BMI088_ACC_RANGE           0x41U
#define BMI088_ACC_CONF            0x40U
#define BMI088_ACC_FIFO_DATA       0x26U
#define BMI088_FIFO_LENGTH_1       0x25U
#define BMI088_FIFO_LENGTH_0       0x24U
#define BMI088_TEMP_LSB            0x23U
#define BMI088_TEMP_MSB            0x22U
#define BMI088_ACC_INT_STAT_1      0x1DU
#define BMI088_SENSORTIME_2        0x1AU
#define BMI088_SENSORTIME_1        0x19U
#define BMI088_SENSORTIME_0        0x18U
#define BMI088_ACC_Z_MSB           0x17U
#define BMI088_ACC_Z_LSB           0x16U
#define BMI088_ACC_Y_MSB           0x15U
#define BMI088_ACC_Y_LSB           0x14U
#define BMI088_ACC_X_MSB           0x13U
#define BMI088_ACC_X_LSB           0x12U
#define BMI088_ACC_STATUS          0x03U
#define BMI088_ACC_ERR_REG         0x02U
#define BMI088_ACC_CHIP_ID         0x00U


// Gyroscope Register Address Definitions
#define BMI088_GYRO_FIFO_DATA      0x3FU
#define BMI088_GYRO_FIFO_CONFIG_1  0x3EU
#define BMI088_GYRO_FIFO_CONFIG_0  0x3DU
#define BMI088_GYRO_SELF_TEST      0x3CU
#define BMI088_FIFO_EXT_INT_S      0x34U
#define BMI088_FIFO_WM_EN          0x1EU
#define BMI088_INT3_INT4_IO_MAP    0x18U
#define BMI088_INT3_INT4_IO_CONF   0x16U
#define BMI088_GYRO_INT_CTRL       0x15U
#define BMI088_GYRO_SOFTRESET      0x14U
#define BMI088_GYRO_LMP1           0x11U
#define BMI088_GYRO_BANDWIDTH      0x10U
#define BMI088_GYRO_RANGE          0x0FU
#define BMI088_FIFO_STATUS         0x0EU
#define BMI088_GYRO_INT_STAT_1     0x0AU
#define BMI088_RATE_Z_MSB          0x07U
#define BMI088_RATE_Z_LSB          0x06U
#define BMI088_RATE_Y_MSB          0x05U
#define BMI088_RATE_Y_LSB          0x04U
#define BMI088_RATE_X_MSB          0x03U
#define BMI088_RATE_X_LSB          0x02U
#define BMI088_GYRO_CHIP_ID        0x00U


// Accelerometer Register Bit Definitions
#define BMI088_INT_MAP_DATA_INT1_FFULL_Pos                 0U
#define BMI088_INT_MAP_DATA_INT1_FFULL_Msk                 ( 0x1U << BMI088_INT_MAP_DATA_INT1_FFULL_Pos )
#define BMI088_INT_MAP_DATA_INT1_FWM_Pos                   1U
#define BMI088_INT_MAP_DATA_INT1_FWM_Msk                   ( 0x1U << BMI088_INT_MAP_DATA_INT1_FWM_Pos )
#define BMI088_INT_MAP_DATA_INT1_DRDY_Pos                  2U
#define BMI088_INT_MAP_DATA_INT1_DRDY_Msk                  ( 0x1U << BMI088_INT_MAP_DATA_INT1_DRDY_Pos )
#define BMI088_INT_MAP_DATA_INT2_FFULL_Pos                 4U
#define BMI088_INT_MAP_DATA_INT2_FFULL_Msk                 ( 0x1U << BMI088_INT_MAP_DATA_INT1_FFULL_Pos )
#define BMI088_INT_MAP_DATA_INT2_FWM_Pos                   5U
#define BMI088_INT_MAP_DATA_INT2_FWM_Msk                   ( 0x1U << BMI088_INT_MAP_DATA_INT1_FWM_Pos )
#define BMI088_INT_MAP_DATA_INT2_DRDY_Pos                  6U
#define BMI088_INT_MAP_DATA_INT2_DRDY_Msk                  ( 0x1U << BMI088_INT_MAP_DATA_INT1_DRDY_Pos )

#define BMI088_INT2_IO_CTRL_LVL_Pos                        1U
#define BMI088_INT2_IO_CTRL_LVL_Msk                        ( 0x1U << BMI088_INT2_IO_CTRL_LVL_Pos )
#define BMI088_INT2_IO_CTRL_OD_Pos                         2U
#define BMI088_INT2_IO_CTRL_OD_Msk                         ( 0x1U << BMI088_INT2_IO_CTRL_OD_Pos )
#define BMI088_INT2_IO_CTRL_OUT_Pos                        3U
#define BMI088_INT2_IO_CTRL_OUT_Msk                        ( 0x1U << BMI088_INT2_IO_CTRL_OUT_Pos )
#define BMI088_INT2_IO_CTRL_IN_Pos                         4U
#define BMI088_INT2_IO_CTRL_IN_Msk                         ( 0x1U << BMI088_INT2_IO_CTRL_IN_Pos )

#define BMI088_INT1_IO_CTRL_LVL_Pos                        1U
#define BMI088_INT1_IO_CTRL_LVL_Msk                        ( 0x1U << BMI088_INT1_IO_CTRL_LVL_Pos )
#define BMI088_INT1_IO_CTRL_OD_Pos                         2U
#define BMI088_INT1_IO_CTRL_OD_Msk                         ( 0x1U << BMI088_INT1_IO_CTRL_OD_Pos )
#define BMI088_INT1_IO_CTRL_OUT_Pos                        3U
#define BMI088_INT1_IO_CTRL_OUT_Msk                        ( 0x1U << BMI088_INT1_IO_CTRL_OUT_Pos )
#define BMI088_INT1_IO_CTRL_IN_Pos                         4U
#define BMI088_INT1_IO_CTRL_IN_Msk                         ( 0x1U << BMI088_INT1_IO_CTRL_IN_Pos )

#define BMI088_ACC_FIFO_CONFIG_1_INT2_EN_Pos               0U
#define BMI088_ACC_FIFO_CONFIG_1_INT2_EN_Msk               ( 0x1U << BMI088_ACC_FIFO_CONFIG_1_INT2_EN_Pos )
#define BMI088_ACC_FIFO_CONFIG_1_INT1_EN_Pos               3U
#define BMI088_ACC_FIFO_CONFIG_1_INT1_EN_Msk               ( 0x1U << BMI088_ACC_FIFO_CONFIG_1_INT1_EN_Pos )
#define BMI088_ACC_FIFO_CONFIG_1_EN_Pos                    6U
#define BMI088_ACC_FIFO_CONFIG_1_EN_Msk                    ( 0x1U << BMI088_ACC_FIFO_CONFIG_1_EN_Pos )

#define BMI088_ACC_FIFO_CONFIG_0_MODE_Pos                  0U
#define BMI088_ACC_FIFO_CONFIG_0_MODE_Msk                  ( 0x1U << BMI088_ACC_FIFO_CONFIG_0_MODE_Pos )

#define BMI088_FIFO_DOWNS_Pos                              4U
#define BMI088_FIFO_DOWNS_Msk                              ( 0x7U << BMI088_FIFO_DOWNS_Pos )

#define BMI088_ACC_RANGE_Pos                               0U
#define BMI088_ACC_RANGE_Msk                               ( 0x3 << BMI088_ACC_RANGE_Pos )

#define BMI088_ACC_CONF_ODR_Pos                            0U
#define BMI088_ACC_CONF_ODR_Msk                            ( 0xFU << BMI088_ACC_CONF_ODR_Pos )
#define BMI088_ACC_CONF_BWP_Pos                            4U
#define BMI088_ACC_CONF_BWP_Msk                            ( 0xFU << BMI088_ACC_CONF_BWP_Pos )

#define BMI088_ACC_INT_STAT_1_DRDY_Pos                     7U
#define BMI088_ACC_INT_STAT_1_DRDY_Msk                     ( 0x1U << BMI088_ACC_INT_STAT_1_DRDY_Pos )

#define BMI088_ACC_STATUS_DRDY_Pos                         7U
#define BMI088_ACC_STATUS_DRDY_Msk                         ( 0x1U << BMI088_ACC_STATUS_DRDY_Pos )

#define BMI088_ACC_ERR_REG_FATAL_ER_Pos                    0U
#define BMI088_ACC_ERR_REG_FATAL_ER_Msk                    ( 0x1U << BMI088_ACC_ERR_REG_FATAL_ER_Pos )
#define BMI088_ACC_ERR_REG_ERROR_CODE_Pos                  2U
#define BMI088_ACC_ERR_REG_ERROR_CODE_Msk                  ( 0x3U << BMI088_ACC_ERR_REG_ERROR_CODE_Pos )


// Gyroscope Register Bit Definitions
#define BMI088_GYRO_FIFO_CONFIG_0_WTR_MRK_LVL_Pos          0U
#define BMI088_GYRO_FIFO_CONFIG_0_WTR_MRK_LVL_Msk          ( 0x7FU << BMI088_GYRO_FIFO_CONFIG_0_WTR_MRK_LVL_Pos )

#define BMI088_GYRO_SELF_TEST_TRIG_BIST_Pos                0U
#define BMI088_GYRO_SELF_TEST_TRIG_BIST_Msk                ( 0x1U << BMI088_GYRO_SELF_TEST_TRIG_BIST_Pos )
#define BMI088_GYRO_SELF_TEST_BIST_RDY_Pos                 1U
#define BMI088_GYRO_SELF_TEST_BIST_RDY_Msk                 ( 0x1U << BMI088_GYRO_SELF_TEST_BIST_RDY_Pos )
#define BMI088_GYRO_SELF_TEST_BIST_FAIL_Pos                2U
#define BMI088_GYRO_SELF_TEST_BIST_FAIL_Msk                ( 0x1U << BMI088_GYRO_SELF_TEST_BIST_FAIL_Pos )
#define BMI088_GYRO_SELF_TEST_RATE_OK_Pos                  4U
#define BMI088_GYRO_SELF_TEST_RATE_OK_Msk                  ( 0x1U << BMI088_GYRO_SELF_TEST_RATE_OK_Pos )

#define BMI088_FIFO_EXT_INT_S_FIFO_SRC_Pos                 4U
#define BMI088_FIFO_EXT_INT_S_FIFO_SRC_Msk                 ( 0x1U << BMI088_FIFO_EXT_INT_S_FIFO_SRC_Pos )
#define BMI088_FIFO_EXT_INT_S_EN_FIFO_SYNC_Pos             5U
#define BMI088_FIFO_EXT_INT_S_EN_FIFO_SYNC_Msk             ( 0x1U << BMI088_FIFO_EXT_INT_S_EN_FIFO_SYNC_Pos )

#define BMI088_INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Pos   0U
#define BMI088_INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Msk   ( 0x1U << BMI088_INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Pos )
#define BMI088_INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT3_Pos   2U
#define BMI088_INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT3_Msk   ( 0x1U << BMI088_INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT3_Pos )
#define BMI088_INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT4_Pos   5U
#define BMI088_INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT4_Msk   ( 0x1U << BMI088_INT3_INT4_IO_MAP_FIFO_INT_MAPPED_INT4_Pos )
#define BMI088_INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT4_Pos   7U
#define BMI088_INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT4_Msk   ( 0x1U << BMI088_INT3_INT4_IO_MAP_DRDY_INT_MAPPED_INT3_Pos )

#define BMI088_INT3_INT4_IO_CONF_INT3_LVL_Pos              0U
#define BMI088_INT3_INT4_IO_CONF_INT3_LVL_Msk              ( 0x1U << BMI088_INT3_INT4_IO_CONF_INT3_LVL_Pos )
#define BMI088_INT3_INT4_IO_CONF_INT3_OD_Pos               1U
#define BMI088_INT3_INT4_IO_CONF_INT3_OD_Msk               ( 0x1U << BMI088_INT3_INT4_IO_CONF_INT3_OD_Pos )
#define BMI088_INT3_INT4_IO_CONF_INT4_LVL_Pos              2U
#define BMI088_INT3_INT4_IO_CONF_INT4_LVL_Msk              ( 0x1U << BMI088_INT3_INT4_IO_CONF_INT3_LVL_Pos )
#define BMI088_INT3_INT4_IO_CONF_INT4_OD_Pos               3U
#define BMI088_INT3_INT4_IO_CONF_INT4_OD_Msk               ( 0x1U << BMI088_INT3_INT4_IO_CONF_INT3_OD_Pos )

#define BMI088_GYRO_INT_CTRL_FIFO_INT_EN_Pos               6U
#define BMI088_GYRO_INT_CTRL_FIFO_INT_EN_Msk               ( 0x1U << BMI088_GYRO_INT_CTRL_FIFO_INT_EN_Pos )
#define BMI088_GYRO_INT_CTRL_NEW_DATA_INT_EN_Pos           7U
#define BMI088_GYRO_INT_CTRL_NEW_DATA_INT_EN_Msk           ( 0x1U << BMI088_GYRO_INT_CTRL_NEW_DATA_INT_EN_Pos )

#define BMI088_FIFO_STATUS_FRAME_COUNTER_Pos               0U
#define BMI088_FIFO_STATUS_FRAME_COUNTER_Msk               ( 0x7FU << BMI088_FIFO_STATUS_FRAME_COUNTER_Pos )
#define BMI088_FIFO_STATUS_OVERRUN_Pos                     7U
#define BMI088_FIFO_STATUS_OVERRUN_Msk                     ( 0x1U << BMI088_FIFO_STATUS_OVERRUN_Pos )

#define BMI088_GYRO_INT_STAT_1_FIFO_INT_Pos                4U
#define BMI088_GYRO_INT_STAT_1_FIFO_INT_Msk                ( 0x1U << BMI088_GYRO_INT_STAT_1_FIFO_INT_Pos )
#define BMI088_GYRO_INT_STAT_1_DRDY_Pos                    7U
#define BMI088_GYRO_INT_STAT_1_DRDY_Msk                    ( 0x1U << BMI088_GYRO_INT_STAT_1_DRDY_Pos )


// Accelerometer Parameter Definitions

// ACC_CONF Parameters
#define BMI088_ACC_CONF_BWP_OSR4                           0x08
#define BMI088_ACC_CONF_BWP_OSR2                           0x09
#define BMI088_ACC_CONF_BWP_NORMAL                         0x0A

#define BMI088_ACC_CONF_ODR_12_5_HZ                        0x05
#define BMI088_ACC_CONF_ODR_25_HZ                          0x06
#define BMI088_ACC_CONF_ODR_50_HZ                          0x07
#define BMI088_ACC_CONF_ODR_100_HZ                         0x08
#define BMI088_ACC_CONF_ODR_200_HZ                         0x09
#define BMI088_ACC_CONF_ODR_400_HZ                         0x0A
#define BMI088_ACC_CONF_ODR_800_HZ                         0x0B
#define BMI088_ACC_CONF_ODR_1600_HZ                        0x0C

// ACC_RANGE Parameters
#define BMI088_ACC_RANGE_3G                                0x00
#define BMI088_ACC_RANGE_6G                                0x01
#define BMI088_ACC_RANGE_12G                               0x02
#define BMI088_ACC_RANGE_24G                               0x03

// ACC_FIFO_CONFIG_0 Parameters
#define BMI088_ACC_FIFO_CONFIG_0_MODE_STREAM               0x00
#define BMI088_ACC_FIFO_CONFIG_0_MODE_FIFO                 0x01

// INT1_IO_CONF Parameters
#define BMI088_INT1_IO_CONF_OD_PP                          0x00
#define BMI088_INT1_IO_CONF_OD_OD                          0x01

#define BMI088_INT1_IO_CONF_LVL_ACTIVE_LOW                 0x00
#define BMI088_INT1_IO_CONF_LVL_ACTIVE_HIGH                0x01

// INT2_IO_CONF Parameters
#define BMI088_INT2_IO_CONF_OD_PP                          0x00
#define BMI088_INT2_IO_CONF_OD_OD                          0x01

#define BMI088_INT2_IO_CONF_LVL_ACTIVE_LOW                 0x00
#define BMI088_INT2_IO_CONF_LVL_ACTIVE_HIGH                0x01

// ACC_SELF_TEST Parameters
#define BMI088_ACC_SELF_TEST_OFF                           0x00
#define BMI088_ACC_SELF_TEST_ENABLE_POSITIVE               0x0D
#define BMI088_ACC_SELF_TEST_ENABLE_NEGATIVE               0x09

// ACC_PWR_CONF Parameters
#define BMI088_ACC_PWR_CONF_SUSPEND_MODE                   0x03
#define BMI088_ACC_PWR_CONF_ACTIVE_MODE                    0x00

// ACC_PWR_CTRL Parameters
#define BMI088_ACC_PWR_CTRL_ENABLE_OFF                     0x00
#define BMI088_ACC_PWR_CTRL_ENABLE_ON                      0x04


// Gyroscope Parameter Definitions

// GYRO_RANGE Parameters
#define BMI088_GYRO_RANGE_2000_DEG_S                       0x00
#define BMI088_GYRO_RANGE_1000_DEG_S                       0x01
#define BMI088_GYRO_RANGE_500_DEG_S                        0x02
#define BMI088_GYRO_RANGE_250_DEG_S                        0x03
#define BMI088_GYRO_RANGE_125_DEG_S                        0x04

// GYRO_BANDWIDTH Parameters
#define BMI088_GYRO_BANDWIDTH_ODR_2000_HZ_FILTER_532_HZ    0x00
#define BMI088_GYRO_BANDWIDTH_ODR_2000_HZ_FILTER_230_HZ    0x01
#define BMI088_GYRO_BANDWIDTH_ODR_1000_HZ_FILTER_116_HZ    0x02
#define BMI088_GYRO_BANDWIDTH_ODR_400_HZ_FILTER_47_HZ      0x03
#define BMI088_GYRO_BANDWIDTH_ODR_200_HZ_FILTER_23_HZ      0x04
#define BMI088_GYRO_BANDWIDTH_ODR_100_HZ_FILTER_12_HZ      0x05
#define BMI088_GYRO_BANDWIDTH_ODR_200_HZ_FILTER_64_HZ      0x06
#define BMI088_GYRO_BANDWIDTH_ODR_100_HZ_FILTER_32_HZ      0x07

// GYRO_LPM1 Parameters
#define BMI088_GYRO_LMP1_NORMAL_MODE                       0x00
#define BMI088_GYRO_LMP1_SUSPEND_MODE                      0x80
#define BMI088_GYRO_LMP1_DEEP_SUSPEND_MODE                 0x20

// INT3_INT4_IO_CONF Parameters
#define BMI088_INT3_INT4_IO_CONF_INT4_OD_PP                0x00
#define BMI088_INT3_INT4_IO_CONF_INT4_OD_OD                0x01
#define BMI088_INT3_INT4_IO_CONF_INT4_LVL_ACTIVE_LOW       0x00
#define BMI088_INT3_INT4_IO_CONF_INT4_LVL_ACTIVE_HIGH      0x01

#define BMI088_INT3_INT4_IO_CONF_INT3_OD_PP                0x00
#define BMI088_INT3_INT4_IO_CONF_INT3_OD_OD                0x01
#define BMI088_INT3_INT4_IO_CONF_INT3_LVL_ACTIVE_LOW       0x00
#define BMI088_INT3_INT4_IO_CONF_INT3_LVL_ACTIVE_HIGH      0x01

// FIFO_WM_ENABLE Parameters
#define BMI088_FIFO_WM_EN_INTERRUPT_DISABLE                0x08
#define BMI088_FIFO_WM_EN_INTERRUPT_ENABLE                 0x88

// FIFO_EXT_INT_S Parameters
#define BMI088_FIFO_EXT_INT_S_INT3_SOURCE                  0x00
#define BMI088_FIFO_EXT_INT_S_INT4_SOURCE                  0x01

// FIFO_CONFIG_1 Parameters
#define BMI088_GYRO_FIFO_CONFIG_1_MODE_FIFO                0x40
#define BMI088_GYRO_FIFO_CONFIG_1_MODE_STREAM              0x80

#endif
