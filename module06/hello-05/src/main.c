#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define SIZE 5

int main(void)
{
    // 初始化数组
    uint32_t numbers[SIZE] = { 100, 200, 300, 400, 500 };

    for (uint32_t i = 0; i < SIZE; i++)
    {
        // numbers[0]
        printf("%" PRIu32 " ", numbers[i]);
    }
    printf("\n");

    // 常见错误
    // 错误1. 越界访问
    // printf("%" PRIu32 "\n", number[5]);

    // 错误2. 未初始化数组
    // uint32_t uninit_array[5];
    // printf("%" PRIu32 "\n", uninit_array[1]);

    // 错误3. 数组大小错误 SIZE > 0 正整数
    // uint32_t wrong_size_arr[-1];

    // 常见警告
    // 警告1. 部分初始化
    /*
        uint32_t part_init_arr[SIZE] = { 1, 2 };
        for (uint32_t i = 0; i < SIZE; i++)
        {
            printf("%" PRIu32 " ", part_init_arr[i]);
        }
        printf("\n");
    */

    // 提示: 总是初始化数组
    uint32_t part_init_arr[SIZE] = { 0 };

    return 0;
}

