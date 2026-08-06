#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define BUF_LEN 64

int main(void)
{
    /**
     * 倒数N个数
     *
     * 输入一个正整数, 我们将从这个数开始倒数到1
     */

    uint32_t start_number; // 初始化: 从哪一个数开始

    puts("请输入一个正整数, 我们将从该数开始倒数到1:");

    char buf[BUF_LEN];
    
    // 读取一整行
    if (fgets(buf, sizeof(buf), stdin) == NULL)
    {
        fprintf(stderr, "读取失败!\n");
        return 1;
    }

    // 去掉fgets带回的换行符
    buf[strcspn(buf, "\n")] = '\0';

    // 在内存中解析字符串
    uint8_t ret = sscanf(buf, "%" SCNu32, &start_number);
    if (ret != 1)
    {
        fprintf(stderr, "输入不合法, 请输入正整数!\n");
        return 1;
    }

    if (start_number < 1)
    {
        fprintf(stderr, "N必须大于等于1\n");
        return 1;
    }

    puts("倒数开始");

    for (uint32_t index = start_number; index > 0; index-- )
    {
        printf("index : %" PRIu32 "\n", index);
    }

    puts("倒数结束");

    return 0;
}

