#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>

int main(void)
{
    // gets() -> 废弃
    // puts()

    const char *str = "Hello!";
    puts(str);

    char buf[32];
    char *res = fgets(buf, sizeof(buf), stdin);
    if (res == NULL)
    {
        return 1;
    }

    // remove newline
    char *nl = strchr(buf, '\n');
    if (nl != NULL)
    {
        *nl = '\0';
    }

    printf("input=[%s]\n", buf);

    return 0;
}

