#include <stdio.h>
#include <string.h>

int main(void)
{
    // 但凡只要是涉及到修改字符串都会考虑安全问题
    // Windows -> _s

    // strcmp -> 比较两个字符是否相等
    // strncmp -> 比较两个字符前n个字符是否相等

    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";
    const char *str3 = "Hello, Guys!";

    if (strcmp(str1, str2) == 0)
    {
        printf("str1 and str2 are equal!\n");
    }
    else
    {
        printf("str1 and str2 are not equal!\n");
    }

    if (strcmp(str1, str3) == 0)
    {
        printf("str1 and str3 are equal!\n");
    }
    else
    {
        printf("str1 and str3 are not equal!\n");
    }

    if (strncmp(str1, str2, 7) == 0)
    {
        printf("str1 and str3 are equal!\n");
    }
    else
    {
        printf("str1 and str3 are not equal!\n");
    }

    return 0;
}

