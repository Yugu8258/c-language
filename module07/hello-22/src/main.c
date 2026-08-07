#include <stdio.h>

void demo_reg_var(void);

int main(void)
{
    // 寄存器

    demo_reg_var();

    return 0;
}

void demo_reg_var(void)
{
    // 声明寄存器变量
    // 建议编译器, 尽可能将counter放在寄存器中
    register int counter;

    for (counter = 0; counter < 10; counter++)
    {
        printf("%d ", counter);
    }
    printf("\n");

    // 不能使用&counter获得地址
    // 地址, 指针
}

