#include <stdio.h>
#include <stdint.h>

void check_car_rent(uint8_t age, uint8_t driving_exp_years);

int main(void)
{
    // 卫语句

    // 租车案例
    // 年龄大于等于21周岁, 驾龄大于一年

    uint8_t age = 23;

    uint8_t driving_exp_years = 3;

    check_car_rent(age, driving_exp_years);

    check_car_rent(19, 1);

    return 0;
}

void check_car_rent(uint8_t age, uint8_t driving_exp_years)
{
    if (age <= 21)
    {
        puts("不满足条件: 年龄小于21周岁");
        return;
    }

    if (driving_exp_years <= 1)
    {
        puts("不满足条件: 驾龄小于一年");
        return;
    }

    puts("满足租车条件!");
}

