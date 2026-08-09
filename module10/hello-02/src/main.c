#include <stdio.h>
#include <string.h>

#define SIZE 50

int main(void)
{
    const char src[] = "hello";

    char dest[SIZE];

    // strcpy_s -> Windows
    // 实际开发中禁止使用strcpy
    strcpy(dest, src);

    printf("%s\n", dest);

    char dest_a[SIZE];

    // 有长度参数
    strncpy(dest_a, src, SIZE);
    
    printf("%s\n", dest_a);

    // snprintf

    return 0;
}

