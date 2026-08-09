#define _POSIX_X_SOURCE 200809L

#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[10];
    const char *long_str = "abcdefghij123456";
    const char *short_str = "hi";

    // 场景1: 原字符串很长, 会截断
    strncpy(buf, long_str, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    printf("long_str copy result: \"%s\"\n", buf);

    // 场景2: 原字符串很短
    strncpy(buf, short_str, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    printf("short_str copy result: \"%s\"\n", buf);

    return 0;
}

