#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t size;
    puts("请输入图案的大小: ");
    scanf("%" SCNu32, &size);

    // 特点: 场合宽都一样
    puts("打印正方形图案:");

    for (uint32_t i = 0; i < size; i++)
    {
        for (uint32_t j = 0; j < size; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

