#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Type Conversion
    // 类型转换 

    // 显示类型转换 (强制类型转换)
    // 无符号 -> 有符号
    uint32_t uNum = UINT32_MAX;
    int32_t sNum = (int32_t)uNum;

    printf("uint32_t: %u\n", uNum);
    printf("converted to int32_t: %d\n", sNum);

    // 大范围 -> 小范围
    int64_t longNum = 50000LL;
    int16_t shortNum = (int16_t)longNum;

    printf("int64_t: %ld\n", longNum);
    printf("converted to int16_t: %hd\n", shortNum);

    // 小范围转换为大范围 (扩展负数)
    int16_t smallNum = -1;
    uint32_t bigNum = (uint32_t)smallNum;

    printf("int16_t: %hd\n", smallNum);
    printf("converted to uint32_t: %u\n", bigNum);

    // 小范围 -> 大范围
    int16_t smallNum2 = INT16_MAX;
    uint32_t bigNum2 = (uint32_t)smallNum2;

    printf("int16_t: %hd\n", smallNum2);
    printf("converted to uint32_t: %u\n", bigNum2);

    // 大范围 -> 小范围
    int32_t mediumNum = 123;
    int16_t smalleNum = (int16_t)mediumNum;

    printf("int32_t: %d\n", mediumNum);
    printf("converted to int16_t: %hd\n", smalleNum);

    return 0;
}

