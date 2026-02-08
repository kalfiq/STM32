#include "Logger.h"

char append_to_string(uint8_t* source, uint8_t new_char) {
    if (NULL == source)
        return 1;

    uint8_t counter = 0;
    while (*source++)
        counter++;

    /* Save one byte for a carriage return and the null-termination character */
    if (counter >= MSG_BUFF_MAX_SIZE - 1)
        return 1;

    *(source - 1) = new_char;
    *source = '\0';

    return 0;
}

/* Doesn't the whole ring buffer just disappear after returning? */
void push_ring_buffer(const uint8_t* msg) {
    struct RingBuffer ring_buff = {0};
    uint8_t buffer[15] = {0};

    ring_buff.buffer = (uint8_t*)&buffer;

    /* Consider decoupling this for portability */
    while (*msg)
        Push(&ring_buff, *msg++);
}

uint8_t is_format_specifier(const uint8_t* format) {
    return ('%' == *format);
}

uint8_t next_char_is_null_termination(const uint8_t* format) {
    return ('\0' == *(format + 1));
}

// TODO: Is there a way to optimize this using some assembly magic?
void initialize_buffer(uint8_t* buffer, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i)
        *(buffer + i) = '\0';
}

void custom_log(const uint8_t* function, const uint8_t* format, ...) {
    va_list args;
    uint8_t msg[BUFF_SIZE + NUM_BUFF_MAX_SIZE];
    uint8_t num_buff[NUM_BUFF_MAX_SIZE];
    uint8_t* num_buff_ptr = (uint8_t*)&num_buff;

    initialize_buffer((uint8_t*)&msg, sizeof(msg));
    initialize_buffer((uint8_t*)&msg, BUFF_SIZE + NUM_BUFF_MAX_SIZE);
    initialize_buffer((uint8_t*)&num_buff, NUM_BUFF_MAX_SIZE);

    /* Are the function names a waste of bytes? */
    while (*function)
        append_to_string(msg, *function++);

    append_to_string(msg, ':');
    append_to_string(msg, ' ');

    va_start(args, format);

    while (*format) {
        if ((!is_format_specifier(format)) || (next_char_is_null_termination(format))) {
            append_to_string(msg, *format);
            format++;
            continue;
        }

        format++;
        switch (*format) {
            case 'd': {
                int value = va_arg(args, int);
                int_to_str(value, num_buff_ptr);
                format++;

                break;
            }

            default:
                break;
        }

        while (*num_buff_ptr)
            append_to_string(msg, *num_buff_ptr++);
    }

    ringBuffer.Push(msg);

    va_end(args);
}
