#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void)
{
    // 正无穷大
    float positive_infinity = INFINITY;
    printf("Positive Infinity: %f\n", positive_infinity);

    // 负无穷大
    float negative_infinity = -INFINITY;
    printf("Negative Infinity: %f\n", negative_infinity);

    // 除以0产生的无穷大
    float num = 1.0f;
    float infinity = num / 0.0f;
    printf("1.0 / 0.0 = %f\n", infinity);

    // Nano 0/0
    float nan = 0.0f / 0.0f;
    printf("0.0 / 0.0 = %f\n", nan);

    // 负数开平分根
    float negative_sqrt = sqrt(-1.0f);
    printf("sqrt(-1.0f) = %f\n", negative_sqrt);

    // Nan nan -> not a number

    return 0;
}

