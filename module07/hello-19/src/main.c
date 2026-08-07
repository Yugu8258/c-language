#include <stdio.h>

void increment_counter(void);

int main(void)
{
    // 静态变量(static variable)

    for (int i = 0; i < 3; i++)
    {
        increment_counter();
    }

    return 0;
}

void increment_counter(void)
{
    // 静态局部变量
    static int counter = 0;

    // 静态局部变量在函数内部声明, 并且程序的期间只初始化一次.
    // 即使函数执行结束, 它的值也不会消失, 而是保持到下次函数的调用.
    // 跨函数调用保持保持着状态和计数.

    counter++;

    printf("Counter: %d\n", counter);
}

