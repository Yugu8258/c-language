#include <stdio.h>
#include <assert.h>

// 在一个给定整数数组中寻找最大值
int findMaximum(int *arr, int length);

int main(void)
{
    int numbers[] = { 3, 1, 4, 5, 6, 1, 4, 6, 8 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int result = findMaximum(numbers, size);

    printf("result : %d\n", result);

    findMaximum(NULL, 0);

    return 0;
}

int findMaximum(int *arr, int length)
{
    assert(arr != NULL && length > 0);

    int max = arr[0];

    for (int i = 0; i < length; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

