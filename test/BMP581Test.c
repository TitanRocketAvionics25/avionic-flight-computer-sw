#include "bmp581.h"

#include "unity.h"
#include "unity_fixture.h"

#include <stdint.h>

#include "bmp581_defs.h"

#include "WriteSpy.h"
#include "FakeRead.h"

TEST_GROUP( BMP581 );

bmp581_t fakeBmp =
{
    .i2c_write = WriteSpy_Write8Arr,
    .i2c_read  = FakeRead_Read8ArrDiffSize
};

TEST_SETUP( BMP581 )
{
    WriteSpy_Create( 10 );
    FakeRead_Create( 10, 10 );
}


TEST_TEAR_DOWN( BMP581 )
{
    WriteSpy_Destroy();
    FakeRead_Destroy();
}


TEST( BMP581, ReadSlaveAddressShiftedSentFirst )
{
    uint8_t rxBuff[ 1 ];
    bmp581_read( BMP581_SLAVE_ADDRESS, BMP581_PRESS_DATA_LSB, rxBuff, 1, &fakeBmp );
    TEST_ASSERT_EQUAL( BMP581_SLAVE_ADDRESS << 1,FakeRead_GetLastCmd8Arr()[ 0 ] );
}


TEST( BMP581, ReadRegisterAddressSentSecond )
{
    uint8_t rxBuff[ 1 ];
    bmp581_read( BMP581_SLAVE_ADDRESS, BMP581_PRESS_DATA_LSB, rxBuff, 1, &fakeBmp );
    TEST_ASSERT_EQUAL( BMP581_PRESS_DATA_LSB, FakeRead_GetLastCmd8Arr()[ 1 ] );
}


TEST( BMP581, ReadReceivesOnlySpecifiedNumOfBytes )
{
    uint8_t fakeReading[] = { 0x22, 0x11, 0x01 };
    FakeRead_SetNextReading8Arr( fakeReading, sizeof( fakeReading ) );
    uint8_t expected[] = { 0x22, 0x11 };

    uint8_t rxBuff[ 2 ];
    bmp581_read( BMP581_SLAVE_ADDRESS, BMP581_PRESS_DATA_LSB , rxBuff, sizeof( rxBuff ), &fakeBmp );
    TEST_ASSERT_EQUAL_UINT8_ARRAY( expected, rxBuff, sizeof( rxBuff ) );
}


TEST( BMP581, WriteSlaveAddressShiftedSentFirst )
{
    uint8_t data = 0x01;
    bmp581_write( BMP581_SLAVE_ADDRESS, BMP581_FIFO_CONFIG, data, &fakeBmp ); 
    TEST_ASSERT_EQUAL( BMP581_SLAVE_ADDRESS << 1, WriteSpy_GetLastWrite8Arr()[ 0 ] );
}


TEST( BMP581, WriteRegisterAddressSentSecond )
{
    uint8_t data = 0x01;
    bmp581_write( BMP581_SLAVE_ADDRESS, BMP581_FIFO_CONFIG, data, &fakeBmp ); 
    TEST_ASSERT_EQUAL( BMP581_FIFO_CONFIG, WriteSpy_GetLastWrite8Arr()[ 1 ] );
}


TEST( BMP581, WriteActualDataSentThird )
{
    uint8_t data = 0x01;
    bmp581_write( BMP581_SLAVE_ADDRESS, BMP581_FIFO_CONFIG, data, &fakeBmp ); 
    TEST_ASSERT_EQUAL( data, WriteSpy_GetLastWrite8Arr()[ 2 ] );
}
