#include <stdio.h>

// 全局变量声明
int global_var = 100;

// 跨越函数边界, 共享数据
// 减少函数的参数, 使用全局变量可以减少需要传递给函数的参数数量, 简化调用

void demonstrate_global_variable(void);

int main(void)
{
    // 程序范围内的可见性
    // 静态存储期
    // 默认初始化
    
    // 线程安全问题: 在多线程环境中, 未枷锁的全局变量可能会导致数据竞争和不一致的问题
    
    demonstrate_global_variable();

    // 在main函数中访问局部变量
    printf("Global variable in main: %d\n", global_var);

    return 0;
}

void demonstrate_global_variable(void)
{
    // 访问全局变量
    printf("Global variable inside function: %d\n", global_var);
}

