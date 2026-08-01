#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 数据对象
    // 左值
    // 右值
    // 运算符

    uint32_t apple_box = 5;

    uint32_t orange_box = 10;

    printf("苹果盒子里有 %" PRIu32 " 个苹果\n", apple_box);

    printf("橘子盒子里有 %" PRIu32 " 个橘子\n", orange_box);

    uint32_t total_fruit = apple_box + orange_box;

    printf("盒子里总共有 %" PRIu32 " 个水果\n", total_fruit);

    return 0;
}

