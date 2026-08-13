#include <stdio.h>
#include <math.h>

int main(void)
{
    double group1_max_temp = 35.5;
    double group2_max_temp = 37.2;

    double group1_min_temp = -5.0;
    double group2_min_temp = -3.8;

    double max_temp = fmax(group1_max_temp, group2_max_temp);
    printf("max_temp : %.2f\n", max_temp);

    double min_temp = fmin(group1_min_temp, group2_min_temp);
    printf("min_temp : %.2f\n", min_temp);

    double temp_diff_max = fdim(max_temp, min_temp);
    printf("temp_diff_max : %.2f\n", temp_diff_max);

    return 0;
}

