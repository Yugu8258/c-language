#include <stdio.h>
#include <stdbool.h>

// 函数的声明
// 函数的参数
void greet(int age, bool gender);

// 函数的返回值 void -> 无返回值
int add(int number_a, int number_b);

int main(void)
{
    // 函数的调用
    // 传递参数
    // 实际参数
    greet(18, 1);
    greet(20, 0);

    // 函数的复用
    printf("sum = %d\n", add(1, 2));

    return 0;
}

// 函数的定义
void greet(int age, bool gender)
{
    // 形式参数
    printf("您的年龄： %d, 您的性别是: %s\n", age, gender ? "男" : "女");
}

int add(int number_a, int number_b)
{
    return number_a + number_b;
}

