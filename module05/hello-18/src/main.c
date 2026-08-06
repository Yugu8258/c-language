#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    /**
     * 打印简单的三角形
     */

    puts("绘画简单的三角形\n");

    puts("输入要绘制的大小: ");

    uint32_t size;

    scanf("%" SCNu32, &size);

    for (uint32_t i = 0; i < size; i++)
    {
        for (uint32_t j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

