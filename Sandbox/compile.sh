#!/usr/bin/sh

mkdir -p obj build_logs

arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -std=c11 -g -O0 -c main.c -o obj/main.o

arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -std=c11 -g -O0 -c assembly_startup.s -o obj/assembly_startup.o
arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -std=c11 -g -O0 -c c_startup.c -o obj/c_startup.o

arm-none-eabi-gcc -nostdlib -T linker.ld -Wl,-Map=build_logs/assembly_method.map obj/main.o obj/assembly_startup.o -o assembly_method.elf
arm-none-eabi-gcc -nostdlib -T linker.ld -Wl,-Map=build_logs/c_method.map obj/main.o obj/c_startup.o -o c_method.elf

arm-none-eabi-objdump -D c_method.elf > build_logs/c_dump.txt
arm-none-eabi-objdump -D assembly_method.elf > build_logs/assembly_dump.txt