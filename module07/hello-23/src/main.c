#include <stdio.h>

void demo(void);

int main(void)
{
    demo();

    return 0;
}

// 函数的作用域 (Function Scope)
void demo(void)
{
    // 作用域
    // 链接性 (Linkage)

    // 块作用域(Block Scope)
    int a = 10; // 'a'具有块作用域, 仅在demo()中可见.

    if (a > 5)
    {
        int b = a + 5; // 'b' 也具有块作用域, 仅仅是在if语句中可见
    }
}

