#include <stdio.h>

#define SIZE 10

int main(void)
{
    // 数组的长度 size

    // const int SIZE = 10;

    // 定义数组, 初始化数组的时候, 长度都不可以为变量
    int number[SIZE] = { 0 };

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\n");

    // number[0];
    // 数组下标为0的元素, index -> 下标

    return 0;
}

