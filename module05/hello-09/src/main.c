#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    /**
     * 假如我们要处理一系列的数字, 我们想要忽略所有的负数和大于100的数, 只能处理0-100之间的数, 对于每一个有效数字, 如果是偶数, 打印一条消息并且告知它是偶数, 如果是奇数, 打印一条语句并且告知它是奇数. 用户输入-1结束此程序.
     */

    int32_t number;

    puts("请输入数字(0-100), 输入-1后结束程序.");

    while (1)
    {
        puts("请输入一个数字:");
        scanf("%" PRId32, &number);

        // 检查结束条件
        if (number == -1) { break; }

        // 跳过所有的负数和大于100的整数
        // 跳过本次循环的剩余部分
        if (number < 0 || number > 100) { continue; } 

        // 处理有效数字
        if (number % 2 == 0)
        {
            printf("%" PRId32 "是偶数.\n", number);
        }
        else
        {
            printf("%" PRId32 "是奇数.\n", number);
        }
    }

    puts("程序结束!");

    return 0;
}

