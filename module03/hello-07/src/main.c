#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 按位移位运算符
    // << >>

    // 0001 0110
    uint8_t num = 22;
    printf("Original number : %" PRIu8 " (binary: 00010110)\n", num);

    // 左移 2 位
    uint8_t left_shifted = num << 2;
    // 0101 1000
    printf("Left shifted by 2 : %" PRIu8 " (binary: 01011000)\n", left_shifted);

    // 右移
    uint8_t right_shifted = num >> 2;
    printf("Right shifted by 2: %" PRIu32 " (binary: 00000101)\n", right_shifted);

    return 0;
}

