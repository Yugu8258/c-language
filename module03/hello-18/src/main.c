#include <stdio.h>

int main(void)
{
    //  && 逻辑与
    //  || 逻辑或

    // 变量类型与变量名无实际意义

    int condition_a = 1;
    int condition_b = 0;

    // 两边同时为真返回真, 否则返回假
    int res = condition_a && condition_b;

    printf("res : %d\n", res);

    // 两边有一个为真返回真, 否则返回假
    res = condition_a || condition_b;
    printf("res : %d\n", res);

    return 0;
}

