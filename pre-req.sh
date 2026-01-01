#!/usr/bin/sh

# Script only supports Arch Linux distros for now

function prepare_openocd() {
    sudo pacman -S make libtool pkg-config jimtcl --needed
    sudo pacman -S autoconf automake texinfo libusb --needed
}

function prepare_generic() {
    sudo pacman -S git cmake --needed
}
