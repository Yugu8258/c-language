#include <stdio.h>

int main(void)
{
    /**
     * 语法:
     * 类型 变量名(标识符) = 值;
     */

    // int integer 整形
    // 定义一个int类型的数据时候, 内存通常开辟一个4bytes空间
    int sun_flower = 100;

    printf("1. sun_flower : %d\n", sun_flower);

    // 重新赋值
    sun_flower = 150;

    printf("2. sun_flower : %d\n", sun_flower);

    return 0;
}

