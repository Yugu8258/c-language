#include <stdio.h>

int main(void)
{
    // linux/macOS
    // 更强调这个变量实际上是一个指针
    int *ptr;

    // 微软写法, int*, 表明强调p这个变量是一个int* (整形指针)类型的变量.
    int* ptr_ptr;

    // int* p, q; => int *p; int q;

    return 0;
}

