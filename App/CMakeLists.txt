set(OUTPUT "test.elf")

set(CMAKE_C_FLAGS "-O0 -g3")

add_executable(${OUTPUT})

target_sources(${OUTPUT}
    PRIVATE
        Logger/Logger.c
        Utilities/Converter.c
        Logger/RingBuffer.c
        Main.c
)

target_include_directories(${OUTPUT}
    PRIVATE
        Logger
        Utilities
)

target_link_libraries(${OUTPUT}
    PRIVATE
        stm32f722
)
