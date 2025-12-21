set(LIBRARY "stm32f722")

add_library(${LIBRARY})

target_sources(${LIBRARY}
    PRIVATE
        STM32F722/Startup/Startup.s
)

include(
    CMake/STM32F722.cmake
)

target_link_options(${LIBRARY}
    PRIVATE
        "-T${CMAKE_CURRENT_LIST_DIR}/Platform/Linker/linker.ld"
)


