#include <stdio.h>
#include <float.h>

int main(void)
{
    float float_num = 1.0 / 3.0;
    double double_num = 1.0 / 3.0;

    printf("Float precision: %.20f\n", float_num);
    printf("Double precision: %.20lf\n", double_num);

    printf("Defined max precision for float: %d\n", FLT_DIG);
    printf("Defined mac precision for double: %d\n", DBL_DIG);

    return 0;
}

