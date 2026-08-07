#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t factorial(uint32_t n, uint32_t acc);

int main(void)
{
    uint32_t number = 5;

    printf("%" PRIu32 "的阶乘是: %" PRIu32 "\n", number, factorial(number, 1));

    return 0;
}

uint32_t factorial(uint32_t n, uint32_t acc)
{
    if (n == 0)
    {
        return acc;
    }
    else
    {
        return factorial(n - 1, n * acc);
    }
}

