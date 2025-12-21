set pagination off

file build/firmware.elf

target remote localhost:3333

layout src
layout reg
load
step
