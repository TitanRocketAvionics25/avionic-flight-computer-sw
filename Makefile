sources = src/drivers/bmi088 src/drivers/bmp581 src/drivers/sx127x

hw_sources = src/ src/startup src/sysclk src/i2cconf src/spiconf

WFLAGS = -Wall

build = build

UTFS_MODULE_DIRS = test/test-utils/fakes test/test-utils/spys $(sources)
UTFS_TEST_DIR = test
UTFS_BUILD_DIR = $(build)
UTFS_WFLAGS = $(WFLAGS)

CLISTM_SRC_DIRS = $(sources) $(hw_sources)
CLISTM_BUILD_DIR = $(build)
CLISTM_MODEL_NUM = STM32F411xE
CLISTM_HAL_MODULES = gpio dma i2c spi
CLISTM_STARTUP_FILE = src/startup/startup.c
CLISTM_WFLAGS = $(WFLAGS)


.PHONY: clean
clean:
	rm -r build


include tools/unity-test-fixture-setup/unity_test_fixture_setup.mk
include tools/command-line-stm32f4/command_line_stm32f4.mk

