cmake_minimum_required(VERSION 3.21)

project(Project
    VERSION 1.0
    LANGUAGES C ASM
)

add_subdirectory(App)
add_subdirectory(Platform)

set(PROGRAMMER /usr/bin/openocd)
set(PROGRAMMER_FLAGS -f ${CMAKE_CURRENT_LIST_DIR}/openocd.cfg)

add_custom_target(flash
    COMMAND ${PROGRAMMER} ${PROGRAMMER_FLAGS} -c "program ${CMAKE_CURRENT_LIST_DIR}/cmake_build/test.elf verify reset exit"
    DEPENDS test.elf
    VERBATIM
)
