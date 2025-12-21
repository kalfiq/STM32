set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++)

# -fno-builtin flag is required to prevent compiler optimization by calling memset function
# ref: https://github.com/riscv-collab/riscv-gnu-toolchain/issues/758
set(MCU_FLAGS "-mcpu=cortex-m7 -mthumb -Wall -nostdlib -fno-builtin")

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${MCU_FLAGS})

add_compile_definitions(STM32F722)
