#include "w25q64jv.h"

#include "unity.h"
#include "unity_fixture.h"

#include <stdint.h>

#include "WriteSpy.h"
#include "FakeRead.h"

TEST_GROUP( W25Q64JV );

TEST_SETUP( W25Q64JV )
{
    WriteSpy_Create(10);
    FakeRead_Create(10, 10);
}

TEST_TEAR_DOWN( W25Q64JV ) 
{
    WriteSpy_Destroy();
    FakeRead_Destroy();
}
