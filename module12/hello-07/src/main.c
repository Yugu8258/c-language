#include <stdio.h>
#include <math.h>
#include <float.h>

void check_float(double number);

int main(void)
{
    double numbers[] = { 0.0, 1.0, -1.0, 1.0 / 0.0, -1.0 / 0.0, 0.0 / 0.0, DBL_MIN / 2.0};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; ++i)
    {
        check_float(numbers[i]);
    }

    return 0;
}

void check_float(double number)
{
    // 检查浮点数的分类
    switch (fpclassify(number))
    {
        case FP_INFINITE:   printf("%.2f 是无穷大\n", number);              break;
        case FP_NAN:        printf("%.2f 不是一个数字(NaN)\n", number);     break;
        case FP_NORMAL:     printf("%.2f 是一个正常数\n", number);          break;
        case FP_SUBNORMAL:  printf("%.2f 是次正规数\n", number);            break;
        case FP_ZERO:       printf("%.2f 是零\n", number);                  break;
    }

    if (isfinite(number)) 
    {
        printf("%.2f 是有限的.\n", number);
    }

    if (isinf(number))
    {
        printf("%.2f 是无穷大.\n", number);
    }

    if (isnan(number))
    {
        printf("%.2f 是NaN.\n", number);
    }

    if (isnormal(number))
    {
        printf("%.2f 是正常数.\n", number);
    }

    if (signbit(number))
    {
        printf("%.2f 是有限的.\n", number);
    }
    else
    {
        printf("%.2f 的符号位是正或零.\n", number);
    }

    printf("\n");
}

