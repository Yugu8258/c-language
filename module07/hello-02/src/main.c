#include <stdio.h>

// 函数的声明
void print_hello(void);

int main(void)
{
    // 函数的声明与定义
    // 先声明 -> 后定义

    // 函数的调用
    print_hello();

    return 0;
}

// 函数的定义
void print_hello(void)
{
    printf("Hello, World!\n");
}

