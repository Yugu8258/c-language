#include <stdio.h>

int main(void)
{
    printf("Hello, Struct!\n");

    // 结构体 (Structures)
    // 数据类型
    
    // 说白了, 我们想要定义什么类型?

    // 案例: 定义一个表示日期的结构体 Date
    // 其中, 整个结构体包含了三个int类型的成员
    struct Date {
        int day;
        int month;
        int year;
    };

    struct Date today = { 12, 2, 2024 };

    return 0;
}

