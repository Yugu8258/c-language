#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    /**
     * 用户输入一个正整数, 计算阶乘, 默认还是从1开始
     */

    uint32_t number;        // INPUT
    uint32_t factorial = 1; // 阶乘初始化1

    puts("请输入一个正整数, 我们将计算阶乘:");
    scanf("%" SCNu32, &number);

    for (uint32_t index = 1; index <= number; index++)
    {
        factorial *= index;
    }

    printf("%" PRIu32 " 的阶乘为: %" PRIu32 "\n", number, factorial);

    return 0;
}

