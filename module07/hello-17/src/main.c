#include <stdio.h>
#include <inttypes.h>

void demonstrate_local_variable(void);

int main(void)
{
    // 局部变量(Local Variables)

    // 作用域限定
    // 自动存储期
    // 初始值为定义

    demonstrate_local_variable();

    // 下面的尝试访问 local_var 将会导致编译错误, 因为它的作用域仅限于 demonstrate_local_variable 函数内
    // printf("Trying to access local_var outside: %" PRId32 "\n", local_var);

    return 0;
}

void demonstrate_local_variable(void)
{
    // 局部变量声明
    int32_t local_var = 100;
    printf("Local variable inside function: %" PRId32 "\n", local_var);
    // local_var 的作用域限于此函数, 生命周期结束于函数返回时
}

