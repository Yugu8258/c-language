// #define NDEBUG 禁用所有断言

#include <stdio.h>
#include <assert.h>

int main(void)
{
    // 断言 assert

    // 用于开发阶段的错误捕获
    // 发布之后, 所有的断言全都不奏效了
    // 不适用于处理运行时候的错误情况

    int a = 5;

    // 断言 a == 5?
    assert(a == 5); // 这个断言会通过, 因为a确实等于5, 这样程序往下走

    a = 3;

    assert(a == 5);

    puts("Hello");
 
    return 0;
}

