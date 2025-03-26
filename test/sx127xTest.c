#include "sx127x.h"
#include "sx127x_defs.h"

#include "unity.h"
#include "unity_fixture.h"

#include <stdint.h>

#include "WriteSpy.h"
#include "FakeRead.h"


TEST_GROUP( SX127X );


static sx127x_t fakeSx =
{
    .spi_write  = WriteSpy_Write8Arr,
    .spi_read   = FakeRead_Read8Arr,
    .spi_cs_set = WriteSpy_Write8
};


TEST_SETUP( SX127X )
{
    WriteSpy_Create( 10 );
    FakeRead_Create( 10, 10 );
}


TEST_TEAR_DOWN( SX127X )
{
    WriteSpy_Destroy();
    FakeRead_Destroy();
}


TEST( SX127X, WriteRWBitHigh )
{
    uint8_t data = 0xCC;
    sx127x_write( SX127X_REG_LNA, &data, sizeof( data ), &fakeSx );
    TEST_ASSERT_BIT_HIGH( 7, WriteSpy_GetLastWrite8Arr()[ 0 ] );
}


TEST( SX127X, Write7BitAddressInFirstByte )
{
    uint8_t data = 0xCC;
    sx127x_write( SX127X_REG_LNA, &data, sizeof( data ), &fakeSx );
    TEST_ASSERT_BITS( 0x7F, SX127X_REG_LNA, WriteSpy_GetLastWrite8Arr()[ 0 ] );
}


TEST( SX127X, WriteDataInSecondByte )
{
    uint8_t data = 0xCC;
    sx127x_write( SX127X_REG_LNA, &data, sizeof( data ), &fakeSx );
    TEST_ASSERT_EQUAL( 0xCC, WriteSpy_GetLastWrite8Arr()[ 1 ] );
}


TEST( SX127X, WriteMultipleBytesSent )
{
    uint8_t data[] = { 0xCC, 0xBB, 0xAA };
    sx127x_write( SX127X_REG_LNA, data, sizeof( data ), &fakeSx );
    TEST_ASSERT_EQUAL_UINT8_ARRAY( data, &WriteSpy_GetLastWrite8Arr()[ 1 ], sizeof( data ) );
}


TEST( SX127X, ReadRWBitLow )
{
    uint8_t rx;
    sx127x_read( SX127X_REG_LNA, &rx, sizeof( rx ), &fakeSx );
    TEST_ASSERT_BIT_LOW( 7, FakeRead_GetLastCmd8Arr()[ 0 ] );
}


TEST( SX127X, Read7BitAddressInFirstByte )
{
    uint8_t rx;
    sx127x_read( SX127X_REG_LNA, &rx, sizeof( rx ), &fakeSx );
    TEST_ASSERT_BITS( 0x7F, SX127X_REG_LNA, FakeRead_GetLastCmd8Arr()[ 0 ] );
}


