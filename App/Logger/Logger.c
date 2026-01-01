#include "Logger.h"

char AppendToString(uint8_t* source, uint8_t newChar) {
    if (NULL == source)
        return 1;

    uint8_t counter = 0;
    while (*source++)
        counter++;

    /* Save one byte for a carriage return and the null-termination character */
    if (counter >= MSG_BUFF_MAX_SIZE - 1)
        return 1;

    *(source - 1) = newChar;
    *source = '\0';

    return 0;
}

/* Doesn't the whole ring buffer just disappear after returning? */
void PushRingBuffer(const uint8_t* msg) {
    struct RingBuffer ringBuff = {0};
    uint8_t buffer[15] = {0};

    ringBuff.buffer = (uint8_t*)&buffer;

    /* Consider decoupling this for portability */
    while (*msg)
        Push(&ringBuff, *msg++);
}

uint8_t IsFormatSpecifier(const uint8_t* format) {
    return ('%' == *format);
}

uint8_t NextCharIsNullTermination(const uint8_t* format) {
    return ('\0' == *(format + 1));
}

// TODO: Is there a way to optimize this using some assembly magic?
void InitializeBuffer(uint8_t* buffer, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i)
        *(buffer + i) = '\0';
}

void CustomLog(const uint8_t* function, const uint8_t* format, ...) {
    va_list args;
    uint8_t msg[BUFF_SIZE + NUM_BUFF_MAX_SIZE];
    uint8_t numBuff[NUM_BUFF_MAX_SIZE];
    uint8_t* numBuffPtr = (uint8_t*)&numBuff;

    InitializeBuffer((uint8_t*)&msg, sizeof(msg));
    InitializeBuffer((uint8_t*)&msg, BUFF_SIZE + NUM_BUFF_MAX_SIZE);
    InitializeBuffer((uint8_t*)&numBuff, NUM_BUFF_MAX_SIZE);

    /* Are the function names a waste of bytes? */
    while (*function)
        AppendToString(msg, *function++);

    AppendToString(msg, ':');
    AppendToString(msg, ' ');

    va_start(args, format);

    while (*format) {
        if ((!IsFormatSpecifier(format)) || (NextCharIsNullTermination(format))) {
            AppendToString(msg, *format);
            format++;
            continue;
        }

        format++;
        switch (*format) {
            case 'd': {
                int value = va_arg(args, int);
                IntToStr(value, numBuffPtr);
                format++;

                break;
            }

            default:
                break;
        }

        while (*numBuffPtr)
            AppendToString(msg, *numBuffPtr++);
    }

    ringBuffer.Push(msg);

    va_end(args);
}
