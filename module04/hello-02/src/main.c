#include <stdio.h>

int main(void)
{
    float current_temperature = 35.0f;

    if (current_temperature > 30.0)
    {
        printf("天气热了, 需要开空调冷气!\n");
    } 
    else if (current_temperature < 15.0)
    {
        printf("天气冷了, 需要开空调暖气!\n");
    }
    else
    {
        printf("不需要开空调!\n");
    }

    return 0;
}

