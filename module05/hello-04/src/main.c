#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#define BUF_LEN 64

int main(void)
{
    /**
     * 求和案例
     * 用户从终端输入一系列数字, 用回车隔开, 直到用户输入一个单个字符q作为结束, 然后把所有的数相加, 最终计算结果.
     */

    int32_t sum = 0; // 初始化数字和为0

    char buf[BUF_LEN];

    puts("请输入一系列数字, 用回车隔开, 我们将计算他们的和, 输入0结束.");

    while (true)
    {
        // 读取一整行输入
        if (fgets(buf, sizeof(buf), stdin) == NULL) { break; }

        // 清除末尾换行符, fgets会带回\n
        buf[strcspn(buf, "\n")] = '\0';

        // 判断输入是否为q退出
        if (strcmp(buf, "q") == 0 || strcmp(buf, "Q") == 0) { break; }

        int32_t number;

        // 尝试转换成数字
        if (sscanf(buf, "%" PRId32, &number) == 1) 
        { 
            sum += number; 
        }
        else
        {
            puts("输入无效! 请输入整数 或者 q 退出.");
        }
    }

    printf("所求的和为: %" PRId32 "\n", sum);

    return 0;
}

