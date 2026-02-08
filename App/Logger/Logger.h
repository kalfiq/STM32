#ifndef LOGGER_H
#define LOGGER_H

/* Enforce compiler flags here in case they are missed in Makefile */
#pragma GCC diagnostic error "-Wint-conversion"

#include "RingBuffer.h"
#include "Converter.h"

#include <stdarg.h>
#include <stdlib.h>

#define NUM_BUFF_MAX_SIZE 12 
#define MSG_BUFF_MAX_SIZE (BUFF_SIZE + NUM_BUFF_MAX_SIZE)

#define LOG(...) custom_log(__FUNCTION__, __VA_ARGS__)

void custom_log(const uint8_t* function, const uint8_t* format, ...);
char append_to_string(uint8_t* source, uint8_t newChar);

uint8_t is_format_specifier(const uint8_t* format);
uint8_t next_char_is_null_termination(const uint8_t* format);

#endif
