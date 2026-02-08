#include <stdio.h>
#include <assert.h>
#include <string.h>
#undef NULL

#include "Logger.h"

typedef void (*func_ptr)(void);

void appending_to_empty_buffer_should_succeed()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = 'a';

    char ret = append_to_string((uint8_t*)&source, newChar);

    assert(ret == 0);
    assert(strcmp(source, "a") == 0);
}

void appending_to_full_buffer_should_fail()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t expected[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = 'b';

    (void)memset((void*)&source, 'a', sizeof(source) - 1);
    (void)memset((void*)&expected, 'a', sizeof(source) - 1);

    char ret = append_to_string((uint8_t*)&source, newChar);

    assert(ret == 1);
    assert(strcmp(source, expected) == 0);
}

void appending_null_source_should_fail()
{
    uint8_t* source = NULL;
    uint8_t newChar = 'b';

    char ret = append_to_string(source, newChar);

    assert(ret == 1);
}

void appending_special_character_should_succeed()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t expected[MSG_BUFF_MAX_SIZE] = {0};
    uint8_t newChar = '(';
    const uint8_t charOffset = 2;

    (void)memset((void*)&source, 'a', sizeof(source) - charOffset);
    (void)memset((void*)&expected, 'a', sizeof(expected) - charOffset);

    expected[MSG_BUFF_MAX_SIZE - 2] = newChar; 

    char ret = append_to_string((uint8_t*)&source, newChar);

    assert(ret == 0);
    assert(strcmp(source, expected) == 0);
}

void append()
{
    uint8_t source[MSG_BUFF_MAX_SIZE] = "This is a test message";
    uint8_t newChar = '3';

    char ret = append_to_string(source, newChar);

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

void format_specifier_returns_true()
{
    uint8_t ret = is_format_specifier("%");

    assert(ret == 1);
}

void non_format_specifier_returns_false()
{
    uint8_t ret = is_format_specifier("d");

    assert(ret == 0);
}

void next_char_null_termination_returns_true()
{
    uint8_t buff[3] = {0};
    uint8_t ret = next_char_is_null_termination((const char*)&buff[0]);

    assert(ret == 1);
}

void next_char_not_null_termination_returns_false()
{
    uint8_t buff[3] = "ab";
    uint8_t ret = next_char_is_null_termination((const char*)&buff[0]);

    assert(ret == 0);
}

void valid_custom_log_string_with_single_int_at_the_end()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "This is a test value: %d";

    LOG((const uint8_t*)&string, 1);
}

void valid_custom_log_string_with_single_int_in_the_middle()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "Test value: %d in the middle";

    LOG((const uint8_t*)&string, 1);
    printf("%s\n", ringBuffer.buffer->buffer);
}

void valid_custom_log_string_with_double_int_at_the_end()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "This is a test value: %d";

    LOG((const uint8_t*)&string, 10);
    printf("%s\n", ringBuffer.buffer->buffer);
}

void valid_custom_log_stirng_with_double_int_in_the_middle()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "Test value: %d in the middle";

    LOG((const uint8_t*)&string, 10);
    printf("%s\n", ringBuffer.buffer->buffer);
}

void custom_log_with_single_argument()
{
    ringBuffer.ResetBuffer();

    uint8_t string[] = "This is a test log";

    LOG((const uint8_t*)&string);
    printf("%s\n", ringBuffer.buffer->buffer);
}

/* Possible to consider benchmarking each function */
void run(func_ptr function)
{
    function();
}

int main()
{
    func_ptr functions[] =
    {
        &appending_to_empty_buffer_should_succeed,
        &appending_to_full_buffer_should_fail,
        &appending_null_source_should_fail,
        &appending_special_character_should_succeed,
        &append,

        &format_specifier_returns_true,
        &non_format_specifier_returns_false,
        &next_char_null_termination_returns_true,
        &next_char_not_null_termination_returns_false,

        &valid_custom_log_string_with_single_int_at_the_end,
        &valid_custom_log_string_with_single_int_in_the_middle,
        &valid_custom_log_string_with_double_int_at_the_end,
        &valid_custom_log_stirng_with_double_int_in_the_middle,

        &custom_log_with_single_argument
    };

    int count = sizeof(functions)/sizeof(functions[0]);

    for (int i = 0; i < count; ++i)
        run(functions[i]);

    return 0;
}
