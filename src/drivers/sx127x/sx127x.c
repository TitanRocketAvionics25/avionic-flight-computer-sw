#include "sx127x.h"
#include "sx127x_defs.h"


#define RW_MASK 0x80
#define WRITE_BUFF_SIZE 2
#define ADDR 0
#define DATA 1

#define CS_LOW   0
#define CS_HIGH  1


void sx127x_read( uint8_t startAddr, uint8_t* rxBuff, uint16_t rxSize, sx127x_t* sx )
{
    uint8_t dataBuff = startAddr & ~RW_MASK;
    sx->spi_cs_set( CS_LOW );
    // First send the starting address and RW bit.
    sx->spi_read( &dataBuff, rxBuff, sizeof( dataBuff ) );
    // After send dummy bytes, while receiving device data. Using
    // the receving buffer itself to transmit dummy bytes since it
    // will be the same size as the desired amount of bytes to receive.
    sx->spi_read( rxBuff, rxBuff, rxSize );
    sx->spi_cs_set( CS_HIGH );
}


uint8_t sx127x_read_byte( uint8_t addr, sx127x_t* sx )
{
    uint8_t received = 0;
    sx127x_read( addr, &received, sizeof( received ), sx );
    return received;
}


void sx127x_write( uint8_t startAddr, uint8_t* data, uint16_t dataSize, sx127x_t* sx )
{
    uint8_t dataBuff[ WRITE_BUFF_SIZE ] = { 0 };
    dataBuff[ ADDR ] = startAddr | RW_MASK;
    dataBuff[ DATA ] = data[ 0 ];

    sx->spi_cs_set( CS_LOW );
    sx->spi_write( dataBuff, sizeof( dataBuff ) );

    if ( dataSize > 1 )
    {
        sx->spi_write( &data[ 1 ], dataSize - 1 );
    }

    sx->spi_cs_set( CS_HIGH );
}


void sx127x_write_byte( uint8_t addr, uint8_t data, sx127x_t* sx )
{
    sx127x_write( addr, &data, sizeof( data ), sx );
}


void sx127x_reset( sx127x_t* sx )
{
    sx->rst_pin_set( 0 );
    sx->rst_pin_set( 1 );
}


void sx127x_sleep_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_OP_MODE, sx ) & ~SX127X_REG_OP_MODE_MODE_Msk;
    sx127x_write_byte( SX127X_REG_OP_MODE, cmd, sx );
}


void sx127x_standby_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_OP_MODE, sx ) & ~SX127X_REG_OP_MODE_MODE_Msk;
    cmd |= SX127X_REG_OP_MODE_STDBY << SX127X_REG_OP_MODE_MODE_Pos;
    sx127x_write_byte( SX127X_REG_OP_MODE, cmd, sx );
}


void sx127x_tx_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_OP_MODE, sx ) & ~SX127X_REG_OP_MODE_MODE_Msk;
    cmd |= SX127X_REG_OP_MODE_TX << SX127X_REG_OP_MODE_MODE_Pos;
    sx127x_write_byte( SX127X_REG_OP_MODE, cmd, sx );
}


void sx127x_rxcontinuous_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_OP_MODE, sx ) & ~SX127X_REG_OP_MODE_MODE_Msk;
    cmd |= SX127X_REG_OP_MODE_RXCONTINUOUS << SX127X_REG_OP_MODE_MODE_Pos;
    sx127x_write_byte( SX127X_REG_OP_MODE, cmd, sx );
}


void sx127x_rxsingle_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_OP_MODE, sx ) & ~SX127X_REG_OP_MODE_MODE_Msk;
    cmd |= SX127X_REG_OP_MODE_RXSINGLE << SX127X_REG_OP_MODE_MODE_Pos;
    sx127x_write_byte( SX127X_REG_OP_MODE, cmd, sx );
}


void sx127x_lora_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_OP_MODE, sx ) & 
                  ~( SX127X_REG_OP_MODE_LORA_MODE_Msk | SX127X_REG_OP_MODE_MODE_Msk );

    cmd |= ( 1 << SX127X_REG_OP_MODE_LORA_MODE_Pos );

    sx127x_write_byte( SX127X_REG_OP_MODE, cmd, sx );

    sx127x_standby_mode( sx );
}


void sx127x_set_freq( uint64_t freq, sx127x_t* sx )
{
    sx127x_standby_mode( sx );

    uint32_t frf = 0;
    frf = ( freq << 19 ) / 32E6;

    sx127x_write_byte( SX127X_REG_FRF_MSB, ( uint8_t )( frf >> 16 ), sx );
    sx127x_write_byte( SX127X_REG_FRF_MID, ( uint8_t )( frf >> 8 ), sx );
    sx127x_write_byte( SX127X_REG_FRF_LSB, ( uint8_t )  frf, sx );
}


void sx127x_set_implicit_header_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG1, sx ) | 
                  SX127X_LORA_REG_MODEM_CONFIG1_IMPLICIT_HEADER_ON_Msk;
    sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG1, cmd, sx );
}


void sx127x_set_explicit_header_mode( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG1, sx ) &
                  ~SX127X_LORA_REG_MODEM_CONFIG1_IMPLICIT_HEADER_ON_Msk;
    sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG1, cmd, sx );
}


void sx127x_set_coding_rate( uint8_t cr, sx127x_t* sx )
{
    if ( ( 4 >= cr ) && ( cr >= 0 ) )
    {
        uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG1, sx ) &
                      ~SX127X_LORA_REG_MODEM_CONFIG1_CODING_RATE_Msk;

        cmd |= cr << SX127X_LORA_REG_MODEM_CONFIG1_CODING_RATE_Pos;
        sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG1, cmd, sx );
    }
}


void sx127x_set_bandwidth( uint8_t bw, sx127x_t* sx )
{
    if ( ( 9 >= bw ) && ( bw >= 0 ) )
    {
        uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG1, sx ) &~
                      SX127X_LORA_REG_MODEM_CONFIG1_BW_Msk;

        cmd |= bw << SX127X_LORA_REG_MODEM_CONFIG1_BW_Pos;
        sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG1, cmd, sx );
    }
}


void sx127x_set_spreading_factor( uint8_t sf, sx127x_t* sx )
{
    if ( ( 12 >= sf ) && ( sf >= 6 ) )
    {
        uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG2, sx ) &~
                      SX127X_LORA_REG_MODEM_CONFIG2_SPREADING_FACTOR_Msk;

        cmd |= sf << SX127X_LORA_REG_MODEM_CONFIG2_SPREADING_FACTOR_Pos;
        sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG2, cmd, sx );
    }
}


void sx127x_crc_enable( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG2, sx ) |
                  SX127X_LORA_REG_MODEM_CONFIG2_RX_PAYLOAD_CRC_ON_Msk;
    sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG2, cmd, sx );
}


void sx127x_crc_disable( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_LORA_REG_MODEM_CONFIG2, sx ) &~
                  SX127X_LORA_REG_MODEM_CONFIG2_RX_PAYLOAD_CRC_ON_Msk;
    sx127x_write_byte( SX127X_LORA_REG_MODEM_CONFIG2, cmd, sx );
}
