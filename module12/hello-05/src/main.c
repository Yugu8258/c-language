#define _DEFAULT_SOURCE
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main(void)
{
    double radius = 1.2;

    double square_side = 0.0;

    double circle_area = 0.0;

    double square_area = 0.0;

    square_side = 2 * radius;

    circle_area = M_PI * pow(radius, 2);

    square_area = pow(square_side, 2);

    printf("圆的面积: %f\n", circle_area);

    printf("边长为圆直径的正方形面积: %f\n", square_area);

    return 0;
}

