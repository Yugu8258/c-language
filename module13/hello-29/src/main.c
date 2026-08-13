#include <stdio.h>
#include <assert.h>

void processImage(int width, int height);

int main(void)
{
    processImage(1024, 768);

    // 模拟场景, 假设这个w, h是通过传递的方式,例如函数, 数组, 指针传递的, 那这个时候, 我们是无法通过肉眼看清楚它的值的
    int w = 50, h = 50;

    processImage(w, h);

    return 0;
}

void processImage(int width, int height)
{
    assert(width > 50 && width < 10000);
    assert(height > 50 && height < 10000);

    if (width > 50 && height > 50)
    {
        printf("Processing an image of size %dx%d pixels.\n", width, height);
    }
}

