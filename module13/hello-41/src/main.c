#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;          // 数组指针
    // data -> int arr[capacity]; => data -> &arr[0];
    // data指向一个 动态分配的内存(数组)的首地址
    size_t size;        // 当前元素个数
    size_t capacity;    // 总容量
} Array;

// create
Array *create_array(size_t init_capacity);

// add
int append(Array *arr, int value);

void print_array(Array *arr);

void free_array(Array *arr);

int main(void)
{
    // 动态数组 Dunamic Array

    Array *arr = create_array(4);

    if (arr == NULL)
    {
        printf("创建数组失败!\n");
        return 1;
    }

    for (size_t i = 0; i < 10; i++)
    {
        append(arr, i + 1);
    }

    print_array(arr);

    free_array(arr);

    return EXIT_SUCCESS;
}

Array *create_array(size_t init_capacity)
{
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL)
    {
        return NULL;
    }

    arr->data = (int *)malloc(sizeof(int) * init_capacity);
    if (arr->data == NULL)
    {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = init_capacity;

    return arr;
}

int append(Array *arr, int value)
{
    if (arr == NULL) { return 0; }

    if (arr->size >= arr->capacity)
    {
        size_t new_capacity = arr->capacity * 2;
        int *temp = (int *)realloc(arr->data, new_capacity * sizeof(int));
        if (temp == NULL)
        {
            return 0;
        }

        arr->data = temp;
        arr->capacity = new_capacity;
    }

    arr->data[arr->size++] = value;

    return 1;
}

void print_array(Array *arr)
{
    if (arr == NULL) { return; }

    printf("\n数组元素:\n");
    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n元素个数: %zu\n容量: %zu\n", arr->size, arr->capacity);
}

void free_array(Array *arr)
{
    if (arr == NULL) { return; }

    free(arr->data);
    free(arr);
    arr = NULL;
}

