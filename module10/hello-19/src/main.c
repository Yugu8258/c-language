#include <stdio.h>

int main(void)
{
    char str[] = "Hello";

    // 指向一个字节数组(字符串)
    char *ptr = str;

    ptr[0] = 'h';

    printf("%s\n", str);

    // 字符串常量
    const char *p = "hello";
    
    // p[0] = 'H';

    // printf("%c\n", *p);

    return 0;
}

