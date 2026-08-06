#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

int main(void)
{
    /**
     *  写一个计算求整数和的案例
     *
     *  用户从终端输入一系列数字, 用回车隔开, 直到用户输入一个单个0作为结束, 然后把所有的数相加, 最终计算结果
     */

    uint32_t sum = 0; // 初始化数字和是0

    uint32_t number = 1; // 每一次用户输入的数字

    int ret = 0;

    puts("请输入一系列数字, 用回车隔开, 我们将计算他们的和, 输入0结束.");

    while (true)
    {
        ret = scanf("%" PRIu32, &number);
        if (ret != 1)
        {
            // 清除所有无效字符
            while(getchar() != '\n')
            {
                puts("非法输入! 请输入正整数!");
                continue;
            }
        }

        if (number == 0) { break; }

        sum += number;
    }

    printf("所求的和为: %" PRIu32 "\n", sum);

    return 0;
}

