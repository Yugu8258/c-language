#define _POSIX_C_SOURCE 200808L

#include <stdio.h>
#include <string.h>

int main(void)
{
    // strncat
    // 最多追加多少个字符

    char buf[16] = "hello";
    const char *append1 = "_world";
    const char *append2 = "_verylongstring";

    printf("buf initial: \"%s\"\n", buf);

    // 安全追加
    size_t remain = sizeof(buf) - strlen(buf) - 1;
    strncat(buf, append1, remain);

    printf("after append1: \"%s\"\n", buf);

    // 再次追加
    remain = sizeof(buf) - strlen(buf) - 1;
    strncat(buf, append2, remain);

    printf("after append2: \"%s\"\n", buf);

    return 0;
}

