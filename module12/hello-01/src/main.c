#define _DEFAULT_SOURCE
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main(void)
{
    // sqrt()

    double input_angle_degress = 0.0;
    double sin_value = 0.0;
    double cos_value = 0.0;
    double tan_value = 0.0;

    printf("请输入角度(度°):\n");
    scanf("%lf", &input_angle_degress);

    // 将角度转换为弧度
    input_angle_degress = input_angle_degress * (M_PI / 180.0);

    // 计算三角函数值
    sin_value = sin(input_angle_degress);
    cos_value = cos(input_angle_degress);
    tan_value = tan(input_angle_degress);

    printf("The sine of %.2f degress is: %.2f\n", input_angle_degress, sin_value);
    printf("The cose of %.2f degress is: %.2f\n", input_angle_degress, cos_value);
    printf("The tan of %.2f degress is: %.2f\n", input_angle_degress, tan_value);

    return 0;
}

