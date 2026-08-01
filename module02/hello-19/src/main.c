#include <stdio.h>

int main(void)
{
    // 四舍五入
    // IEEE 754
    // 最近偶数舍入 round to nearest, ties to even
    // 银行家舍入

    float number = 3.15f;
    printf("1-> %.2f\n", number); // 3.2

    number = 3.25f;
    printf("2-> %.2f\n", number); // 3.2

    // 如果尾数的整数部分是奇数, 向上舍入, 使得变为偶数
    // 如果尾数的整数部分是偶数, 保持不变, 因为它已经是偶数

    return 0;
}

