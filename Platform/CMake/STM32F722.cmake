set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(ARM_TOOLCHAIN_PATH "${THIRDPARTY_ROOT}/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi/bin")

set(CMAKE_C_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-g++)

# -fno-builtin flag is required to prevent compiler optimization by calling memset function
# ref: https://github.com/riscv-collab/riscv-gnu-toolchain/issues/758
set(MCU_FLAGS "-mcpu=cortex-m7 -mthumb -Wall -nostdlib -fno-builtin")

string(APPEND CMAKE_C_FLAGS ${MCU_FLAGS})

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    string(APPEND CMAKE_C_FLAGS " -g3 -O0")
endif ()

add_compile_definitions(STM32F722)
