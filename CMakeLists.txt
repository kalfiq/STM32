cmake_minimum_required(VERSION 3.21)

project(Project
    VERSION 1.0
    LANGUAGES C ASM
)

set(PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}")
set(APP_ROOT "${PROJECT_ROOT}/App")
set(PLATFORM_ROOT "${PROJECT_ROOT}/Platform")
set(THIRDPARTY_ROOT "${PROJECT_ROOT}/ThirdParty")

set(OUTPUT "firmware.elf")
set(PLATFORM_SOURCES "")
set(APP_SOURCES "")
set(APP_HEADERS "")
set(PLATFORM_HEADERS "")
set(LINKER_SCRIPT "")
set(PLATFORM_TOOLCHAIN "")

############################################################################################
# Configure the variant handling to get the source files, linkers, and toolchains
############################################################################################
add_subdirectory(app)
add_subdirectory(platform)

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
    ${PLATFORM_HEADERS}
)

include(
    ${PLATFORM_TOOLCHAIN}
)

############################################################################################
# Custom flashing command
############################################################################################
set(PROGRAMMER openocd)

set(PROGRAMMER_FLAGS
    # Set the root path for OpenOCD to traverse
    -s ${THIRDPARTY_ROOT}/openocd/tcl
    -f ${CMAKE_CURRENT_LIST_DIR}/openocd.cfg
)

add_custom_target(flash
    COMMAND ${PROGRAMMER} ${PROGRAMMER_FLAGS} -c "program $<TARGET_FILE:firmware.elf> verify reset exit"
    DEPENDS firmware.elf
    VERBATIM
)

