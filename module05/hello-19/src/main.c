#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    /**
     * 绘制金字塔
     */

    uint32_t levels;

    puts("请输入金字塔的层数: ");
    scanf("%" SCNu32, &levels);

    puts("数字金字塔图案如下: ");

    for (uint32_t i = 1; i <= levels; i++)
    {
        uint32_t spaces = levels - i; // 计算并提前存储每层空格
        // 输出空格
        for (uint32_t j = 0; j < spaces; j++)
        {
            printf("  ");
        }

        for (uint32_t j = 1; j <= i; j++)
        {
            printf("%" PRIu32 " ", j);
        }

        for (uint32_t j = i - 1; j >= 1; j--)
        {
            printf("%" PRIu32 " ", j);
        }

        printf("\n");
    }

    return 0;
}

