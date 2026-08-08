#include <stdio.h>
#include <inttypes.h>

void add_ten_by_value(int32_t *value);

int main(void)
{
    // 函数的值传递(Pass by Value)

    // 地址传递 (Pass by Reference)

    int32_t my_value = 5;
    printf("原本的值: %" PRId32 "\n", my_value);

    // 指针作为函数的参数
    add_ten_by_value(&my_value);

    printf("已经调用add_ten_by_value之后的值: %" PRId32 "\n", my_value);

    return 0;
}

void add_ten_by_value(int32_t *value)
{
    value += 10;
}

