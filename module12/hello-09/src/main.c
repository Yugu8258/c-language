#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 2.845;
    double divisor = 2.0;

    // 舍入函数
    printf("round(%f) = %f\n", value, round(value));
    printf("lround(%f) = %ld\n", value, lround(value));
    printf("llround(%f) = %lld\n", value, llround(value));
    printf("rint(%f) = %f\n", value, rint(value));
    printf("lrint(%f) = %ld\n", value, lrint(value));
    printf("llrint(%f) = %lld\n", value, llrint(value));
    printf("nearbyint(%f) = %f\n", value, nearbyint(value));
    
    // 剩余函数
    printf("remainder(%f, %f) = %f\n", value, divisor, remainder(value, divisor));

    // 特殊情况, 展示不同的舍入策略对比
    double special_value = 2.5;
    printf("\nSpecial Case (%f): \n", special_value);
    printf("round(%f) = %f\n", special_value, round(special_value));
    printf("rint(%f) = %f\n", special_value, rint(special_value));
    printf("nearbyint(%f) = %f\n", special_value, nearbyint(special_value));

    return 0;
}

