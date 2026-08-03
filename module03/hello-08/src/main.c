#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num = 25;

    printf("Original number: %" PRIu32 "\n", num);

    // uint32_t result = num * 1024;
    uint32_t result = num << 10; // 左移10位相当于乘以 2^10, 1024

    printf("Result: %" PRIu32 "\n", result);

    return 0;
}

