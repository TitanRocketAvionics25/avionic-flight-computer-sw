sources = 

hw_sources = src/ src/startup

build = build

#UTFS_MODULE_DIRS = test/fakes test/spys $(sources)
UTFS_MODULE_DIRS = $(sources)
UTFS_TEST_DIR = test
UTFS_BUILD_DIR = $(build)

CLISTM_SRC_DIRS = $(sources) $(hw_sources)
CLISTM_BUILD_DIR = $(build)
CLISTM_MODEL_NUM = STM32F411xE
CLISTM_HAL_MODULES = gpio
CLISTM_STARTUP_FILE = src/startup/startup.c


.PHONY: clean
clean:
	rm -r build


include tools/unity-test-fixture-setup/unity_test_fixture_setup.mk
include tools/command-line-stm32f4/command_line_stm32f4.mk

