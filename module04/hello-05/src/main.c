#include <stdio.h>
#include <stdbool.h>

int main(void)
{

    // 天气晴朗和场地可用的情况下, 就可以举行高尔夫球活动

    bool is_weather_sunny = false;   // 假设天气不晴朗
    bool is_venue_available = true;  // 假设场地可用

    // 扩展
    // 使用逻辑AND && 来处理if-else的短路行为
    if (is_weather_sunny && is_venue_available)
    {
        printf("如期举行!\n");
    }
    else
    {
        printf("活动无法举行!\n");
        if (!is_weather_sunny)
        {
            printf("原因: 天气不晴朗!\n");
        }
        else
        {
            printf("原因: 场地不可用!\n");
        }
    }

    return 0;
}

