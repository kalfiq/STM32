#include "RingBuffer.h"

uint8_t testBuffer[BUFF_SIZE] = {0};

struct RingBuffer ring_bufff = {
    .buffer = testBuffer,
    .size = BUFF_SIZE,
    .head = 0,
    .tail = 0
};

IRingBuffer ringBuffer = {
    .Push = &PushTest,
    .pop = &PopTest,
    .ResetBuffer = &ResetBuffer,
    .buffer = &ringBufff
};

void reset_buffer() {
    for (int i = 0; i < BUFF_SIZE; ++i)
        ring_bufff.buffer[i] = '\0';

    ring_bufff.head = 0;
    ring_bufff.tail = 0;
}

void push_test(uint8_t* data) {
    if (BUFF_FULL == buff_capacity((const struct RingBuffer*)&ring_bufff))
        return;

    while (*data) {
        ring_bufff.buffer[ring_bufff.head] = *data;
        ring_bufff.head++;

        if (ring_bufff.head == BUFF_SIZE)
            ring_bufff.head = 0;

        data++;
    }
}

uint8_t pop_test() {
    const uint8_t data = ring_bufff.buffer[ring_bufff.tail];
    ring_bufff.tail++;

    if (ring_bufff.tail == BUFF_SIZE)
        ring_bufff.tail = 0;

    return data;
}

void push(struct RingBuffer* ring_buff, uint8_t data) {
    if (NULL == ring_buff)
        return;

    if (BUFF_FULL == buff_capacity(ring_buff))
        return;

    ring_buff->buffer[ring_buff->head] = data;
    ring_buff->head++;

    if (ring_buff->head == BUFF_SIZE)
        ring_buff->head = 0;
}

uint8_t pop(struct RingBuffer* ring_buff) {
    const uint8_t data = ring_buff->buffer[ring_buff->tail];
    ring_buff->tail++;

    if (ring_buff->tail == BUFF_SIZE)
        ring_buff->tail = 0;

    return data;
}

Capacity buff_capacity(const struct RingBuffer* ring_buff) {
    if (NULL == ring_buff)
        return ERROR;

    if (ring_buff->head == ring_buff->tail)
        return BUFF_EMPTY;

    uint8_t head_ref = ring_buff->head+1;

    if (head_ref == BUFF_SIZE)
        head_ref = 0;

    if (head_ref == ring_buff->tail)
        return BUFF_FULL;

    return BUFF_OK;
}

