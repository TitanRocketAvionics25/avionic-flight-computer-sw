#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP( FakeRead );
    RUN_TEST_GROUP( WriteSpy );
    RUN_TEST_GROUP( BMI088   );
    RUN_TEST_GROUP( BMP581   );
    RUN_TEST_GROUP( SX127X   );
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
