#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER( SX127X )
{
    RUN_TEST_CASE( SX127X, WriteRWBitHigh );
    RUN_TEST_CASE( SX127X, Write7BitAddressInFirstByte );
    RUN_TEST_CASE( SX127X, WriteDataInSecondByte );
    RUN_TEST_CASE( SX127X, WriteMultipleBytesSent );
    RUN_TEST_CASE( SX127X, ReadRWBitLow );
    RUN_TEST_CASE( SX127X, Read7BitAddressInFirstByte );
}
