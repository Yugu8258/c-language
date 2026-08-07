#include <stdio.h>
#include <inttypes.h>

// 全局变量, 全局作用域, 生命周期从程序开始到程序结束
// 内存泄露, 访问已经被销毁的变量(悬挂引用), 过度消耗资源
int32_t g_global_var = 10;

void demo_function(void);

int main(void)
{
    // 生命周期(Lifetime): 它描述了从变量被创建(或者是初始化)到变量被销毁(或被回收)的整个过程.
    
    demo_function();

    // 此处尝试访问local_var将导致编译错误, 因为其生命周期已经结束
    printf("In main, Global var = %" PRId32 "\n", g_global_var);

    // 全局变量的生命周期将在程序执行结束时结束

    return 0;
}

void demo_function(void)
{
    // 局部变量, 局部作用域, 生命周期从这里开始
    int32_t local_var = 5;
    printf("Inside demo function, Local var = %" PRId32 "\n", local_var);
    // 局部变量的生命周期在函数返回时结束
}

