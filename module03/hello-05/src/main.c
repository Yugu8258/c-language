#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int32_t number_1 = 10;
    int32_t number_2 = -number_1; // 一元运算符号
    
    int32_t total_number = number_1 - number_2; // 二元运算符

    printf("number_1 : %" PRId32 "\n", number_1);
    printf("number_2 : %" PRId32 "\n", number_2);

    printf("total_number : %" PRId32 "\n", total_number);

    return 0;
}

