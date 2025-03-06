#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER( BMP581 )
{
    RUN_TEST_CASE( BMP581, ReadSlaveAddressShiftedSentFirst );
    RUN_TEST_CASE( BMP581, ReadRegisterAddressSentSecond );
    RUN_TEST_CASE( BMP581, ReadReceivesOnlySpecifiedNumOfBytes );
    RUN_TEST_CASE( BMP581, WriteSlaveAddressShiftedSentFirst );
    RUN_TEST_CASE( BMP581, WriteRegisterAddressSentSecond );
    RUN_TEST_CASE( BMP581, WriteActualDataSentThird );
}
