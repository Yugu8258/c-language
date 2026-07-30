#include <stdio.h>
#include <float.h>

int main(void)
{
    float max_float = FLT_MAX;

    // OverFlow 上溢
    float overflow = max_float * 1000.0f;

    float min_float = FLT_MIN;

    // UnderFlow 下溢
    float underflow = min_float / 1000.0f;

    printf("Maximum Float: %e\n", max_float);

    printf("Overflow: %e\n", overflow);

    printf("Minimum Positive Float: %e\n", min_float);

    printf("Underflow: %e\n", underflow);

    return 0;
}

