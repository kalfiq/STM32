#include "RingBuffer.h"

uint8_t testBuffer[BUFF_SIZE] = {0};

struct RingBuffer ringBufff = {
    .buffer = testBuffer,
    .size = BUFF_SIZE,
    .head = 0,
    .tail = 0
};

IRingBuffer ringBuffer = {
    .Push = &PushTest,
    .Pop = &PopTest,
    .ResetBuffer = &ResetBuffer,
    .buffer = &ringBufff
};

void ResetBuffer() {
    for (int i = 0; i < BUFF_SIZE; ++i)
        ringBufff.buffer[i] = '\0';

    ringBufff.head = 0;
    ringBufff.tail = 0;
}

void PushTest(uint8_t* data) {
    if (BUFF_FULL == BuffCapacity((const struct RingBuffer*)&ringBufff))
        return;

    while (*data) {
        ringBufff.buffer[ringBufff.head] = *data;
        ringBufff.head++;

        if (ringBufff.head == BUFF_SIZE)
            ringBufff.head = 0;

        data++;
    }
}

uint8_t PopTest() {
    const uint8_t data = ringBufff.buffer[ringBufff.tail];
    ringBufff.tail++;

    if (ringBufff.tail == BUFF_SIZE)
        ringBufff.tail = 0;

    return data;
}

void Push(struct RingBuffer* ringBuff, uint8_t data) {
    if (NULL == ringBuff)
        return;

    if (BUFF_FULL == BuffCapacity(ringBuff))
        return;

    ringBuff->buffer[ringBuff->head] = data;
    ringBuff->head++;

    if (ringBuff->head == BUFF_SIZE)
        ringBuff->head = 0;
}

uint8_t Pop(struct RingBuffer* ringBuff) {
    const uint8_t data = ringBuff->buffer[ringBuff->tail];
    ringBuff->tail++;

    if (ringBuff->tail == BUFF_SIZE)
        ringBuff->tail = 0;

    return data;
}

Capacity BuffCapacity(const struct RingBuffer* ringBuff) {
    if (NULL == ringBuff)
        return ERROR;

    if (ringBuff->head == ringBuff->tail)
        return BUFF_EMPTY;

    uint8_t head_ref = ringBuff->head+1;

    if (head_ref == BUFF_SIZE)
        head_ref = 0;

    if (head_ref == ringBuff->tail)
        return BUFF_FULL;

    return BUFF_OK;
}

