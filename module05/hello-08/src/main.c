#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t sum = 0;
    int32_t number;

    puts("请输入一系列正整数来计算他们的和.");
    puts("可以输入负数, 但它们不会被加入到总和之中.");
    puts("输入0以结束输入并且显示出总和.");

    while (1)
    {
        puts("请输入一个数字:");
        scanf("%" PRIu32, &number);

        // break 结束当前循环
        if (number == 0) { break; }

        // continue 跳过本次循环的剩余部分, 进入下一次循环
        if (number < 0) { continue; }

        sum += number;
    }

    printf("所求的和为: %" PRIu32 "\n", sum);

    return 0;
}

