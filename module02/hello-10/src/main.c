#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int8_t myInt8 = 127;
    printf("myInt8 : %dd\n", myInt8);
    printf("Size of int8_t: %zu byte(s)\n", sizeof(myInt8));

    uint8_t myUInt8 = 255;
    printf("myUInt8 : %du\n", myUInt8);
    printf("Size of uint8_t: %zu byte(s)\n", sizeof(myUInt8));

    int16_t myInt16 = 32767;
    printf("myInt16 : %hd\n", myInt16);
    printf("Size of int16_t: %zu byte(s)\n", sizeof(myInt16));

    uint16_t myUInt16 = 25535;
    printf("myUInt16 : %hu\n", myUInt16);
    printf("Size of uint16_t: %zu byte(s)\n", sizeof(myUInt16));

    int32_t myInt32 = 2147483647;
    printf("myInt32 : %d\n", myInt32);
    printf("Size of int32_t: %zu byte(s)\n", sizeof(myInt32));

    uint32_t myUInt32 = 4294967295U;
    printf("myUInt32 : %u\n", myUInt32);
    printf("Size of uint32_t: %zu byte(s)\n", sizeof(myUInt32));

    int64_t myInt64 = 9223372036854775807LL;
    printf("myInt64 : %ld\n", myInt64);
    printf("Size of int64_t: %zu byte(s)\n", sizeof(myInt64));

    uint64_t myUInt64 = 18446744073709551615ULL;
    printf("myUInt64: %lu\n", myUInt64);
    printf("Size of uint64_t: %zu byte(s)\n", sizeof(myUInt64));

    return 0;
}

