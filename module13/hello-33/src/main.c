#include <stdio.h>

// void print_array(int arr[], int size);
void print_array(int *arr, int size);

int main(void)
{
    // c语言函数参数中的数组传递

    int numbers[] = { 2, 4, 6, 8, 10, 23, 13 };

    int size = sizeof(numbers) / sizeof(numbers[0]);

    // 数组的第0个元素的地址, 就是这个数组的首地址
    print_array(&numbers[0], size);

    print_array(numbers, size);

    return 0;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

