# Toolchain
CC      = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump -D

CFLAGS  = -mcpu=cortex-m7 -mthumb -Wall -nostdlib

LDFILE  = Platform/STM32F722/Linker/linker.ld
LDFLAGS = -T$(LDFILE)

# Directories
BUILD_DIR    	= build
OBJECT_DIR      = $(BUILD_DIR)/objects
BUILD_LOGS_DIR  = $(BUILD_DIR)/logs
INCLUDES		= -IApp/Logger -IApp/Utilities

# Consolidate build directories for clean creation
BUILD_DIRS += $(BUILD_DIR)
BUILD_DIRS += $(OBJECT_DIR)
BUILD_DIRS += $(BUILD_LOGS_DIR)

# Modules
MODULES += Startup
MODULES += Main
MODULES += Logger
MODULES += Utilities

# Final binary
TARGET = $(BUILD_DIR)/firmware.elf

# Build targets
all: $(TARGET)

flash: $(TARGET)
	openocd -f openocd.cfg -c "program $(TARGET) verify reset exit"

# Configure debug builds
debug: CFLAGS += -O0 -g3
debug: $(TARGET)

# Build the dependencies
$(TARGET): directories $(MODULES) 
	@echo
	@echo "********************"
	@echo "GENERATING BINARY"
	@echo "********************"
	$(CC) $(CFLAGS) $(OBJECT_DIR)/*.o $(LDFLAGS) -o $(TARGET)

Logger: RingBuffer
	@echo
	@echo "*****************"
	@echo "LOGGER"
	@echo "*****************"
	$(CC) $(CFLAGS) -c App/Logger/$@.c $(INCLUDES) -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

RingBuffer:
	$(CC) $(CFLAGS) -c App/Logger/$@.c $(INCLUDES) -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

Main:
	@echo
	@echo "******************"
	@echo "MAIN APP"
	@echo "******************"
	$(CC) $(CFLAGS) -c App/$@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

Startup:
	@echo
	@echo "**********************"
	@echo "BOOTLOADER"
	@echo "**********************"
	$(CC) $(CFLAGS) -c Platform/STM32F722/Startup/$@.s -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

Utilities: Converter

Converter:
	@echo
	@echo "**********************"
	@echo "CONVERTER"
	@echo "**********************"
	$(CC) $(CFLAGS) -c App/Utilities/$@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

directories:
	mkdir -p $(BUILD_DIRS)

clean:
	rm -rf $(BUILD_DIR)
