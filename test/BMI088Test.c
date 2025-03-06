#include "bmi088.h"

#include "unity.h"
#include "unity_fixture.h"

#include <stdint.h>

#include "bmi088_defs.h"

#include "WriteSpy.h"
#include "FakeRead.h"

TEST_GROUP( BMI088 );

bmi088_t fakeBmi =
{
    .i2c_write = WriteSpy_Write8Arr,
    .i2c_read  = FakeRead_Read8ArrDiffSize
};

TEST_SETUP( BMI088 )
{
    WriteSpy_Create( 10 );
    FakeRead_Create( 10, 10 );
}


TEST_TEAR_DOWN( BMI088 )
{
    WriteSpy_Destroy();
    FakeRead_Destroy();
}


TEST( BMI088, ReadSlaveAddressShiftedSentFirst )
{
    uint8_t rxBuff[ 1 ];
    bmi088_read( GYRO_SLAVE_ADDRESS, RATE_Z_MSB, rxBuff, 1, &fakeBmi );
    TEST_ASSERT_EQUAL( GYRO_SLAVE_ADDRESS << 1,FakeRead_GetLastCmd8Arr()[ 0 ] );
}


TEST( BMI088, ReadRegisterAddressSentSecond )
{
    uint8_t rxBuff[ 1 ];
    bmi088_read( GYRO_SLAVE_ADDRESS, RATE_Z_MSB, rxBuff, 1, &fakeBmi );
    TEST_ASSERT_EQUAL( RATE_Z_MSB, FakeRead_GetLastCmd8Arr()[ 1 ] );
}


TEST( BMI088, ReadReceivesOnlySpecifiedNumOfBytes )
{
    uint8_t fakeReading[] = { 0x22, 0x11, 0x01 };
    FakeRead_SetNextReading8Arr( fakeReading, sizeof( fakeReading ) );
    uint8_t expected[] = { 0x22, 0x11 };

    uint8_t rxBuff[ 2 ];
    bmi088_read( GYRO_SLAVE_ADDRESS,RATE_Z_MSB , rxBuff, sizeof( rxBuff ), &fakeBmi );
    TEST_ASSERT_EQUAL_UINT8_ARRAY( expected, rxBuff, sizeof( rxBuff ) );
}


TEST( BMI088, WriteSlaveAddressShiftedSentFirst )
{
    uint8_t data = 0x01;
    bmi088_write( ACC_SLAVE_ADDRESS, ACC_PWR_CTRL, data, &fakeBmi ); 
    TEST_ASSERT_EQUAL( ACC_SLAVE_ADDRESS << 1, WriteSpy_GetLastWrite8Arr()[ 0 ] );
}


TEST( BMI088, WriteRegisterAddressSentSecond )
{
    uint8_t data = 0x01;
    bmi088_write( ACC_SLAVE_ADDRESS, ACC_PWR_CTRL, data, &fakeBmi ); 
    TEST_ASSERT_EQUAL( ACC_PWR_CTRL, WriteSpy_GetLastWrite8Arr()[ 1 ] );
}


TEST( BMI088, WriteActualDataSentThird )
{
    uint8_t data = 0x01;
    bmi088_write( ACC_SLAVE_ADDRESS, ACC_PWR_CTRL, data, &fakeBmi ); 
    TEST_ASSERT_EQUAL( data, WriteSpy_GetLastWrite8Arr()[ 2 ] );
}
