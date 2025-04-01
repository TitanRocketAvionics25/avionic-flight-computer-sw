#include "sx127x.h"
#include "sx127x_defs.h"


// Mask for read/write bit in SPI transaction.
#define RW_MASK         0x80

// SPI write buffer size.
#define WRITE_BUFF_SIZE 2

// Indexes for SPI transaction buffer.
#define ADDR            0
#define DATA            1

// Chip select pin states.
#define CS_LOW          0
#define CS_HIGH         1


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


void sx127x_max_fifo( sx127x_t* sx )
{
    sx127x_write_byte( SX127X_LORA_REG_FIFO_TX_BASE_ADDR, 0x00, sx );
    sx127x_write_byte( SX127X_LORA_REG_FIFO_RX_BASE_ADDR, 0x00, sx );
}


void sx127x_pa_boost( sx127x_t* sx )
{
    uint8_t cmd = sx127x_read_byte( SX127X_REG_PA_CONFIG, sx ) | SX127X_REG_PA_CONFIG_SELECT_Msk;
    sx127x_write_byte( SX127X_REG_PA_CONFIG, cmd, sx );
}


void sx127x_transmit_packet( uint8_t* data, uint8_t size, sx127x_t* sx )
{
    // FIFO can only be filled in standby mode.
    sx127x_standby_mode( sx );

    // Initialize FIFO TX pointer to the TX base address.
    uint8_t fifoTxPtrBase = sx127x_read_byte( SX127X_LORA_REG_FIFO_TX_BASE_ADDR, sx );
    sx127x_write_byte( SX127X_LORA_REG_FIFO_ADDR_PTR, fifoTxPtrBase, sx );

    // Write data to FIFO.
    sx127x_write( SX127X_REG_FIFO, data, size, sx );

    // Set payload length.
    sx127x_write_byte( SX127X_LORA_REG_PAYLOAD_LENGTH, size, sx );

    // Begin transmission.
    sx127x_tx_mode( sx );

    // Wait for TxDone IRQ flag to be set.
    while( !( sx127x_read_byte( SX127X_LORA_REG_IRQ_FLAGS, sx ) & SX127X_LORA_REG_IRQ_FLAGS_TX_DONE_Msk ) );

    // Clear TxDone IRQ.
    sx127x_write_byte( SX127X_LORA_REG_IRQ_FLAGS, SX127X_LORA_REG_IRQ_FLAGS_TX_DONE_Msk, sx );

    // At the end of TxDone the tranciever is put into standby automatically.
}


uint8_t sx127x_receive_packet( uint8_t* buffer, uint8_t size, sx127x_t*sx )
{
    // Ensure RxDone flag is set (ideally from an interrupt).
    while ( !( sx127x_read_byte( SX127X_LORA_REG_IRQ_FLAGS, sx ) & SX127X_LORA_REG_IRQ_FLAGS_RX_DONE_Msk ) );

    // Read IRQ flags.
    uint8_t irq = sx127x_read_byte( SX127X_LORA_REG_IRQ_FLAGS, sx ); 

    // Clear flags.
    sx127x_write_byte( SX127X_LORA_REG_IRQ_FLAGS, SX127X_LORA_REG_IRQ_FLAGS_VALID_HEADER_Msk | 
                       SX127X_LORA_REG_IRQ_FLAGS_RX_DONE_Msk | 
                       SX127X_LORA_REG_IRQ_FLAGS_PAYLOAD_CRC_ERR_Msk, sx );

    uint8_t packetSize = 0;
    // Check ValidHeader flag set but not PayloadCrcError.
    if ( ( irq & SX127X_LORA_REG_IRQ_FLAGS_VALID_HEADER_Msk ) && 
        !( irq & SX127X_LORA_REG_IRQ_FLAGS_PAYLOAD_CRC_ERR_Msk ) ) 
    {
        // Read RegRxNbBytes to get size of latest packet and RegFifoRxCurrentAddr for location.
        packetSize = sx127x_read_byte( SX127X_LORA_REG_RX_NB_BYTES, sx );
        if ( packetSize > size )  packetSize = size;

        uint8_t packetLocation = sx127x_read_byte( SX127X_LORA_REG_FIFO_RX_CURRENT_ADDR, sx );

        // Set RegFifoAddrPtr to RegFifoRxCurrentAddr which sets ptr to location of latest packet.
        sx127x_write_byte( SX127X_LORA_REG_FIFO_ADDR_PTR, packetLocation, sx );

        // Read RegFifo RegRxNbBytes times
        sx127x_read( SX127X_REG_FIFO, buffer, packetSize, sx );
    }

    return packetSize;
}


