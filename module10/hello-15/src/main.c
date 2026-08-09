#include <stdio.h>
#include <string.h>

int main(void)
{
    // strchr -> 从左向右, 查找字符第一次出现的位置
    // strchr -> 从右向左, 查找字符最后一次出现的位置(reverse-r)

    const char *text = "hello, world";

    // strchr 找第一个'l'
    char *p1 = strchr(text, 'l');
    if (p1 != NULL)
    {
        printf("strchr l: %s\n", p1); // llo, world
    }

    // strrchr 找最后一个 'l'
    char *p2 = strrchr(text, 'l');
    if (p2 != NULL)
    {
        printf("strrchr l: %s\n", p2); // ld
    }

    // 查找 '\0' 合法, 返回字符串末尾的'\0'指针
    char *end = strchr(text, '\0');
    printf("end ptr diff: %td\n", end - text); // 字符串长度

    return 0;
}

