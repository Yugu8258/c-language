#include <stdio.h>

void greet_a();
void greet_b(void);

int main(void)
{
    int a = 10;

    // 调用函数的时候, 传递一个整数参数
    // 它不会去检查
    greet_a();

    greet_b();

    return 0;
}

void greet_a()
{
    printf("Hello\n");
}

void greet_b(void)
{
    printf("Hello\n");
}

