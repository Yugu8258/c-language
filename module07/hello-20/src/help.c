#include <stdio.h>

// 通过extern关键字声明对外部文件的全局变量的访问
extern int g_static_var;

void try_access_g(void)
{
    g_static_var += 10;

    printf("Inside helper.c try_access_g: %d\n", g_static_var);
}

