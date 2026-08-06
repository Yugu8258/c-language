#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define DAYS_IN_WEEK 7

int main(void)
{
    /**
     * 记录一周的天气, 计算平均天气, 记录最大, 最小天气
     */

    uint32_t daily_temperatures[DAYS_IN_WEEK] = { 22, 24, 19, 24, 17, 18, 23 };

    // 总和
    uint32_t sum = 0;

    // 最高气温
    uint32_t max_temp = daily_temperatures[0];

    // 最低气温
    uint32_t min_temp = daily_temperatures[0];

    // 打印一周的天气
    puts("一周的天气:");
    for (uint32_t i = 0; i < DAYS_IN_WEEK; i++)
    {
        printf("第 %" PRIu32 "天的温度: %" PRIu32 "°\n", i + 1, daily_temperatures[i]);

        sum += daily_temperatures[i];

        if (daily_temperatures[i] > max_temp)
        {
            max_temp = daily_temperatures[i];
        }

        if (daily_temperatures[i] < min_temp)
        {
            min_temp = daily_temperatures[i];
        }
    }

    double average = (double)sum / DAYS_IN_WEEK;

    printf("一周内最高温度为: %" PRIu32 "°\n", max_temp);
    printf("一周内最低温度为: %" PRIu32 "°\n", min_temp);
    printf("一周的平均温度: %.2f°\n", average);

    return 0;
}

