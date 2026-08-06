#include <stdio.h>

int main(void)
{
    // 隐式确定数组大小的初始化
    int arr[] = { 1, 2, 3, 4, 5 }; // 这个数组一定是固定的

    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("arr size: %zu\n", size);

    return 0;
}

