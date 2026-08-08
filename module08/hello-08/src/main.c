#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // 指针的算术运算

    // uint32_t
    uint32_t numbers[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    
    uint32_t *ptr = numbers; // &numbers[0]

    // 数组在内存中是连续的
    // 所以只需要一个首地址就能找到整个数组

    // 计算数组的大小
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    // sizeof(numbers) 计算整个数组所占用的内存大小, 单位是字节
    // 返回一个整个数组的空间所占的大小
    // sizeof(number[0]) 计算第一个元素的大小, 单位字节

    printf("numbers[]的大小size : %" PRIuMAX "\n\n", size);

    printf("原始数组数据:\nnumbers[] = { ");
    for (size_t i = 0; i < size; ++i)
    {
        printf("%" PRIu32 " ", numbers[i]);
    }
    printf("}\n\n");

    // 使用指针加法移动指针
    printf("使用指针加法访问第5个元素: \n");
    ptr += 4; // 4*sizeof(uint32_t) 个字节

    printf("numbers[ptr += 4] : %" PRIu32 "\n\n", *ptr);

    // 使用指针减法回到第一个元素
    ptr -= 4;

    printf("使用指针减法回到第1个元素: \n");
    printf("回到第一个元素numbers[ptr -= 4] : %" PRIu32 "\n\n", *ptr);

    // 使用指针减法, 计算距离
    uint32_t *start_ptr = &numbers[0];
    uint32_t *end_ptr = &numbers[size - 1];

    // %td 有符号, 指针相减结果 -> inttypes 中可以使用 PRIdMAX
    printf("数组首尾之间的距离是: %td\n\n", end_ptr - start_ptr);

    // 指针之间的比较
    puts("比较指针指向的元素:");
    if (start_ptr < end_ptr)
    {
        puts("start_ptr 指向的元素在 end_ptr 所指向的元素之前!\n");
    }

    // 使用指针遍历数组
    puts("使用指针遍历数组:");
    printf("*p 使用外部指针遍历: { ");
    for (uint32_t *p = start_ptr; p <= end_ptr; p++)
    {
        printf("%" PRIu32 " ", *p);
    }
    printf("}\n\n");

    // 使用指针减法逐个访问数组中的每个元素的反向顺序(反向遍历)
    printf("使用指针减法逐个访问数组中的每个元素的反向顺序\n*p = { ");
    for (uint32_t *p = end_ptr; p >= start_ptr; --p)
    {
        printf("%" PRIu32 " ", *p);
    }
    printf("}\n\n");

    // 使用指针加减访问特定元素
    puts("使用指针加减访问特定元素:");

    uint32_t offset = 3;

    printf("第4个元素(使用加法) : %" PRIu32 "\n", *(start_ptr + offset));

    printf("第2个元素(使用减法) : %" PRIu32 "\n\n", *(start_ptr + offset - 2));

    // 比较两个指针
    uint32_t middle_ptr = &numbers[size / 2]; // 指向数组中间的元素

    printf("比较两个指针指向的位置:\n");

    if (start_ptr < middle_ptr)
    {
        puts("start_ptr 指向的元素在 middle_ptr 所指向的元素之前!\n");
    }

    if (end_prt > middle_ptr)
    {
        puts("end_ptr 指向的元素在 middle_ptr 所指向的元素之后!\n");
    }

    return 0;
}

