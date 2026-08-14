#include <stdio.h>
#include <stdlib.h>

int compare_value(const void *a, const void *b);

void generic_sort(void *array, size_t element_size, size_t element_count, int (*compare)(const void*, const void*));

int main(void)
{
    // 比较函数
    // 高可用
    // 泛型编程
    // void*

    int num1 = 1;
    int num2 = 2;

    printf("%d\n", compare_value(&num1, &num2));
    
    int arrays[] = { -2, 90, 0, -123, 3, 41, 1 };
    size_t arrays_size = sizeof(arrays) / sizeof(arrays[0]);

    generic_sort(arrays, sizeof(arrays[0]), arrays_size, compare_value);

    for (size_t i = 0; i < arrays_size; ++i)
    {
        printf("%d ", arrays[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

// 强制类型转换为int类型
int compare_value(const void *a, const void *b)
{
    int age1 = *(const int*)a;
    int age2 = *(const int*)b;

    if (age1 < age2) { return -1; }
    if (age1 > age2) { return 1; }

    return 0;
}

void generic_sort(void *array, size_t element_size, size_t element_count, int (*compare)(const void*, const void*))
{
    qsort(array, element_count, element_size, compare);
}

