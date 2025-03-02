#include "BMI088.h"

#include "unity.h"
#include "unity_fixture.h"

#include <stdint.h>

#include "BMI088_defs.h"

#include "WriteSpy.h"
#include "FakeRead.h"

TEST_GROUP( BMI088 );


TEST_SETUP( BMI088 )
{
    WriteSpy_Create( 10 );
    FakeRead_Create( 10, 10 );

    BMI088Interface inter =
    {
        .i2cWrite = WriteSpy_Write8Arr,
        .i2cRead  = FakeRead_Read8ArrDiffSize
    };
    BMI088_SetInterface( &inter );
}


TEST_TEAR_DOWN( BMI088 )
{
    WriteSpy_Destroy();
    FakeRead_Destroy();
}


TEST( BMI088, RequireFullInterface )
{
    BMI088Interface inter =
    {
        .i2cWrite = WriteSpy_Write8Arr,
        .i2cRead = NULL
    };

    TEST_ASSERT_EQUAL( BMI088_FAIL, BMI088_SetInterface( &inter ) );

    inter.i2cRead = FakeRead_Read8ArrDiffSize;
    TEST_ASSERT_EQUAL( BMI088_SUCCESS, BMI088_SetInterface( &inter ) );
}


TEST( BMI088, ReadSlaveAddressShiftedSentFirst )
{
    uint8_t rxBuff[ 1 ];
    BMI088_Read( RATE_Z_MSB, rxBuff, 1 );
    TEST_ASSERT_EQUAL( SLAVE_ADDRESS << 1,FakeRead_GetLastCmd8Arr()[ 0 ] );
}


TEST( BMI088, ReadRegisterAddressSentSecond )
{
    uint8_t rxBuff[ 1 ];
    BMI088_Read( RATE_Z_MSB, rxBuff, 1 );
    TEST_ASSERT_EQUAL( RATE_Z_MSB, FakeRead_GetLastCmd8Arr()[ 1 ] );
}


TEST( BMI088, ReadReceivesOnlySpecifiedNumOfBytes )
{
    uint8_t fakeReading[] = { 0x22, 0x11, 0x01 };
    FakeRead_SetNextReading8Arr( fakeReading, sizeof( fakeReading ) );
    uint8_t expected[] = { 0x22, 0x11 };

    uint8_t rxBuff[ 2 ];
    BMI088_Read( RATE_Z_MSB, rxBuff, sizeof( rxBuff ) );
    TEST_ASSERT_EQUAL_UINT8_ARRAY( expected, rxBuff, sizeof( rxBuff ) );
}
