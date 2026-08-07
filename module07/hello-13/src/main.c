#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// 斐波那契数列
uint32_t fibonacci_iterative(uint32_t n);

int main(void)
{
    uint32_t number = 10;

    printf("%" PRIu32 " 项: %" PRIu32 "\n", number, fibonacci_iterative(number));

    return 0;
}

uint32_t fibonacci_iterative(uint32_t n)
{
    if (n <= 1) { return n; }

    uint32_t fib_n_minus_1 = 0;
    uint32_t fib_n_minus_2 = 1;

    uint32_t fib_n = 0;

    for (uint32_t i = 2; i <= n; ++i)
    {
        fib_n = fib_n_minus_1 + fib_n_minus_2;
        fib_n_minus_1 = fib_n_minus_2;
        fib_n_minus_2 = fib_n;
    }

    return fib_n;
}

