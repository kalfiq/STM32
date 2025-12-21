#include <stdio.h>
#include <assert.h>
#include <string.h>
#undef NULL

#include "Logger.h"

typedef void (*funcPtr)(void);

void AppendingToEmptyBufferShouldSucceed()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = 'a';

    char ret = AppendToString((uint8_t*)&source, newChar);

    assert(ret == 0);
    assert(strcmp(source, "a") == 0);
}

void AppendingToFullBufferShouldFail()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t expected[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = 'b';

    (void)memset((void*)&source, 'a', sizeof(source) - 1);
    (void)memset((void*)&expected, 'a', sizeof(source) - 1);

    char ret = AppendToString((uint8_t*)&source, newChar);

    assert(ret == 1);
    assert(strcmp(source, expected) == 0);
}

void AppendingToNullSourceShouldFail()
{
    uint8_t* source = NULL;
    uint8_t newChar = 'b';

    char ret = AppendToString(source, newChar);

    assert(ret == 1);
}

void AppendingSpecialCharacterShouldSucceed()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t expected[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = '(';
    const uint8_t charOffset = 2;

    (void)memset((void*)&source, 'a', sizeof(source) - charOffset);
    (void)memset((void*)&expected, 'a', sizeof(expected) - charOffset);

    expected[MSG_BUFF_MAX_SIZE - 2] = newChar; 

    char ret = AppendToString((uint8_t*)&source, newChar);

    assert(ret == 0);
    assert(strcmp(source, expected) == 0);
}

void Append()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = "This is a test message";
    uint8_t newChar = '3';

    char ret = AppendToString(source, newChar);

    assert(ret == 0);
}

#if 0

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
/******************************************************************
 * This causes segmentation fault - so we don't want to allow it
 * Compilation should fail due to -Wint-conversion error
 *******************************************************************/
void PassingArgumentsInTheWrongOrder()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = 'a';

    AppendToString(newChar, (uint8_t*)&source);
}
#pragma GCC diagnostic pop

#endif

void FormatSpecifierReturnsTrue()
{
    uint8_t ret = IsFormatSpecifier("%");

    assert(ret == 1);
}

void NonFormatSpecifierReturnsFalse()
{
    uint8_t ret = IsFormatSpecifier("d");

    assert(ret == 0);
}

void NextCharNullTerminateReturnsTrue()
{
    uint8_t buff[3] = {0};
    uint8_t ret = NextCharIsNullTermination((const char*)&buff[0]);

    assert(ret == 1);
}

void NextCharNotNullTerminateReturnsFalse()
{
    uint8_t buff[3] = "ab";
    uint8_t ret = NextCharIsNullTermination((const char*)&buff[0]);

    assert(ret == 0);
}

void ValidCustomLogStringWithSingleIntAtTheEnd()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "This is a test value: %d";

    LOG((const uint8_t*)&string, 1);
}

void ValidCustomLogStringWithSingleIntInTheMiddle()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "Test value: %d in the middle";

    LOG((const uint8_t*)&string, 1);
    printf("%s\n", ringBuffer.buffer->buffer);
}

void ValidCustomLogStringWithDoubleIntAtTheEnd()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "This is a test value: %d";

    LOG((const uint8_t*)&string, 10);
    printf("%s\n", ringBuffer.buffer->buffer);
}

void ValidCustomLogStringWithDoubleIntInTheMiddle()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "Test value: %d in the middle";

    LOG((const uint8_t*)&string, 10);
    printf("%s\n", ringBuffer.buffer->buffer);
}

void CustomLogWithSingleArgument()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "This is a test log";

    LOG((const uint8_t*)&string);
    printf("%s\n", ringBuffer.buffer->buffer);
}

/* Possible to consider benchmarking each function */
void Run(funcPtr function)
{
    function();
}

int main()
{
    funcPtr functions[] =
    {
        &AppendingToEmptyBufferShouldSucceed,
        &AppendingToFullBufferShouldFail,
        &AppendingToNullSourceShouldFail,
        &AppendingSpecialCharacterShouldSucceed,
        &Append,

        &FormatSpecifierReturnsTrue,
        &NonFormatSpecifierReturnsFalse,
        &NextCharNullTerminateReturnsTrue,
        &NextCharNotNullTerminateReturnsFalse,

        &ValidCustomLogStringWithSingleIntAtTheEnd,
        &ValidCustomLogStringWithSingleIntInTheMiddle,
        &ValidCustomLogStringWithDoubleIntAtTheEnd,
        &ValidCustomLogStringWithDoubleIntInTheMiddle,

        &CustomLogWithSingleArgument
    };

    int count = sizeof(functions)/sizeof(functions[0]);

    for (int i = 0; i < count; ++i)
        Run(functions[i]);

    return 0;
}
