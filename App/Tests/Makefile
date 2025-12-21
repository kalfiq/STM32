# Toolchain
CC      = gcc
CFLAGS  = -Werror=conversion
LDFLAGS = -I../src/Logger -I../src/Utilities
OBJDUMP = objdump -D

BUILD_DIR  	   = build
OBJECT_DIR 	   = $(BUILD_DIR)/objects
BUILD_LOGS_DIR = $(BUILD_DIR)/logs

SOURCE_DIR = ../src

# Test modules
TEST_MODULES += Utilities
TEST_MODULES += LoggerTest
TEST_MODULES += RingBufferTest

# Configure debug builds
debug: CFLAGS += -O1 -g3
debug: $(TEST_MODULES)

all: $(TEST_MODULES)

LoggerTest: Logger RingBuffer Utilities
	$(CC) $(CFLAGS) -c $@.c $(LDFLAGS) -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

	$(CC) $(CFLAGS) $(OBJECT_DIR)/$@.o $(OBJECT_DIR)/RingBuffer.o $(OBJECT_DIR)/Logger.o $(OBJECT_DIR)/Converter.o -o $(BUILD_DIR)/$@

Logger: directories
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../src/Logger/$@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

RingBufferTest: RingBuffer
	$(CC) $(CFLAGS) $(LDFLAGS) -c $@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

	$(CC) $(CFLAGS) $(OBJECT_DIR)/$@.o $(OBJECT_DIR)/RingBuffer.o -o $(BUILD_DIR)/$@

RingBuffer: directories
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../src/Logger/$@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

Utilities: ConverterTest

ConverterTest: Converter
	$(CC) $(CFLAGS) $(LDFLAGS) -c $@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

	$(CC) $(CFLAGS) $(OBJECT_DIR)/$@.o $(OBJECT_DIR)/Converter.o -o $(BUILD_DIR)/$@

Converter: directories
	$(CC) $(CFLAGS) $(LDFLAGS) -c ../src/Utilities/$@.c -o $(OBJECT_DIR)/$@.o
	$(OBJDUMP) $(OBJECT_DIR)/$@.o > $(BUILD_LOGS_DIR)/$@.txt

directories:
	mkdir -p $(BUILD_DIR) $(OBJECT_DIR) $(BUILD_LOGS_DIR)

clean:
	rm -rf $(BUILD_DIR)
