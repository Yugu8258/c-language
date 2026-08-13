#include <stdio.h>
#include <math.h>

int main(void)
{
    // c语言中, 使用指数和对数函数

    double input_exp = 1.0;         // 指数函数的值

    double input_log = 2.71828;     // 自然对数函数的输入值, 接近e

    double input_log10 = 10.0;      // 以10为底的对数函数的输入值

    // 计算指数函数值
    double result_exp = exp(input_exp);

    printf("exp(%.2f) = %f\n", input_exp, result_exp);
    
    // 自然对数
    double result_log = log(input_log);

    printf("exp(%.2f) = %f\n", input_log, result_log);

    // 以10为底的对数
    double result_log10 = log10(input_log10);
    
    printf("exp(%.2f) = %f\n", input_log10, result_log10);

    return 0;
}

