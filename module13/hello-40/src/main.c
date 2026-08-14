#include <stdio.h>
#include <stdlib.h>

// 结构体中的指针成员 Pointer Member in a struct
typedef struct
{
    int *data; // 指针成员(指向动态分配的内存)
} Example;

typedef struct
{
    int id;
    char *title; // char title[50] -> 编译的时候, 必须明确说明是什么size
                 // char title[50000] -> 占空间, 连续不断的空间
                 // [500] -> 会出现浪费的现象
                 // 静态内存
    float price;
} Book;

// 动态内存 -> 运行的时候 在 堆(heap) 中申请内存

// stack 栈
// 堆
// 代码区
// 静态区(全局区)

int main(void)
{
    // malloc
    // free

    int n = 5;

    // arr是一个指针变量, 存储动态内存的起始地址 &arr[0]
    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        fprintf(stderr, "内存分配失败!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    printf("数组内容: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}

