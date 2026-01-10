#include <stdio.h>
#include <assert.h>
#include <string.h>
#undef NULL
#include "RingBuffer.h"

void PushingEmptyBufferShouldBeOK()
{
    ringBuffer.ResetBuffer();

    uint8_t buffer[BUFF_SIZE] = "This is a test buffer";
    ringBuffer.push((uint8_t*)&buffer);

    assert(strcmp(ringBuffer.buffer->buffer, (uint8_t*)&buffer[0]) == 0);
}

void PushingFullBufferShouldFail()
{
    ringBuffer.ResetBuffer();

    uint8_t buffer[BUFF_SIZE] = "This is a test buffer";
    uint8_t testBuffer[BUFF_SIZE] = {0};

    for (uint8_t i = 0; i < BUFF_SIZE - 1; ++i)
    {
        testBuffer[i] = 'a';
        ringBuffer.push((uint8_t*)&testBuffer[i]);
    }

    ringBuffer.buffer->buffer = testBuffer;
    ringBuffer.push((uint8_t*)&buffer);

    assert(strcmp(ringBuffer.buffer->buffer, testBuffer) == 0);
    assert(ringBuffer.buffer->head == BUFF_SIZE - 1);
}

void StreamingBuffer()
{
    ringBuffer.ResetBuffer();

    uint8_t buffer[BUFF_SIZE] = "This is a test buffer";
    
    for (int i = 0; i < 2 * BUFF_SIZE; ++i)
    {
        ringBuffer.push((uint8_t*)&buffer);
        ringBuffer.push((uint8_t*)&buffer);

        ringBuffer.pop();
    }

    printf("%s\n", ringBuffer.buffer->buffer);
}

int main()
{
    PushingEmptyBufferShouldBeOK();
    PushingFullBufferShouldFail();

    StreamingBuffer();

    return 0;
}

