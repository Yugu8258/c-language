#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t apples = 10;
    uint32_t oranges = 5;

    // 算术运算
    uint32_t totalFruits = apples + oranges; // 加法
    uint32_t remainingApples = apples - 2; // 减法
    uint32_t appleBoxes = apples * 10; // 乘法
    uint32_t fruitsPerFriend = totalFruits / 2; // 除法
    uint32_t remainingFruits = totalFruits % 3; // 取模

    // 输出结果
    printf("总共有%" PRIu32 "个水果\n", totalFruits);
    printf("假如我们吃掉两个苹果后, 就会只剩下%" PRIu32 "个苹果\n", remainingApples);
    printf("10个盒子可以装%" PRIu32 "个苹果\n", appleBoxes);
    printf("假设现在有15个水果, 那么平均每个小朋友可以分到%" PRIu32 "个水果\n", fruitsPerFriend);
    printf("假设现在15个水果平均分给3个人, 那么分完后还剩%" PRIu32 "个水果\n", remainingFruits);

    return 0;
}

