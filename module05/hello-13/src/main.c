#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define BUF_LEN 64

int main(void)
{
    /**
     * 倒数N个数
     */

    uint32_t start_number; // 初始化

    puts("请输入一个正整数, 我们将从该数开始倒数到1");

    char buf[BUF_LEN];

    // 读取一整行
    if (fgets(buf, sizeof(buf), stdin) == NULL)
    {
        fprintf(stderr, "读取输入失败!\n");
        return 1;
    }

    // 去掉fgets带回的换行符
    buf[strcspn(buf, "\n")] = '\0';

    // 在内存中解析字符串
    uint32_t ret = sscanf(buf, "%" SCNu32, &start_number);
    if (ret != 1)
    {
        fprintf(stderr, "输入不合法, 请输入正整数!\n");
        return 1;
    }

    if (start_number < 1)
    {
        fprintf(stderr, "nubmer必须大于等于1\n");
        return 1;
    }

    puts("倒数开始");

    for (uint32_t index = start_number; index > 0; index--)
    {
        sleep(1);
        printf("%" PRIu32 "\n", index);
    }

    puts("倒数结束");

    return 0;
}

