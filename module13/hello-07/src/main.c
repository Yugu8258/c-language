#include <stdio.h>

int main(void)
{
    // 多级指针
    // 指向指针的指针

    int a = 10;         // 一个普通的变量a

    // ptr -> a
    int *ptr = &a;      // 一个指向int变量a的指针

    // ptr是一个指针, 一个指针是保存了一个变量的地址, 现在我们想要保存一个指针的地址?

    int **pptr = &ptr;  // 一个指向指针ptr的指针

    return 0;
}

