#ifndef __SX127X_DEFS_H__
#define __SX127X_DEFS_H__


// Common register addresses
#define SX127X_REG_FIFO                             0x00
#define SX127X_REG_OP_MODE                          0x01

#define SX127X_REG_FRF_MSB                          0x06
#define SX127X_REG_FRF_MID                          0x07
#define SX127X_REG_FRF_LSB                          0x08
#define SX127X_REG_PA_CONFIG                        0x09
#define SX127X_REG_PA_RAMP                          0x0A
#define SX127X_REG_OCP                              0x0B
#define SX127X_REG_LNA                              0x0C

#define SX127X_REG_DIO_MAPPING1                     0x40
#define SX127X_REG_DIO_MAPPING2                     0x41
#define SX127X_REG_VERSION                          0x42

#define SX127X_REG_TCXO                             0x4B
#define SX127X_REG_PA_DAC                           0x4D
#define SX127X_REG_FORMER_TEMP                      0x5B

#define SX127X_REG_AGC_REF                          0x61
#define SX127X_REG_AGC_THRESH1                      0x62
#define SX127X_REG_AGC_THRESH2                      0x63
#define SX127X_REG_AGC_THRESH3                      0x64
#define SX127X_REG_PII                              0x70


// FSK/OOK Mode register addresses 
#define SX127X_REG_BITRATE_MSB                      0x02
#define SX127X_REG_BITRATE_LSB                      0x03
#define SX127X_REG_FDEV_MSB                         0x04
#define SX127X_REG_FDEV_LSB                         0x05

#define SX127X_FSKOOK_REG_RX_CONFIG                 0x0D
#define SX127X_FSKOOK_REG_RSSI_CONFIG               0x0E
#define SX127X_FSKOOK_REG_RSSI_COLLISION            0x0F
#define SX127X_FSKOOK_REG_RSSI_THRESH               0x10
#define SX127X_FSKOOK_REG_RSSI_VALUE                0x11
#define SX127X_FSKOOK_REG_RX_BW                     0x12
#define SX127X_FSKOOK_REG_AFC_BW                    0x13
#define SX127X_FSKOOK_REG_OOK_PEAK                  0x14
#define SX127X_FSKOOK_REG_OOK_FIX                   0x15
#define SX127X_FSKOOK_REG_OOK_AVG                   0x16
#define SX127X_FSKOOK_REG_AFC_FEI                   0x1A

#define SX127X_FSKOOK_REG_AFC_MSB                   0x1B
#define SX127X_FSKOOK_REG_AFC_LSB                   0x1C
#define SX127X_FSKOOK_REG_FEI_MSB                   0x1D
#define SX127X_FSKOOK_REG_FEI_LSB                   0x1E
#define SX127X_FSKOOK_REG_PREAMBLE_DETECT           0x1F
#define SX127X_FSKOOK_REG_RX_TIMEOUT1               0x20
#define SX127X_FSKOOK_REG_RX_TIMEOUT2               0x21
#define SX127X_FSKOOK_REG_RX_TIMEOUT3               0x22
#define SX127X_FSKOOK_REG_RX_DELAY                  0x23
#define SX127X_FSKOOK_REG_OSC                       0x24
#define SX127X_FSKOOK_REG_PREAMBLE_MSB              0x25
#define SX127X_FSKOOK_REG_PREAMBLE_LSB              0x26
#define SX127X_FSKOOK_REG_SYNC_CONFIG               0x27
#define SX127X_FSKOOK_REG_SYNC_VALUE1               0x28
#define SX127X_FSKOOK_REG_SYNC_VALUE2               0x29
#define SX127X_FSKOOK_REG_SYNC_VALUE3               0x2A
#define SX127X_FSKOOK_REG_SYNC_VALUE4               0x2B
#define SX127X_FSKOOK_REG_SYNC_VALUE5               0x2C
#define SX127X_FSKOOK_REG_SYNC_VALUE6               0x2D
#define SX127X_FSKOOK_REG_SYNC_VALUE7               0x2E
#define SX127X_FSKOOK_REG_SYNC_VALUE8               0x2F
#define SX127X_FSKOOK_REG_PACKET_CONFIG1            0x30
#define SX127X_FSKOOK_REG_PACKET_CONFIG2            0x31
#define SX127X_FSKOOK_REG_PAYLOAD_LENGTH            0x32
#define SX127X_FSKOOK_REG_NODE_ADRS                 0x33
#define SX127X_FSKOOK_REG_BROADCAST_ADRS            0x34
#define SX127X_FSKOOK_REG_FIFO_THRESH               0x35
#define SX127X_FSKOOK_REG_SEQ_CONFIG1               0x36
#define SX127X_FSKOOK_REG_SEQ_CONFIG2               0x37
#define SX127X_FSKOOK_REG_TIMER_RESOL               0x38
#define SX127X_FSKOOK_REG_TIMER1_COEF               0x39

#define SX127X_FSKOOK_REG_TIMER2_COEF               0x3A
#define SX127X_FSKOOK_REG_IMAGE_CAL                 0x3B
#define SX127X_FSKOOK_REG_TEMP                      0x3C
#define SX127X_FSKOOK_REG_LOW_BAT                   0x3D
#define SX127X_FSKOOK_REG_IRQ_FLAGS1                0x3E
#define SX127X_FSKOOK_REG_IRQ_FLAGS2                0x3F
#define SX127X_FSKOOK_REG_PII_HOP                   0x44
#define SX127X_FSKOOK_REG_BITRATE_FRAC              0x5D


// LoRa Mode register addresses 
#define SX127X_LORA_REG_FIFO_ADDR_PTR               SX127X_FSKOOK_REG_RX_CONFIG
#define SX127X_LORA_REG_FIFO_TX_BASE_ADDR           SX127X_FSKOOK_REG_RSSI_CONFIG
#define SX127X_LORA_REG_FIFO_RX_BASE_ADDR           SX127X_FSKOOK_REG_RSSI_COLLISION
#define SX127X_LORA_REG_FIFO_RX_CURRENT_ADDR        SX127X_FSKOOK_REG_RSSI_THRESH
#define SX127X_LORA_REG_IRQ_FLAGS_MASK              SX127X_FSKOOK_REG_RSSI_VALUE
#define SX127X_LORA_REG_IRQ_FLAGS                   SX127X_FSKOOK_REG_RX_BW
#define SX127X_LORA_REG_RX_NB_BYTES                 SX127X_FSKOOK_REG_AFC_BW
#define SX127X_LORA_REG_RX_HEADER_CNT_VALUE_MSB     SX127X_FSKOOK_REG_OOK_PEAK
#define SX127X_LORA_REG_RX_HEADER_CNT_VALUE_LSB     SX127X_FSKOOK_REG_OOK_FIX
#define SX127X_LORA_REG_RX_PACKET_CNT_VALUE_MSB     SX127X_FSKOOK_REG_OOK_AVG
#define SX127X_LORA_REG_RX_PACKET_CNT_VALUE_LSB     0x17
#define SX127X_LORA_REG_MODEM_STAT                  0x18
#define SX127X_LORA_REG_PKT_SNR_VALUE               0x19
#define SX127X_LORA_REG_PKT_RSSI_VALUE              SX127X_FSKOOK_REG_AFC_FEI

#define SX127X_LORA_REG_RSSI_VALUE                  SX127X_FSKOOK_REG_AFC_MSB         
#define SX127X_LORA_REG_HOP_CHANNEL                 SX127X_FSKOOK_REG_AFC_LSB        
#define SX127X_LORA_REG_MODEM_CONFIG1               SX127X_FSKOOK_REG_FEI_MSB        
#define SX127X_LORA_REG_MODEM_CONFIG2               SX127X_FSKOOK_REG_FEI_LSB        
#define SX127X_LORA_REG_SYMB_TIMEOUT_LSB            SX127X_FSKOOK_REG_PREAMBLE_DETECT
#define SX127X_LORA_REG_PREAMBLE_MSB                SX127X_FSKOOK_REG_RX_TIMEOUT1    
#define SX127X_LORA_REG_PREAMBLE_LSB                SX127X_FSKOOK_REG_RX_TIMEOUT2    
#define SX127X_LORA_REG_PAYLOAD_LENGTH              SX127X_FSKOOK_REG_RX_TIMEOUT3    
#define SX127X_LORA_REG_MAX_PAYLOAD_LENGTH          SX127X_FSKOOK_REG_RX_DELAY       
#define SX127X_LORA_REG_HOP_PERIOD                  SX127X_FSKOOK_REG_OSC            
#define SX127X_LORA_REG_FIFO_RX_BYTE_ADDR           SX127X_FSKOOK_REG_PREAMBLE_MSB   
#define SX127X_LORA_REG_MODEM_CONFIG3               SX127X_FSKOOK_REG_PREAMBLE_LSB   
#define SX127X_LORA_REG_FEI_MSB                     SX127X_FSKOOK_REG_SYNC_VALUE1
#define SX127X_LORA_REG_FEI_MID                     SX127X_FSKOOK_REG_SYNC_VALUE2
#define SX127X_LORA_REG_FEI_LSB                     SX127X_FSKOOK_REG_SYNC_VALUE3
#define SX127X_LORA_REG_RSSI_WIDEBAND               SX127X_FSKOOK_REG_SYNC_VALUE5
#define SX127X_LORA_REG_DETECT_OPTIMIZE             SX127X_FSKOOK_REG_PACKET_CONFIG2
#define SX127X_LORA_REG_INVERT_IQ                   SX127X_FSKOOK_REG_NODE_ADRS
#define SX127X_LORA_REG_DETECTION_THRESHOLD         SX127X_FSKOOK_REG_SEQ_CONFIG2
#define SX127X_LORA_REG_SYNC_WORD                   SX127X_FSKOOK_REG_TIMER1_COEF


#endif
