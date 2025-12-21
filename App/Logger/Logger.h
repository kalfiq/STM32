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

#define LOG(...) CustomLog(__FUNCTION__, __VA_ARGS__)

void CustomLog(const uint8_t* function, const uint8_t* format, ...);
char AppendToString(uint8_t* source, uint8_t newChar);

uint8_t IsFormatSpecifier(const uint8_t* format);
uint8_t NextCharIsNullTermination(const uint8_t* format);

#endif
