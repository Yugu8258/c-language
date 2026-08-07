#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// 全局变量, 全局作用域 (global scope)
int32_t g_global_var = 10;

void demo_function(void);

int main(void)
{
    // 作用域 Scope

    // 一个函数内 
    // 一个文件内
    // 整个程序内(配置文件)

    // 一个函数内的变量有效范围: 局部作用域 Local Scope
    // 一个函数有效内的范围变量, 或者局部作用内的变量, 局部变量

    demo_function();

    // 尝试访问local_val将导致编译错误, 因为它的作用域仅限与demo_function内
    // printf("In main, Local var = %" PRId32 "\n", local_val);
    printf("In main, Global var = %" PRId32 "\n", g_global_var);

    return 0;
}

void demo_function(void)
{
    // 局部变量, 局部作用域
    int32_t local_val = 5;

    printf("Inside demo function, Local var = %" PRId32 "\n", local_val);

    printf("Inside demo function, Global var = %" PRId32 "\n", g_global_var);
}

