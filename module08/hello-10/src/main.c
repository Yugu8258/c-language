#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

int main(void)
{
    int32_t values[] = { 10, 20, 30, 40, 50 };

    int32_t *start_ptr = values;

    size_t values_size = sizeof(values) / sizeof(values[0]);

    int32_t target_value = 30;
    int32_t *target_ptr = NULL;

    size_t index = 0;

    bool found = false;

    for (size_t i = 0; i < values_size; ++i)
    {
        if (*(start_ptr + i) == target_value)
        {
            // 顺手保存目标的地址值
            target_ptr = start_ptr + i;
            // 找到目标的index
            index = i;
            found = true;
            break;
        }
    }

    if (found)
    {
        printf("元素 %" PRId32 " 的INDEX: %" PRIuMAX "\n", target_value, index);
    }
    else
    {
        printf("元素 %" PRId32 " 未找到!\n", target_value);
    }

    return 0;
}

