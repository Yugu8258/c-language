#include <stdio.h>

void print_line(void);

void print_i(void);

int main(void)
{
    // Functions 功能块
    
    // 模块化

    // 功能抽离, 达到复用性

    print_line();

    print_i();

    return 0;
}

void print_line(void)
{
    printf("-----------\n");
}

void print_i(void)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d", i);
    }
    printf("\n");
}
