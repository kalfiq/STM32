cmake_minimum_required(VERSION 3.21)
project(UnitTests
    VERSION 1.0
)

set(SOURCE_PATH ${CMAKE_CURRENT_LIST_DIR}/..)
set(CMAKE_C_FLAGS "-O0 -g3")

add_executable(logger_test
    logger_test.c
    ${SOURCE_PATH}/logger/logger.c
    ${SOURCE_PATH}/logger/ring_buffer.c
    ${SOURCE_PATH}/utilities/converter.c
)

add_executable(converter_test
    converter_test.c
    ${SOURCE_PATH}/utilities/converter.c
)

add_executable(ring_buffer_test
    ring_buffer_test.c
    ${SOURCE_PATH}/logger/ring_buffer.c
)

include_directories(
    ${SOURCE_PATH}/logger
    ${SOURCE_PATH}/utilities
)
