#include <stdio.h>

#define PI 3.14

double square_area(double side);

double rectangle_area(double length, double width);

double circle_area(double redius);

int main(void)
{
    double side = 5.0;

    double length = 10.0, width = 7.0;

    double redius = 3.5;

    printf("%lf\n", square_area(side));

    printf("%lf\n", rectangle_area(length, width));

    printf("%lf\n", circle_area(redius));

    return 0;
}

double square_area(double side)
{
    return side * side;
}

double rectangle_area(double length, double width)
{
    return length * width;
}

double circle_area(double redius)
{
    return redius * redius * PI;
}

