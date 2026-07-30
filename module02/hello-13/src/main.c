#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // int_leastN_t
    // 定义的时候, 保证至少有N位, 可能更多, 适用于需要保证最小存储容量的可移植代码

    // int_fast64_t
    // 定义的时候, 保证至少有N位, 但是选择运算最快的类型, 适用于需要性能敏感的场景

    // 标准整数类型 -> 固定宽度整数类型
    // 固定的位数, 不可以越界, 适用与需要精确数据大小的场景

    // 玩家分数 (初始分数)
    int_least32_t playerScore = 5000;
    printf("paluerScoer : %" PRIdLEAST32 "\n", playerScore);

    // 初始化像素值
    int_fast32_t pixelValue = 128;
    printf("pixelValue : %" PRIdFAST32 "\n", pixelValue);

    return 0;
}


