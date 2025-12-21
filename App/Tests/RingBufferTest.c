#include <stdio.h>
#undef NULL
#include "RingBuffer.h"

void TC_test_empty()
{
    struct RingBuffer ringBuff = {0};
    uint8_t buffer[15] = {0};
    ringBuff.buffer = (uint8_t*)&buffer;
    ringBuff.size = 15;

    printf("Pushing data into buffer...\n");
    for (uint8_t i = 0; i < 15; ++i)
    {
        Push(&ringBuff, i+1);
        if (BUFF_FULL == BuffCapacity(&ringBuff))
            printf("[%d] Buffer filled as expected...\n", ringBuff.head);
    }

    for (uint8_t i = 0; i < 15; ++i)
        printf("Data: %d\n", ringBuff.buffer[i]);

    printf("Popping data from buffer...\n");
    for (uint8_t i = 0; i < 15; ++i)
    {
        Pop(&ringBuff);
        if (BUFF_EMPTY == BuffCapacity(&ringBuff))
            printf("[%d] Buffer empty as expected...\n", ringBuff.tail);
    }
}

void TC_test_full()
{
    struct RingBuffer ringBuff = {0};
    uint8_t buffer[15] = {0};
    ringBuff.buffer = (uint8_t*)&buffer;
    ringBuff.size = 15;

    printf("Pushing data into buffer...\n");
    for (uint8_t i = 0; i < 15; ++i)
    {
        Push(&ringBuff, i+1);
        if (BUFF_FULL == BuffCapacity(&ringBuff))
            printf("[%d] Buffer filled as expected...\n", ringBuff.head);
    }

    for (uint8_t i = 0; i < 15; ++i)
        printf("Data: %d\n", ringBuff.buffer[i]);

    printf("Pushing data into buffer...\n");
    for (uint8_t i = 0; i < 50; ++i)
    {
        Push(&ringBuff, i+1);
        if (BUFF_FULL == BuffCapacity(&ringBuff))
            printf("[%d] Buffer filled as expected...\n", ringBuff.head);
    }

    for (uint8_t i = 0; i < 15; ++i)
        printf("Data: %d\n", ringBuff.buffer[i]);
}

void TC_stream()
{
    uint8_t logChar = 'a';
    struct RingBuffer ringBuff = {0};
    uint8_t buffer[15] = {0};

    ringBuff.buffer = (uint8_t*)&buffer;
    ringBuff.size = 15;

    while (1)
    {
        Push(&ringBuff, logChar++);
        Push(&ringBuff, logChar);
        if (logChar - 97 > 25)
        {
            logChar = 'a';
            printf("\n");
        }

        printf("%c", Pop(&ringBuff));
    }
}

int main()
{
    //TC_Push();
    //TC_Pop();
    //TC_stream();
    TC_test_full();
    TC_test_empty(); 


    return 0;
}

