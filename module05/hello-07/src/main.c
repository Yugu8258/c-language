#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    uint32_t secret_num, guess;

    // 生成随机数
    srand(time(NULL));
    // 生成1-100的随机数
    secret_num = rand() % 100 + 1;

    puts("猜猜我想的是哪一个数(1-100)?");
    printf("随机数: %-2" PRIu32 "\n", secret_num);

    uint32_t ret;

    do
    {
        puts("请输入你的猜测:");

        ret = scanf("%" PRIu32, &guess);
        // 读取失败, 清空缓冲区垃圾字符
        if (ret != 1)
        {
            // 清理所有无效字符
            while (getchar() != '\n');
            puts("非法输入! 请输入正整数!");
            continue;
        }

        if (guess < secret_num)
        {
            puts("太小了, 再试试看!");
        }
        else if (guess > secret_num)
        {
            puts("太大了, 再试试看!");
        }
    } while (guess != secret_num);

    printf("恭喜你, 猜对了! 答案就是 %-2" PRIu32 "\n", secret_num);

    return 0;
}

