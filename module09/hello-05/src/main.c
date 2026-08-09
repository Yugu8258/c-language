#include <stdio.h>
#include <inttypes.h>

typedef struct
{
    uint32_t x;
    uint32_t y;
} Point;

int main(void)
{
    // 结构体数组
    
    Point points[] = {
        { 1, 2 },
        { 3, 4 }
    }; // 定义一个包含2个Point结构体的数组

    size_t size = sizeof(points) / sizeof(points[0]);

    for (size_t i = 0; i < size; ++i)
    {
        printf("Point %" PRIuMAX ": (%" PRIu32 ", %" PRIu32 ")\n", i, points[i].x, points[i].y);
    }
 
    return 0;
}

