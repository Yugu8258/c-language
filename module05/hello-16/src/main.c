#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    /**
     * 九九乘法口诀表
     */

    puts("乘法口诀表:");

    uint32_t number = 9;
    uint32_t sum = 0;

    for (uint32_t i = 1; i <= number; i++)
    {
        for (uint32_t j = 1; j <= i; j++)
        {
            sum = i * j;
            printf("%" PRIu32 " x %" PRIu32 " = %-2" PRIu32 "  ", j, i, sum);
        }
        printf("\n");
    }

    return 0;
}

