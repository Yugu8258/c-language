#include <stdio.h>

int main(void)
{
    // 精度丢失
    float humidity = 48.3f;

    printf("Humidity: %f\n", humidity);
    printf("Humidity: %.2f\n", humidity);

    return 0;
}

