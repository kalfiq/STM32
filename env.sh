#!/usr/bin/sh

PROJECT_ROOT=$(realpath .)
BUILD_DIR=${PROJECT_ROOT}/cmake_build

function build_all()
{
    cmake -S ${PROJECT_ROOT} -B ${BUILD_DIR}
    cmake --build ${BUILD_DIR}
}

function flash()
{
    cmake --build ${BUILD_DIR} --target flash
}

function start_openocd()
{
    openocd -f ${PROJECT_ROOT}/openocd.cfg -s "/usr/share/openocd/scripts" 
}
