#include <stdio.h>

int main(void)
{
    int num = -75;

    int multiply_by2 = num << 1;
    int divide_by2 = num >> 1;

    printf("%d x 2 = %d\n", num, multiply_by2);
    printf("%d / 2 = %d\n", num, divide_by2);

    return 0;
}

