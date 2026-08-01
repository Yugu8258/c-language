#include <stdio.h>

int main(void)
{
    // 变量类型和变量名无实际意义
    int a = 1, b = 1, c = 1;

    int result = (a += 1, b += 1, c += 3);

    printf("a = %d, b = %d, c = %d, result = %d\n", a, b, c, result);
    
    return 0;
}

