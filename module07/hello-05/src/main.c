#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year);

int main(void)
{
    /**
     * 1. 明确函数的目的, 明确它的功能将帮助你决定那些输入是必须的(形式参数. 模板), 以及如何报告它的工作结果(函数的返回值)
     *
     * 2. 识别所需要的参数
     *
     * 3. 确定函数的输出
     *
     * 4. 使用适当的数据类型
     *
     * 5. 函数的命名清晰, 并且先声明后定义
     */

    int year = 2024;

    printf("%d年%s闰年\n", year, is_leap_year(year) ? "是" : "不是");

    return 0;
}

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

