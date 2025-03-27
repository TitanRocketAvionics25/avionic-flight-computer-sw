#ifndef __SX127X_DEFS_H__
#define __SX127X_DEFS_H__


// Common register addresses
#define SX127X_REG_FIFO                                             0x00
#define SX127X_REG_OP_MODE                                          0x01

#define SX127X_REG_FRF_MSB                                          0x06
#define SX127X_REG_FRF_MID                                          0x07
#define SX127X_REG_FRF_LSB                                          0x08
#define SX127X_REG_PA_CONFIG                                        0x09
#define SX127X_REG_PA_RAMP                                          0x0A
#define SX127X_REG_OCP                                              0x0B
#define SX127X_REG_LNA                                              0x0C

#define SX127X_REG_DIO_MAPPING1                                     0x40
#define SX127X_REG_DIO_MAPPING2                                     0x41
#define SX127X_REG_VERSION                                          0x42

#define SX127X_REG_TCXO                                             0x4B
#define SX127X_REG_PA_DAC                                           0x4D
#define SX127X_REG_FORMER_TEMP                                      0x5B

#define SX127X_REG_AGC_REF                                          0x61
#define SX127X_REG_AGC_THRESH1                                      0x62
#define SX127X_REG_AGC_THRESH2                                      0x63
#define SX127X_REG_AGC_THRESH3                                      0x64
#define SX127X_REG_PII                                              0x70


// FSK/OOK Mode register addresses 
#define SX127X_REG_BITRATE_MSB                                      0x02
#define SX127X_REG_BITRATE_LSB                                      0x03
#define SX127X_REG_FDEV_MSB                                         0x04
#define SX127X_REG_FDEV_LSB                                         0x05

#define SX127X_FSKOOK_REG_RX_CONFIG                                 0x0D
#define SX127X_FSKOOK_REG_RSSI_CONFIG                               0x0E
#define SX127X_FSKOOK_REG_RSSI_COLLISION                            0x0F
#define SX127X_FSKOOK_REG_RSSI_THRESH                               0x10
#define SX127X_FSKOOK_REG_RSSI_VALUE                                0x11
#define SX127X_FSKOOK_REG_RX_BW                                     0x12
#define SX127X_FSKOOK_REG_AFC_BW                                    0x13
#define SX127X_FSKOOK_REG_OOK_PEAK                                  0x14
#define SX127X_FSKOOK_REG_OOK_FIX                                   0x15
#define SX127X_FSKOOK_REG_OOK_AVG                                   0x16
#define SX127X_FSKOOK_REG_AFC_FEI                                   0x1A

#define SX127X_FSKOOK_REG_AFC_MSB                                   0x1B
#define SX127X_FSKOOK_REG_AFC_LSB                                   0x1C
#define SX127X_FSKOOK_REG_FEI_MSB                                   0x1D
#define SX127X_FSKOOK_REG_FEI_LSB                                   0x1E
#define SX127X_FSKOOK_REG_PREAMBLE_DETECT                           0x1F
#define SX127X_FSKOOK_REG_RX_TIMEOUT1                               0x20
#define SX127X_FSKOOK_REG_RX_TIMEOUT2                               0x21
#define SX127X_FSKOOK_REG_RX_TIMEOUT3                               0x22
#define SX127X_FSKOOK_REG_RX_DELAY                                  0x23
#define SX127X_FSKOOK_REG_OSC                                       0x24
#define SX127X_FSKOOK_REG_PREAMBLE_MSB                              0x25
#define SX127X_FSKOOK_REG_PREAMBLE_LSB                              0x26
#define SX127X_FSKOOK_REG_SYNC_CONFIG                               0x27
#define SX127X_FSKOOK_REG_SYNC_VALUE1                               0x28
#define SX127X_FSKOOK_REG_SYNC_VALUE2                               0x29
#define SX127X_FSKOOK_REG_SYNC_VALUE3                               0x2A
#define SX127X_FSKOOK_REG_SYNC_VALUE4                               0x2B
#define SX127X_FSKOOK_REG_SYNC_VALUE5                               0x2C
#define SX127X_FSKOOK_REG_SYNC_VALUE6                               0x2D
#define SX127X_FSKOOK_REG_SYNC_VALUE7                               0x2E
#define SX127X_FSKOOK_REG_SYNC_VALUE8                               0x2F
#define SX127X_FSKOOK_REG_PACKET_CONFIG1                            0x30
#define SX127X_FSKOOK_REG_PACKET_CONFIG2                            0x31
#define SX127X_FSKOOK_REG_PAYLOAD_LENGTH                            0x32
#define SX127X_FSKOOK_REG_NODE_ADRS                                 0x33
#define SX127X_FSKOOK_REG_BROADCAST_ADRS                            0x34
#define SX127X_FSKOOK_REG_FIFO_THRESH                               0x35
#define SX127X_FSKOOK_REG_SEQ_CONFIG1                               0x36
#define SX127X_FSKOOK_REG_SEQ_CONFIG2                               0x37
#define SX127X_FSKOOK_REG_TIMER_RESOL                               0x38
#define SX127X_FSKOOK_REG_TIMER1_COEF                               0x39

#define SX127X_FSKOOK_REG_TIMER2_COEF                               0x3A
#define SX127X_FSKOOK_REG_IMAGE_CAL                                 0x3B
#define SX127X_FSKOOK_REG_TEMP                                      0x3C
#define SX127X_FSKOOK_REG_LOW_BAT                                   0x3D
#define SX127X_FSKOOK_REG_IRQ_FLAGS1                                0x3E
#define SX127X_FSKOOK_REG_IRQ_FLAGS2                                0x3F
#define SX127X_FSKOOK_REG_PII_HOP                                   0x44
#define SX127X_FSKOOK_REG_BITRATE_FRAC                              0x5D


// LoRa Mode register addresses 
#define SX127X_LORA_REG_FIFO_ADDR_PTR                               SX127X_FSKOOK_REG_RX_CONFIG
#define SX127X_LORA_REG_FIFO_TX_BASE_ADDR                           SX127X_FSKOOK_REG_RSSI_CONFIG
#define SX127X_LORA_REG_FIFO_RX_BASE_ADDR                           SX127X_FSKOOK_REG_RSSI_COLLISION
#define SX127X_LORA_REG_FIFO_RX_CURRENT_ADDR                        SX127X_FSKOOK_REG_RSSI_THRESH
#define SX127X_LORA_REG_IRQ_FLAGS_MASK                              SX127X_FSKOOK_REG_RSSI_VALUE
#define SX127X_LORA_REG_IRQ_FLAGS                                   SX127X_FSKOOK_REG_RX_BW
#define SX127X_LORA_REG_RX_NB_BYTES                                 SX127X_FSKOOK_REG_AFC_BW
#define SX127X_LORA_REG_RX_HEADER_CNT_VALUE_MSB                     SX127X_FSKOOK_REG_OOK_PEAK
#define SX127X_LORA_REG_RX_HEADER_CNT_VALUE_LSB                     SX127X_FSKOOK_REG_OOK_FIX
#define SX127X_LORA_REG_RX_PACKET_CNT_VALUE_MSB                     SX127X_FSKOOK_REG_OOK_AVG
#define SX127X_LORA_REG_RX_PACKET_CNT_VALUE_LSB                     0x17
#define SX127X_LORA_REG_MODEM_STAT                                  0x18
#define SX127X_LORA_REG_PKT_SNR_VALUE                               0x19
#define SX127X_LORA_REG_PKT_RSSI_VALUE                              SX127X_FSKOOK_REG_AFC_FEI

#define SX127X_LORA_REG_RSSI_VALUE                                  SX127X_FSKOOK_REG_AFC_MSB         
#define SX127X_LORA_REG_HOP_CHANNEL                                 SX127X_FSKOOK_REG_AFC_LSB        
#define SX127X_LORA_REG_MODEM_CONFIG1                               SX127X_FSKOOK_REG_FEI_MSB        
#define SX127X_LORA_REG_MODEM_CONFIG2                               SX127X_FSKOOK_REG_FEI_LSB        
#define SX127X_LORA_REG_SYMB_TIMEOUT_LSB                            SX127X_FSKOOK_REG_PREAMBLE_DETECT
#define SX127X_LORA_REG_PREAMBLE_MSB                                SX127X_FSKOOK_REG_RX_TIMEOUT1    
#define SX127X_LORA_REG_PREAMBLE_LSB                                SX127X_FSKOOK_REG_RX_TIMEOUT2    
#define SX127X_LORA_REG_PAYLOAD_LENGTH                              SX127X_FSKOOK_REG_RX_TIMEOUT3    
#define SX127X_LORA_REG_MAX_PAYLOAD_LENGTH                          SX127X_FSKOOK_REG_RX_DELAY       
#define SX127X_LORA_REG_HOP_PERIOD                                  SX127X_FSKOOK_REG_OSC            
#define SX127X_LORA_REG_FIFO_RX_BYTE_ADDR                           SX127X_FSKOOK_REG_PREAMBLE_MSB   
#define SX127X_LORA_REG_MODEM_CONFIG3                               SX127X_FSKOOK_REG_PREAMBLE_LSB   
#define SX127X_LORA_REG_FEI_MSB                                     SX127X_FSKOOK_REG_SYNC_VALUE1
#define SX127X_LORA_REG_FEI_MID                                     SX127X_FSKOOK_REG_SYNC_VALUE2
#define SX127X_LORA_REG_FEI_LSB                                     SX127X_FSKOOK_REG_SYNC_VALUE3
#define SX127X_LORA_REG_RSSI_WIDEBAND                               SX127X_FSKOOK_REG_SYNC_VALUE5
#define SX127X_LORA_REG_DETECT_OPTIMIZE                             SX127X_FSKOOK_REG_PACKET_CONFIG2
#define SX127X_LORA_REG_INVERT_IQ                                   SX127X_FSKOOK_REG_NODE_ADRS
#define SX127X_LORA_REG_DETECTION_THRESHOLD                         SX127X_FSKOOK_REG_SEQ_CONFIG2
#define SX127X_LORA_REG_SYNC_WORD                                   SX127X_FSKOOK_REG_TIMER1_COEF


// Bit width definitions
#define SX127X_1BIT                                                 0x1U
#define SX127X_2BIT                                                 0x3U
#define SX127X_3BIT                                                 0x7U
#define SX127X_4BIT                                                 0xFU
#define SX127X_5BIT                                                 0x1FU
#define SX127X_6BIT                                                 0x3FU


// Common register bit definitions
#define SX127X_REG_OP_MODE_MODE_Pos                                 0U
#define SX127X_REG_OP_MODE_MODE_Msk                                 ( SX127X_3BIT << SX127X_REG_OP_MODE_MODE_Pos )
#define SX127X_REG_OP_MODE_LOW_FREQ_MODE_ON_Pos                     3U
#define SX127X_REG_OP_MODE_LOW_FREQ_MODE_ON_Msk                     ( SX127X_1BIT << SX127X_REG_OP_MODE_LOW_FREQ_MODE_ON_Pos )
#define SX127X_REG_OP_MODE_MODULATION_TYPE_Pos                      5U
#define SX127X_REG_OP_MODE_MODULATION_TYPE_Msk                      ( SX127X_2BIT << SX127X_REG_OP_MODE_MODULATION_TYPE_Pos )
#define SX127X_REG_OP_MODE_LORA_MODE_Pos                            7U
#define SX127X_REG_OP_MODE_LORA_MODE_Msk                            ( SX127X_1BIT << SX127X_REG_OP_MODE_LORA_MODE_Pos )

#define SX127X_REG_PA_CONFIG_OUTPUT_PWR_Pos                         0U
#define SX127X_REG_PA_CONFIG_OUTPUT_PWR_Msk                         ( SX127X_4BIT << SX127X_REG_PA_CONFIG_OUTPUT_PWR_Pos )
#define SX127X_REG_PA_CONFIG_MAX_PWR_Pos                            4U
#define SX127X_REG_PA_CONFIG_MAX_PWR_Msk                            ( SX127X_3BIT << SX127X_REG_PA_CONFIG_MAX_PWR_Pos )
#define SX127X_REG_PA_CONFIG_SELECT_Pos                             7U
#define SX127X_REG_PA_CONFIG_SELECT_Msk                             ( SX127X_1BIT << SX127X_REG_PA_CONFIG_SELECT_Pos )

#define SX127X_REG_PA_RAMP_PA_RAMP_Pos                              0U
#define SX127X_REG_PA_RAMP_PA_RAMP_Msk                              ( SX127X_4BIT <<SX127X_REG_PA_RAMP_PA_RAMP_Pos )
#define SX127X_REG_PA_RAMP_MODULATION_SHAPING_Pos                   5U
#define SX127X_REG_PA_RAMP_MODULATION_SHAPING_Msk                   ( SX127X_2BIT << SX127X_REG_PA_RAMP_MODULATION_SHAPING_Pos )

#define SX127X_REG_OCP_TRIM_Pos                                     0U
#define SX127X_REG_OCP_TRIM_Msk                                     ( SX127X_5BIT << SX127X_REG_OCP_TRIM_Pos )
#define SX127X_REG_OCP_ON_Pos                                       5U
#define SX127X_REG_OCP_ON_Msk                                       ( SX127X_1BIT << SX127X_REG_OCP_ON_Pos )

#define SX127X_REG_LNA_BOOST_HF_Pos                                 0U
#define SX127X_REG_LNA_BOOST_HF_Msk                                 ( SX127X_2BIT << SX127X_REG_LNA_BOOST_HF_Pos )
#define SX127X_REG_LNA_BOOST_LF_Pos                                 3U
#define SX127X_REG_LNA_BOOST_LF_Msk                                 ( SX127X_2BIT << SX127X_REG_LNA_BOOST_LF_Pos )
#define SX127X_REG_LNA_GAIN_Pos                                     5U
#define SX127X_REG_LNA_GAIN_Msk                                     ( SX127X_3BIT << SX127X_REG_LNA_GAIN_Pos )

#define SX127X_REG_DIO_MAPPING1_DIO3_Pos                            0U
#define SX127X_REG_DIO_MAPPING1_DIO3_Msk                            ( SX127X_2BIT << SX127X_REG_DIO_MAPPING1_DIO3_Pos )
#define SX127X_REG_DIO_MAPPING1_DIO2_Pos                            2U
#define SX127X_REG_DIO_MAPPING1_DIO2_Msk                            ( SX127X_2BIT << SX127X_REG_DIO_MAPPING1_DIO2_Pos )
#define SX127X_REG_DIO_MAPPING1_DIO1_Pos                            4U
#define SX127X_REG_DIO_MAPPING1_DIO1_Msk                            ( SX127X_2BIT << SX127X_REG_DIO_MAPPING1_DIO1_Pos )
#define SX127X_REG_DIO_MAPPING1_DIO0_Pos                            6U
#define SX127X_REG_DIO_MAPPING1_DIO0_Msk                            ( SX127X_2BIT << SX127X_REG_DIO_MAPPING1_DIO0_Pos )

#define SX127X_REG_DIO_MAPPING2_DIO5_Pos                            4U
#define SX127X_REG_DIO_MAPPING2_DIO5_Msk                            ( SX127X_2BIT << SX127X_REG_DIO_MAPPING2_DIO5_Pos )
#define SX127X_REG_DIO_MAPPING2_DIO4_Pos                            6U
#define SX127X_REG_DIO_MAPPING2_DIO4_Msk                            ( SX127X_2BIT << SX127X_REG_DIO_MAPPING2_DIO4_Pos )

#define SX127X_REG_TCXO_INPUT_ON_Pos                                4U
#define SX127X_REG_TCXO_INPUT_ON_Msk                                ( SX127X_1BIT << SX127X_REG_TCXO_INPUT_ON_Pos )

#define SX127X_REG_PA_DAC_Pos                                       0U
#define SX127X_REG_PA_DAC_Msk                                       ( SX127X_3BIT << SX127X_REG_PA_DAC_Pos )

#define SX127X_REG_AGC_REF_LVL_Pos                                  0U
#define SX127X_REG_AGC_REF_LVL_Msk                                  ( SX127X_6BIT << SX127X_REG_AGC_REF_LVL_Pos )

#define SX127X_REG_AGC_THRESH1_STEP1_Pos                            0U
#define SX127X_REG_AGC_THRESH1_STEP1_Msk                            ( SX127X_5BIT << SX127X_REG_AGC_THRESH1_STEP1_Pos )

#define SX127X_REG_AGC_THRESH2_STEP3_Pos                            0U
#define SX127X_REG_AGC_THRESH2_STEP3_Msk                            ( SX127X_4BIT << SX127X_REG_AGC_THRESH2_STEP3_Pos )
#define SX127X_REG_AGC_THRESH2_STEP2_Pos                            4U
#define SX127X_REG_AGC_THRESH2_STEP2_Msk                            ( SX127X_4BIT << SX127X_REG_AGC_THRESH2_STEP2_Pos )

#define SX127X_REG_AGC_THRESH3_STEP5_Pos                            0U
#define SX127X_REG_AGC_THRESH3_STEP5_Msk                            ( SX127X_4BIT << SX127X_REG_AGC_THRESH3_STEP5_Pos )
#define SX127X_REG_AGC_THRESH3_STEP4_Pos                            4U
#define SX127X_REG_AGC_THRESH3_STEP4_Msk                            ( SX127X_4BIT << SX127X_REG_AGC_THRESH3_STEP4_Pos )

#define SX127X_REG_PII_BW_Pos                                       6U
#define SX127X_REG_PII_BW_Msk                                       ( SX127X_2BIT << SX127X_REG_PII_BW_Pos )


// FSK/OOK register bit definitions


// LoRa register bit definitions

#define SX127X_LORA_REG_IRQ_FLAGS_MASK_CAD_DETECTED_Pos             0U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_CAD_DETECTED_Msk             ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_CAD_DETECTED_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_FHSS_CHANGE_CHANNEL_Pos      1U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_FHSS_CHANGE_CHANNEL_Msk      ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_FHSS_CHANGE_CHANNEL_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_CAD_DONE_Pos                 2U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_CAD_DONE_Msk                 ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_CAD_DONE_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_TX_DONE_Pos                  3U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_TX_DONE_Msk                  ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_TX_DONE_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_VALID_HEADER_Pos             4U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_VALID_HEADER_Msk             ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_VALID_HEADER_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_PAYLOAD_CRC_ERR_Pos          5U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_PAYLOAD_CRC_ERR_Msk          ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_PAYLOAD_CRC_ERR_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_RX_DONE_Pos                  6U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_RX_DONE_Msk                  ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_RX_DONE_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_RX_TIMEOUT_Pos               7U
#define SX127X_LORA_REG_IRQ_FLAGS_MASK_RX_TIMEOUT_Msk               ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_MASK_RX_TIMEOUT_Pos )

#define SX127X_LORA_REG_IRQ_FLAGS_CAD_DETECTED_Pos                  0U
#define SX127X_LORA_REG_IRQ_FLAGS_CAD_DETECTED_Msk                  ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_CAD_DETECTED_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_FHSS_CHANGE_CHANNEL_Pos           1U
#define SX127X_LORA_REG_IRQ_FLAGS_FHSS_CHANGE_CHANNEL_Msk           ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_FHSS_CHANGE_CHANNEL_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_CAD_DONE_Pos                      2U
#define SX127X_LORA_REG_IRQ_FLAGS_CAD_DONE_Msk                      ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_CAD_DONE_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_TX_DONE_Pos                       3U
#define SX127X_LORA_REG_IRQ_FLAGS_TX_DONE_Msk                       ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_TX_DONE_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_VALID_HEADER_Pos                  4U
#define SX127X_LORA_REG_IRQ_FLAGS_VALID_HEADER_Msk                  ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_VALID_HEADER_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_PAYLOAD_CRC_ERR_Pos               5U
#define SX127X_LORA_REG_IRQ_FLAGS_PAYLOAD_CRC_ERR_Msk               ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_PAYLOAD_CRC_ERR_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_RX_DONE_Pos                       6U
#define SX127X_LORA_REG_IRQ_FLAGS_RX_DONE_Msk                       ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_RX_DONE_Pos )
#define SX127X_LORA_REG_IRQ_FLAGS_RX_TIMEOUT_Pos                    7U
#define SX127X_LORA_REG_IRQ_FLAGS_RX_TIMEOUT_Msk                    ( SX127X_1BIT << SX127X_LORA_REG_IRQ_FLAGS_RX_TIMEOUT_Pos )

#define SX127X_LORA_REG_MODEM_STAT_SIGNAL_DETECTED_Pos              0U
#define SX127X_LORA_REG_MODEM_STAT_SIGNAL_DETECTED_Msk              ( SX127X_1BIT << SX127X_LORA_REG_MODEM_STAT_SIGNAL_DETECTED_Pos )
#define SX127X_LORA_REG_MODEM_STAT_SIGNAL_SYNCED_Pos                1U
#define SX127X_LORA_REG_MODEM_STAT_SIGNAL_SYNCED_Msk                ( SX127X_1BIT << SX127X_LORA_REG_MODEM_STAT_SIGNAL_SYNCED_Pos )
#define SX127X_LORA_REG_MODEM_STAT_RX_ON_GOING_Pos                  2U
#define SX127X_LORA_REG_MODEM_STAT_RX_ON_GOING_Msk                  ( SX127X_1BIT << SX127X_LORA_REG_MODEM_STAT_RX_ON_GOING_Pos )
#define SX127X_LORA_REG_MODEM_HEADER_INFO_VALID_Pos                 3U
#define SX127X_LORA_REG_MODEM_HEADER_INFO_VALID_Msk                 ( SX127X_1BIT << SX127X_LORA_REG_MODEM_HEADER_INFO_VALID_Pos )
#define SX127X_LORA_REG_MODEM_MODEM_CLEAR_Pos                       4U
#define SX127X_LORA_REG_MODEM_MODEM_CLEAR_Msk                       ( SX127X_1BIT << SX127X_LORA_REG_MODEM_MODEM_CLEAR_Pos )
#define SX127X_LORA_REG_MODEM_RX_CODING_RATE_Pos                    5U
#define SX127X_LORA_REG_MODEM_RX_CODING_RATE_Msk                    ( SX127X_3BIT << SX127X_LORA_REG_MODEM_RX_CODING_RATE_Pos )

#define SX127X_LORA_REG_HOP_CHANNEL_FHSS_PRESENT_CHNL_Pos           0U
#define SX127X_LORA_REG_HOP_CHANNEL_FHSS_PRESENT_CHNL_Msk           ( SX127X_6BIT << SX127X_LORA_REG_HOP_CHANNEL_FHSS_PRESENT_CHNL_Pos )
#define SX127X_LORA_REG_HOP_CHANNEL_CRC_ON_PAYLOAD_Pos              6U
#define SX127X_LORA_REG_HOP_CHANNEL_CRC_ON_PAYLOAD_Msk              ( SX127X_1BIT << SX127X_LORA_REG_HOP_CHANNEL_CRC_ON_PAYLOAD_Pos )
#define SX127X_LORA_REG_HOP_CHANNEL_PII_TIMEOUT_Pos                 7U
#define SX127X_LORA_REG_HOP_CHANNEL_PII_TIMEOUT_Msk                 ( SX127X_1BIT << SX127X_LORA_REG_HOP_CHANNEL_PII_TIMEOUT_Pos )

#define SX127X_LORA_REG_MODEM_CONFIG1_IMPLICIT_HEADER_ON_Pos        0U
#define SX127X_LORA_REG_MODEM_CONFIG1_IMPLICIT_HEADER_ON_Msk        ( SX127X_1BIT << SX127X_LORA_REG_MODEM_CONFIG1_IMPLICIT_HEADER_ON_Pos )
#define SX127X_LORA_REG_MODEM_CONFIG1_CODING_RATE_Pos               1U
#define SX127X_LORA_REG_MODEM_CONFIG1_CODING_RATE_Msk               ( SX127X_3BIT << SX127X_LORA_REG_MODEM_CONFIG1_CODING_RATE_Pos )
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_Pos                        4U
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_Msk                        ( SX127X_4BIT << SX127X_LORA_REG_MODEM_CONFIG1_BW_Pos )

#define SX127X_LORA_REG_MODEM_CONFIG2_SYMB_TIMEOUT_Pos              0U
#define SX127X_LORA_REG_MODEM_CONFIG2_SYMB_TIMEOUT_Msk              ( SX127X_2BIT << SX127X_LORA_REG_MODEM_CONFIG2_SYMB_TIMEOUT_Pos )
#define SX127X_LORA_REG_MODEM_CONFIG2_RX_PAYLOAD_CRC_ON_Pos         2U
#define SX127X_LORA_REG_MODEM_CONFIG2_RX_PAYLOAD_CRC_ON_Msk         ( SX127X_1BIT << SX127X_LORA_REG_MODEM_CONFIG2_RX_PAYLOAD_CRC_ON_Pos )
#define SX127X_LORA_REG_MODEM_CONFIG2_TX_CONTINUOUS_MODE_Pos        3U
#define SX127X_LORA_REG_MODEM_CONFIG2_TX_CONTINUOUS_MODE_Msk        ( SX127X_1BIT << SX127X_LORA_REG_MODEM_CONFIG2_TX_CONTINUOUS_MODE_Pos )
#define SX127X_LORA_REG_MODEM_CONFIG2_SPREADING_FACTOR_Pos          4U
#define SX127X_LORA_REG_MODEM_CONFIG2_SPREADING_FACTOR_Msk          ( SX127X_4BIT << SX127X_LORA_REG_MODEM_CONFIG2_SPREADING_FACTOR_Pos )

#define SX127X_LORA_REG_MODEM_CONFIG3_AGC_AUTO_ON_Pos               2U
#define SX127X_LORA_REG_MODEM_CONFIG3_AGC_AUTO_ON_Msk               ( SX127X_1BIT << SX127X_LORA_REG_MODEM_CONFIG3_AGC_AUTO_ON_Pos )
#define SX127X_LORA_REG_MODEM_CONFIG3_LOW_DATA_RATE_OPTIMIZE_Pos    3U
#define SX127X_LORA_REG_MODEM_CONFIG3_LOW_DATA_RATE_OPTIMIZE_Msk    ( SX127X_1BIT << SX127X_LORA_REG_MODEM_CONFIG3_LOW_DATA_RATE_OPTIMIZE_Pos )

#define SX127X_LORA_REG_FEI_MSB_FREQ_ERR_Pos                        0U
#define SX127X_LORA_REG_FEI_MSB_FREQ_ERR_Msk                        ( SX127X_4BIT << SX127X_LORA_REG_FEI_MSB_FREQ_ERR_Pos )

#define SX127X_LORA_REG_DETECT_OPTIMIZE_Pos                         0u
#define SX127X_LORA_REG_DETECT_OPTIMIZE_Msk                         ( SX127X_3BIT << SX127X_LORA_REG_DETECT_OPTIMIZE_Pos )

#define SX127X_LORA_REG_INVERT_IQ_Pos                               6U
#define SX127X_LORA_REG_INVERT_IQ_Msk                               ( SX127X_1BIT << SX127X_LORA_REG_INVERT_IQ_Pos )


// Parameter definitions

// RegOpMode parameters
#define SX127X_REG_OP_MODE_STDBY            0x1
#define SX127X_REG_OP_MODE_FSTX             0x2
#define SX127X_REG_OP_MODE_TX               0x3
#define SX127X_REG_OP_MODE_FSRX             0x4
#define SX127X_REG_OP_MODE_RXCONTINUOUS     0x5
#define SX127X_REG_OP_MODE_RXSINGLE         0x6
#define SX127X_REG_OP_MODE_CAD              0x7


// RegModemConfig1 parameters
#define SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr5      0x1
#define SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr6      0x2
#define SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr7      0x3
#define SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr8      0x4

#define SX127X_LORA_REG_MODEM_CONFIG1_BW_7pt8_KHZ       0x0
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_10pt4_KHZ      0x1
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_15pt6_KHZ      0x2
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_20pt8_KHZ      0x3
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_31pt25_KHZ     0x4
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_41pt7_KHZ      0x5
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_62pt5_KHZ      0x6
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_125_KHZ        0x7
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_250_KHZ        0x8
#define SX127X_LORA_REG_MODEM_CONFIG1_BW_500_KHZ        0x9

// RegModemConfig2 parameters
// NOTE: chips per symbol(CPS)
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_64_CPS     0x6
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_128_CPS    0x7
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_256_CPS    0x8
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_512_CPS    0x9
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_1024_CPS   0xA
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_2048_CPS   0xB
#define SX127X_LORA_REG_MODEM_CONFIG2_SF_4096_CPS   0xC




#endif
