#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 数组的定义
    // 初始化
    uint32_t number[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 下标 index
    // 打印数组
    for (uint8_t index = 0; index < 10; index++)
    {
        printf("%" PRIu32 " ", number[index]);
    }
    printf("\n");

    // 修改
    number[3] = 400;

    for (uint8_t index = 0; index < 10; index++)
    {
        printf("%" PRIu32 " ", number[index]);
    }
    printf("\n");

    return 0;
}

