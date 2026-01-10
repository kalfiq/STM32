#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

#include "converter.h"

#define INT_CHAR_MAX_COUNT 12

void SingleDigitPositiveIntToStringConversionSuccessful()
{
    int testValue = 3;
    char stringValue[INT_CHAR_MAX_COUNT] = {0};

    int ret = int_to_str(testValue, (char*)&stringValue);

    assert(ret == 0);
    assert(strcmp(stringValue, "3") == 0);
}

void SingleDigitNegativeIntToStringConversionSuccessful()
{
    int testValue = -3;
    char stringValue[INT_CHAR_MAX_COUNT] = {0};

    int ret = int_to_str(testValue, (char*)&stringValue);

    assert(ret == 0);
    assert(strcmp(stringValue, "-3") == 0);
}

void MaxDigitPositiveIntToStringConversion()
{
    int testValue = INT_MAX;
    char stringValue[INT_CHAR_MAX_COUNT] = {0};

    int ret = int_to_str(testValue, (char*)&stringValue);

    assert(ret == 0);
    assert(strcmp(stringValue, "2147483647") == 0);
}

void MaxDigitNegativeIntToStringConversion()
{
    int testValue = INT_MIN;
    char stringValue[INT_CHAR_MAX_COUNT] = {0};

    int ret = int_to_str(testValue, (char*)&stringValue);

    assert(ret == 0);
    assert(strcmp(stringValue, "-2147483648") == 0);
}

void CharBufferSizeOneFailsConversion()
{
    int testValue = -3;
    char stringValue[1] = {0};

    int ret = int_to_str(testValue, (char*)&stringValue);

    assert(ret == -1);
}

/*******************************************************
 * Compilation should fail due to -Wconversion error
 ********************************************************/
#if 0
void OvershootDigitStringConversion()
{
    long testValue = LONG_MAX;
    char stringValue[INT_CHAR_MAX_COUNT] = {0};

    int ret = IntToStr(testValue, (char*)&stringValue);

    assert(ret == 0);
}
#endif

int main()
{
    SingleDigitPositiveIntToStringConversionSuccessful();
    SingleDigitNegativeIntToStringConversionSuccessful();

    MaxDigitPositiveIntToStringConversion();
    MaxDigitNegativeIntToStringConversion();

    return 0;
}
