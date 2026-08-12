#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int32_t(*operation_t)(int32_t, int32_t);

int32_t add(int32_t a, int32_t b);
int32_t subtract(int32_t a, int32_t b);
int32_t multiply(int32_t a, int32_t b);
int32_t divide(int32_t a, int32_t b);

// 通过函数指针数组包含各种操作
operation_t operations[4] = { add, subtract, multiply, divide };

int main(void)
{
    int32_t a = 10;
    int32_t b = 5;

    int32_t result = 0;

    result = operations[0](a, b);
    printf("result : %" PRIu32 "\n", result);

    result = operations[1](a, b);
    printf("result : %" PRIu32 "\n", result);

    result = operations[2](a, b);
    printf("result : %" PRIu32 "\n", result);

    result = operations[3](a, b);
    printf("result : %" PRIu32 "\n", result);

    return EXIT_SUCCESS;
}

int32_t add(int32_t a, int32_t b)
{
    return a + b;
}

int32_t subtract(int32_t a, int32_t b)
{
    return a - b;
}

int32_t multiply(int32_t a, int32_t b)
{
    return a * b;
}

int32_t divide(int32_t a, int32_t b)
{
    return a / b;
}

