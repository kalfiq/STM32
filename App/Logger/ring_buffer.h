#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define BUFF_SIZE 128 

#define NULL      ((void*)0)

typedef unsigned char uint8_t;

struct RingBuffer
{
    uint8_t* buffer;
    uint8_t size;
    uint8_t head;
    uint8_t tail;
};

typedef enum
{
    ERROR = 0,
    BUFF_FULL,
    BUFF_EMPTY,
    BUFF_OK
} Capacity;

void push(struct RingBuffer* ringBuff, uint8_t data);
uint8_t pop(struct RingBuffer* ringBuff);
Capacity buff_capacity(const struct RingBuffer* ringBuff);

void PushTest(uint8_t* data);
uint8_t PopTest();
void reset_buffer();

/* Testing some interfaces */
typedef void (*IPush)(struct RingBuffer*, uint8_t);
typedef uint8_t (*IPop)(struct RingBuffer*);

typedef void (*TestPush)(uint8_t*);
typedef uint8_t (*TestPop)(void);
typedef void (*IResetBuffer)(void);

typedef struct
{
    TestPush push;
    TestPop pop;
    IResetBuffer ResetBuffer;

    struct RingBuffer* buffer;
} IRingBuffer;

extern IRingBuffer ringBuffer;

#endif
