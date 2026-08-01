#include <stdio.h>

int main(void)
{
    int base_number = 8;
    printf("base_number : %d\n", base_number);

    int add_number = 2;
    int sub_number = 3;
    int mul_number = 4;
    int div_number = 2;
    int mod_number = 5;

    int left_shift_number = 1;
    int right_shift_number = 2;
    int and_number = 0b1010;
    int or_number = 0b0101;
    int xor_number = 0b1111;

    // In-place Modification 原地修改
    // 原地修改, 意味着变量的值将在其原始的存储位置被更新, 而不是在另一个位置简单创建一个新的值做出计算然后在将新的值赋值给原先的值
    // 复合赋值运算符

    // base_number = base_number + add_number;
    base_number += add_number;
    printf("base_number : %d\n", base_number);

    base_number -= sub_number;
    printf("base_number : %d\n", base_number);

    base_number *= mul_number;
    printf("base_number : %d\n", base_number);

    base_number /= div_number;
    printf("base_number : %d\n", base_number);

    base_number %= mod_number;
    printf("base_number : %d\n", base_number);

    base_number <<= left_shift_number;
    printf("base_number : %d\n", base_number);

    base_number >>= right_shift_number;
    printf("base_number : %d\n", base_number);

    base_number &= and_number;
    printf("base_number : %d\n", base_number);

    base_number |= or_number;
    printf("base_number : %d\n", base_number);

    base_number ^= xor_number;
    printf("base_number : %d\n", base_number);

    return 0;
}

