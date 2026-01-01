#!/usr/bin/sh

PROJECT_ROOT=$(realpath .)
BUILD_DIR=${PROJECT_ROOT}/cmake_build
DEBUG_DIR=${PROJECT_ROOT}/Debug
RELEASE_DIR=${PROJECT_ROOT}/Release

THIRDPARTY_DIR=${PROJECT_ROOT}/ThirdParty

ARM_TOOLCHAIN="arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz"
ARM_TOOLCHAIN_PATH=${THIRDPARTY_DIR}/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi/bin

OPENOCD_PATH=${THIRDPARTY_DIR}/openocd/src

export PATH=${ARM_TOOLCHAIN_PATH}:${OPENOCD_PATH}:${PATH}

function build_release() {
    cmake -S ${PROJECT_ROOT} -B ${RELEASE_DIR} -D CMAKE_BUILD_TYPE=Release -D VARIANT=stm32f722
    cmake --build ${RELEASE_DIR}
}

function build_debug() {
    cmake -S ${PROJECT_ROOT} -B ${DEBUG_DIR} -D CMAKE_BUILD_TYPE=Debug -D VARIANT=stm32f722
    cmake --build ${DEBUG_DIR}
}

function build_tests() {
    cmake -S ${PROJECT_ROOT}/App/Tests -B ${PROJECT_ROOT}/App/Tests/TestBuild
    cmake --build ${PROJECT_ROOT}/App/Tests/TestBuild
}

function build_all() {
    build_debug
    build_release
    build_tests
}

function flash_debug() {
    cmake --build ${DEBUG_DIR} --target flash
}

function flash_release() {
    cmake --build ${RELEASE_DIR} --target flash
}

function start_openocd() {
    openocd -f ${PROJECT_ROOT}/openocd.cfg -s "${THIRDPARTY_DIR}/openocd/tcl" 
}

function check_toolchains() {
    if [ ! -e ${THIRDPARTY_DIR} ]; then
        mkdir -p ${THIRDPARTY_DIR}
    fi

    # ARM toolchain
    arm-none-eabi-gcc --version > /dev/null 2>&1 
    if [ $? -ne 0 ]; then

        if [ ! -e ${PROJECT_ROOT}/ThirdParty/${ARM_TOOLCHAIN} ]; then
            echo ""
            echo "Downloading ARM toolchain..."
            wget "https://developer.arm.com/-/media/Files/downloads/gnu/15.2.rel1/binrel/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz" -P ${THIRDPARTY_DIR}
        fi

        echo "Extracting ${ARM_TOOLCHAIN}"
        tar -xJf ${THIRDPARTY_DIR}/${ARM_TOOLCHAIN} -C ${THIRDPARTY_DIR}
    fi

    # OpenOCD
    openocd --version > /dev/null 2>&1
    if [ $? -ne 0 ]; then
    
        # Download the git repo
        if [ ! -e ${THIRDPARTY_DIR}/openocd ]; then
            echo ""
            echo "Downloading OpenOCD..."
            git clone "https://github.com/openocd-org/openocd" -b "v0.12.0" ${THIRDPARTY_DIR}/openocd
        fi

        # Download the pre-requisites for building openocd
        source ./pre-req.sh
        prepare_openocd

        cd ${THIRDPARTY_DIR}/openocd
        git merge 400cf213c05d17cede4dca4787a5533959bd2183 # Contains fix for compilation issues

        ./bootstrap
        ./configure
        make

        cd -
    fi
}

check_toolchains
