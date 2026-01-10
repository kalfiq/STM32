#include "converter.h"

int int_to_str(int n, unsigned char* str) {
    unsigned char i = 0;
    unsigned char isNegative = (n < 0);
    unsigned char overflowed = 0;

    if (-n == n) {
        n += 1;
        overflowed = 1;
    }

    if (n < 0)
        n = -n;

    // TODO: See if the computation part can be optimized
    while (n > 0) {
        // Value range: 0 to 9 - safe to typecast to char
        str[i++] = (unsigned char)(n % 10) + '0';
      	n /= 10;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        unsigned char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }

    if (overflowed)
        str[i - 1] += 1;

    return 0;
}
