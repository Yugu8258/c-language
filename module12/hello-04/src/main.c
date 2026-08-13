#include <stdio.h>
#include <math.h>

int main(void)
{
    double num_sqrt = 16.0;     // 要求的平方根的数
    double num_fabs = -5.7;     // 要求的绝对值的数
    double num_ceil = 2.3;      // 向上取整的数
    double num_floor = 2.7;     // 向下取整的数
    double num1_fmod = 5.5;     // 求余数的被除数
    double num2_fmod = 2.0;     // 求余数的除数

    double result_sqrt = sqrt(num_sqrt);
    double result_fabs = fabs(num_fabs);
    double result_ceil = ceil(num_ceil);
    double result_floor = floor(num_floor);
    double result_fmod = fmod(num1_fmod, num2_fmod);

    printf("sqrt(%.2f) = %f\n", num_sqrt, result_sqrt);
    printf("fabs(%.2f) = %f\n", num_fabs, result_fabs);
    printf("ceil(%.2f) = %f\n", num_ceil, result_ceil);
    printf("floor(%.2f) = %f\n", num_floor, result_floor);
    printf("fmod(%.2f %.2f) = %f\n", num1_fmod, num2_fmod, result_fmod);

    return 0;
}

