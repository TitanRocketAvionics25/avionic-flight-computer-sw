#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER( BMI088 )
{
    RUN_TEST_CASE( BMI088, RequireFullInterface );
    RUN_TEST_CASE( BMI088, ReadSlaveAddressShiftedSentFirst );
    RUN_TEST_CASE( BMI088, ReadRegisterAddressSentSecond );
    RUN_TEST_CASE( BMI088, ReadReceivesOnlySpecifiedNumOfBytes );
}
