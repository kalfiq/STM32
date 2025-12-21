cmake_minimum_required(VERSION 3.21)

project(Project
    VERSION 1.0
    LANGUAGES C ASM
)

set(OUTPUT "firmware.elf")
set(PLATFORM_SOURCES "")
set(APP_SOURCES "")
set(APP_HEADERS "")
set(LINKER_SCRIPT "")
set(PLATFORM_TOOLCHAIN "")

############################################################################################
# Configure the variant handling to get the source files, linkers, and toolchains
############################################################################################
add_subdirectory(App)
add_subdirectory(Platform)

############################################################################################
# Compile and link the variant sources
############################################################################################
add_executable(${OUTPUT}
    ${PLATFORM_SOURCES}
    ${APP_SOURCES}
)

target_link_options(${OUTPUT}
    PRIVATE
        "-T${LINKER_SCRIPT}"
)

target_include_directories(${OUTPUT}
    PRIVATE
        ${APP_HEADERS}
)

include(
    ${PLATFORM_TOOLCHAIN}
)

############################################################################################
# Custom flashing command
############################################################################################
set(PROGRAMMER /usr/bin/openocd)
set(PROGRAMMER_FLAGS -f ${CMAKE_CURRENT_LIST_DIR}/openocd.cfg)

add_custom_target(flash
    COMMAND ${PROGRAMMER} ${PROGRAMMER_FLAGS} -c "program $<TARGET_FILE:firmware.elf> verify reset exit"
    DEPENDS firmware.elf
    VERBATIM
)

