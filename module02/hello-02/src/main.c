#include <stdio.h>

int main(void)
{
    // 变量 Variable
    // 可以变化的量


    // int -> integer
    // = 赋值

    // 初始化定义
    // 类型 标识符 = 值;
    // 将 100 这个值赋给 sun_flower 这个变量
    int sun_flower = 100;

    printf("1. 阳光目前的值 : %d\n", sun_flower);

    // 重新赋值
    sun_flower = 200;

    printf("2. 阳光目前的值 : %d\n", sun_flower);

    // 重新赋值
    sun_flower = 550;

    printf("3. 阳光目前的值 : %d\n", sun_flower);

    // 变量的计算
    sun_flower = sun_flower - 100;

    printf("4. 阳光目前的值 : %d\n", sun_flower);

    return 0;
}

