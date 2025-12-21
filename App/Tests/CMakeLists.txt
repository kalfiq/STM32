cmake_minimum_required(VERSION 3.21)
project(UnitTests
    VERSION 1.0
)

set(SOURCE_PATH ${CMAKE_CURRENT_LIST_DIR}/..)
set(CMAKE_C_FLAGS "-O0 -g3")

add_executable(LoggerTest
    LoggerTest.c
    ${SOURCE_PATH}/Logger/Logger.c
    ${SOURCE_PATH}/Logger/RingBuffer.c
    ${SOURCE_PATH}/Utilities/Converter.c
)

add_executable(ConverterTest
    ConverterTest.c
    ${SOURCE_PATH}/Utilities/Converter.c
)

add_executable(RingBufferTest
    RingBufferTest.c
    ${SOURCE_PATH}/Logger/RingBuffer.c
)

include_directories(
    ${SOURCE_PATH}/Logger
    ${SOURCE_PATH}/Utilities
)
