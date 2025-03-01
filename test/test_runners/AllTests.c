#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP( FakeRead );
    RUN_TEST_GROUP( WriteSpy );
    RUN_TEST_GROUP( BMI088   );
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
