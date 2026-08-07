#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t factorial(uint32_t n);

int main(void)
{
    // 递归 阶乘
    
    uint32_t number = 5;

    printf("%" PRIu32 "的阶乘是: %" PRIu32 "\n", number, factorial(number));

    return 0;
}

uint32_t factorial(uint32_t n)
{
    if (n == 0) { return 1; }
    else { return n * factorial(n - 1); } // 尾递归
}

