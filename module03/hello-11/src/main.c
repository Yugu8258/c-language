#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // 类型与变量名无实际意义
    int a = 10;
    int b = 20;

    bool greater = a > b;
    printf("a > b : %d\n", greater);

    bool less = a < b;
    printf("a < b : %d\n", less);

    bool equal = a == b;
    printf("a == b : %d\n", equal);

    bool not_equal = a != b;
    printf("a != b : %d\n", not_equal);

    bool greater_or_equal = a >= b;
    printf("a >= b : %d\n", greater_or_equal);

    bool less_or_equal = a <= b;
    printf("a <= b : %d\n", less_or_equal);

    return 0;
}

