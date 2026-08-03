#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int32_t value = 5;
    int32_t result;

    // 后缀递增 (先赋值, 后增加)
    result = value++; // 使用value的当前值(5) -> 然后value变成6 

    printf("After postfix increment, result = %" PRId32 ", value = %" PRId32 "\n", result, value);

    value = 5;
    // 前缀递增 (先增加, 在赋值)
    result = ++value;
    // resutl = value + 1;

    printf("After postfix increment, result = %" PRId32 ", value = %" PRId32 "\n", result, value);

    value = 5;
    // 后缀递减 (先赋值, 后减少)
    result = value--;
    printf("After postfix increment, result = %" PRId32 ", value = %" PRId32 "\n", result, value);

    value = 5;
    // 前缀递减 (先减少, 在赋值)
    result = --value;
    printf("After postfix increment, result = %" PRId32 ", value = %" PRId32 "\n", result, value);

    return 0;
}

