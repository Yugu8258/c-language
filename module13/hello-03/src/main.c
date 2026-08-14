#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 静态数组的声明和初始化
    // 编译的时候就确定了, 整个数组的大小和生命周期连同作用域, 都一起决定了
    // 分配在栈上
    int static_arr[5] = { 1, 2, 3, 4, 5 };
    printf("静态数组的内容:\n");
    for (size_t i = 0; i < 5; ++i)
    {
        printf("%d ", static_arr[i]);
    }
    printf("\n");

    // 动态内存分配 int arr[5];
    // 分配到堆上
    int *dynamic_arr = (int *)malloc(5 * sizeof(int));
    if (dynamic_arr == NULL)
    {
        perror("动态数组分配失败.");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < 5; ++i)
    {
        dynamic_arr[i] = (i + 1) * 10;
    }
    
    puts("动态数组的内容:");
    for (size_t i = 0; i < 5; ++i)
    {
        printf("%d ", dynamic_arr[i]);
    }
    printf("\n");

    // void* 指针在C语言中用于泛型编程.

    // 堆内存要手动释放, 因为不是简单的局部变量那么简单, 局部变量会在函数执行完之后自动释放, 而堆不会.

    free(dynamic_arr);

    return 0;
}

