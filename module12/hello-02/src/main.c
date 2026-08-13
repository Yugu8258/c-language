#include <stdio.h>
#include <math.h>

int main(void)
{
    // 计算双曲函数值
    double input_value = 1.0; // 假设

    double sinh_value = sinh(input_value);

    double cosh_value = cosh(input_value);

    double tanh_value = tanh(input_value);

    printf("sinh(%f) = %f\n", input_value, sinh_value);

    printf("cosh(%f) = %f\n", input_value, cosh_value);

    printf("tanh(%f) = %f\n", input_value, tanh_value);
}

