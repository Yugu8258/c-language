#include <stdio.h>

// 静态全局变量, 仅在文本中可见
static int g_static_var = 10;

int main(void)
{
    printf("%d\n", g_static_var);

    return 0;
}

