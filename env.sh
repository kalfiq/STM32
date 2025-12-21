#!/usr/bin/sh

PROJECT_ROOT=$(realpath .)
BUILD_DIR=${PROJECT_ROOT}/cmake_build
DEBUG_DIR=${PROJECT_ROOT}/Debug
RELEASE_DIR=${PROJECT_ROOT}/Release

function build_release()
{
    cmake -S ${PROJECT_ROOT} -B ${RELEASE_DIR} -D CMAKE_BUILD_TYPE=Release -D VARIANT=stm32f722
    cmake --build ${RELEASE_DIR}
}

function build_debug()
{
    cmake -S ${PROJECT_ROOT} -B ${DEBUG_DIR} -DCMAKE_BUILD_TYPE=Debug -D VARIANT=stm32f722
    cmake --build ${DEBUG_DIR}
}

function build_all()
{
    build_debug
    build_release
}

function flash()
{
    cmake --build ${BUILD_DIR} --target flash
}

function start_openocd()
{
    openocd -f ${PROJECT_ROOT}/openocd.cfg -s "/usr/share/openocd/scripts" 
}
