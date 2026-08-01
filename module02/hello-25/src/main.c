#include <stdio.h>

int main(void)
{
    // 转义序列
    // 回车 换行...

    // 转义字符
    // \

    printf("\a");

    // 清除屏幕
    printf("\033[H\033[2J");

    printf("\n第一行\n\t第二行, 带有缩进\n\t\t第三行, 带有两个缩进\n");

    return 0;
}

