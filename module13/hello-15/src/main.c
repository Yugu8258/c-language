#include <stdio.h>
#include <stdlib.h>

typedef void (*Callback)(int);

void traverse(int *array, int size, Callback callback);

void print_element(int element);
void double_element(int element);
void check_if_even(int element);

int main(void)
{
    // 回调函数
    // 是你传递给另一个函数的函数. 这允许在后者中调用前者
    // 这种机制让你能够在不同的时间或条件下, 根据需要执行特定的功能
    // 为什么使用回调函数: 代码更加灵活和可重用(分模块)
    // 因为你可以根据不同的情况动态的改变执行操作

    int numbers[] = { 1, 2, 3, 4, 5 };

    int size = sizeof(numbers) / sizeof(numbers[0]);

    traverse(numbers, size, print_element);
    traverse(numbers, size, double_element);
    traverse(numbers, size, check_if_even);

    return EXIT_SUCCESS;
}

void traverse(int *array, int size, Callback callback)
{
    for (int i = 0; i < size; i++)
    {
        callback(array[i]);
        // print_element
        // double_element
        // check_if_even
        // ...
    }
}

void print_element(int element)
{
    printf("%d\n", element);
}

void double_element(int element)
{
    printf("%d doubled is %d\n", element, element * 2);
}

void check_if_even(int element)
{
    if (element % 2 == 0)
    {
        printf("%d is even\n", element);
    }
    else
    {
        printf("%d is odd\n", element);
    }
}

