#include "../src/drivers/w25q64jvssiq/w25q64jvssiq.h"

#include "unity.h"
#include "unity_fixture.h"

#include <stdint.h>

#include "WriteSpy.h"
#include "FakeRead.h"

TEST_GROUP( w25q64jvssiq );

TEST (ww25q64jvssiq) {
}


TEST_SETUP ( w25q64jvssiq ){
    WriteSpy_Create(10);
    FakeRead_Create(10, 10);
}

Test_Tear_Down ( w25q64jvssiq ) {
    WriteSpy_Destoy();
    KaeRead_Destory();
}
