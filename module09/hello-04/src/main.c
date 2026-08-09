#include <stdio.h>

// 通过值返回结构体

typedef struct
{
    int x;
    int y;
} Point;

Point get_point(void);

int main(void)
{
    Point my_point = get_point();

    printf("Point : (%d, %d)\n", my_point.x, my_point.y);

    return 0;
}

Point get_point(void)
{
    // 值语句(values semantics)
    Point p = { 10, 20 };
    return p; // return 一个结构体副本
}

