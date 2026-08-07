#include <stdio.h>

#define GRADE_COUNT 11

char get_grade(int score);

int main(void)
{
    // 表驱动法
    // 使用数据结构(array, hash)
    // 使用数组
    // 来代替复杂的逻辑语句

    // 核型思想: 许多程序行为可以通过查表来确定, 而不是通过复杂的条件语句

    // 1. 识别: 确定程序中可以用查表替代的逻辑部分.
    // 2. 设计: 创建包含所有可能输入和对应输出的表(数组或者Hash).
    // 3. 实现: 编写代码, 使用输入作为索引或者键来查找表中的相应输出.
    // 4. 优化: 根据需要, 调整表的结构以提高效率或者可读性.

    printf("grades 91 ---> %c\n", get_grade(91));

    return 0; 
}

char get_grade(int score)
{
    // 分数范围和等级

    // 等级内容对应
    const char grades[GRADE_COUNT] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A' };

    if (score < 0 || score > 100)
    {
        return 'X';
    }

    return grades[score / 10];
}

