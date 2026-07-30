#include <stdio.h>

int main(void)
{
    // 输入输出
    // 人和计算机交互的过程

    // Windows
    // scanf_s()

    // scanf()
    // 不安全, 企业不建议用
    // scanf_s
    // _s safe

    printf("Please input a number:\n");

    int number;

    // 校验成功读取变量数量, 防止非法输入卡死逻辑
    if (scanf("%d", &number) != 1)
    {
        fprintf(stderr, "非法数字输入!\n");
        // 清空输入缓冲区垃圾字符, 避免死循环
        while(getchar() != '\n');

        return 1;
    }

    printf("Your number is : %d\n", number);

    return 0;
}

