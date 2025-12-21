#include "Converter.h"

int IntToStr(int N, unsigned char* str)
{
    unsigned char i = 0;
    unsigned char isNegative = (N < 0);
    unsigned char overflowed = 0;

    if (-N == N)
    {
        N += 1;
        overflowed = 1;
    }

    if (N < 0)
        N = -N;

    // TODO: See if the computation part can be optimized
    while (N > 0)
    {
        // Value range: 0 to 9 - safe to typecast to char
        str[i++] = (unsigned char)(N % 10) + '0';
      	N /= 10;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        unsigned char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }

    if (overflowed)
        str[i - 1] += 1;

    return 0;
}

