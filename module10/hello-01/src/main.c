#include <stdio.h>

int main(void)
{
    // 单个字符
    char c = 't';

    // 很多个字符, 组合在一起
    // 串起来...
    // 字符串 String
    // 文本
    char arr[] = { "Hello" };
    // 'H' 'e' 'l' 'l' '0' '\0'

    char string[5] = "hello";

    printf("%s\n", string);

    char *ptr = "Hello";

    return 0;
}

