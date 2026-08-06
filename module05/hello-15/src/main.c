#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>

// 判断是否为素数
bool is_prime(uint32_t n);

int main(void)
{
    /**
     * 输入一个数, 判断是否为素数
     */

    char buf[64];
    uint32_t num;

    puts("请输入一个正整数, 判断是否为素数:");
    if (fgets(buf, sizeof(buf), stdin) == NULL)
    {
        fprintf(stderr, "读取输入失败!\n");
        return 1;
    }

    // 去掉换行符
    buf[strcspn(buf, "\n")] = '\0';

    int ret = sscanf(buf, "%" SCNu32, &num);
    if (ret != 1)
    {
        fprintf(stderr, "输入不合法, 请输入正整数!\n");
        return 1;
    }

    if (is_prime(num))
    {
        printf("%" PRIu32 " 是素数\n", num);
    }
    else {
        printf("%" PRIu32 " 不是素数\n", num);
    }

    return 0;
}

bool is_prime(uint32_t n)
{
    if (n <= 1) { return false; }
    if (n == 2) { return true; }

    if (n % 2 == 0) { return false; }

    // 只检查奇数, 循环到sqrt(n)
    uint32_t limit = (uint32_t)sqrt(n);
    for (uint32_t i = 3; i <= limit; i += 2)
    {
        if (n % i == 0) { return false; }
    }

    return true;
}

