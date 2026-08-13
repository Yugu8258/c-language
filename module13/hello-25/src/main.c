#include <stdio.h>
#include <stdarg.h>

double average(int num_args, ...);

int main(void)
{
    // 可变参数 

    printf("Ave 2,3,4,5 = %.2f\n", average(4,2,3,45,5));

    return 0;
}

/**
 * @bierf 计算平均数
 * 
 * @param num_args 参数的数量
 * @param ... 可变参数列表, 即要计算平均的数字
 *
 * @return 平均数
 */
double average(int num_args, ...)
{
    double sum = 0.0;
    
    va_list args;

    va_start(args, num_args);

    for (size_t i = 0; i < num_args; ++i)
    {
        sum += va_arg(args, int); // va_arg获取下一个参数
    }

    va_end(args);

    return num_args > 0 ? sum / num_args : 0;
}

