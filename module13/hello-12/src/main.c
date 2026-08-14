#include <stdio.h>
#include <stdlib.h>

// 如何声明一个指针指向函数呢?
// 返回类型 (*指针变量名) (参数类型);

int (*my_function_pointer)(int, int);
// my_function_pointer -> int f(int number1, int number2);

int add(int num1, int num2);

int main(void)
{
    // 函数 (Function pointer)
    // 指针(指向): 变量, 数组, 字符串, 结构体, 指针, 函数

    // 指针指向函数
    // 回调函数

    // 指向函数
    my_function_pointer = add;

    // 通过指针调用函数

    int result = my_function_pointer(2, 3);

    printf("result : %d\n", result);

    // 函数指针的用途: 实现回调函数
    // 回调函数允许你将一个函数作为参数传递给另一个函数, 这样, 当特定的事件发生时候, 可以调用传递的参数
    // 事件驱动编程

    return EXIT_SUCCESS;
}

int add(int num1, int num2)
{
    return num1 + num2;
}

