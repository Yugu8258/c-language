#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // 指针与数组的关系

    // 数组名作为指针的使用

    int32_t arrays[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    // 直接把数组名字给指针, 就相当于把数组的首地址(index = 0)给它
    int32_t *ptr = arrays; // &arrays[0];

    // size_t 是一个无符号的整数类型
    // 它是专门用来表示大小, 长度和索引
    // 提高程序在不同平台, 跨平台的可移植性和安全性
    size_t array_size = sizeof(arrays) / sizeof(arrays[0]);

    // 输出原数组
    printf("原始数组: \n");

    printf("arrays[] = { ");
    for (size_t i = 0; i < array_size; ++i)
    {
        printf("%" PRId32 " ", arrays[i]);
    }
    printf(" }\n\n");

    // 通过指针增加数组的每个元素的值
    for (size_t i = 0; i < array_size; ++i)
    {
        // 直接通过指针修改数组中的值
        *(ptr + i) += 5;
    }

    printf("修改后的数组: \n");

    printf("arrays[] = { ");
    for (size_t i = 0; i < array_size; ++i)
    {
        printf("%" PRId32 " ", arrays[i]);
    }
    printf(" }\n\n");

    return 0;
}

