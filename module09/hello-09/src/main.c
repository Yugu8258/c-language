#include <stdio.h>

typedef union
{
    int int_value;
    float float_value;
    char *string_value;
} Data;

typedef enum
{
    INT,
    FLOAT,
    STRING
} DataType;

typedef struct
{
    DataType type;
    Data data;
} TypedData;

void print_data(TypedData *typed_data);
 
int main(void)
{
    // 联合 Union
    // 它允许在相同的内存位置存储不同的数据类型.
    // 联合体的所有成员共享一块内存空间, 大小等于其最大成员的大小.
    // 这就意味着在任一时刻, 联合体只能存储一个成员的值

    // 一个变量可能存储多种类型的数据, 但是在一个给定时刻里, 只是用其中一种的数据类型, 这样可以节省内存

    TypedData data1= { INT, { .int_value = 10 } };
    TypedData data2= { FLOAT, { .float_value = 3.14f } };
    TypedData data3= { STRING, { .string_value = "Hello, Union!" } };

    print_data(&data1);
    print_data(&data2);
    print_data(&data3);

    return 0;
}

void print_data(TypedData *typed_data)
{
    switch (typed_data->type)
    {
        case INT:       printf("Integer: %d\n", typed_data->data.int_value);        break;
        case FLOAT:     printf("Integer: %.2f\n", typed_data->data.float_value);    break;
        case STRING:    printf("Integer: %s\n", typed_data->data.string_value);     break;
        default: break;
    }
}
 
