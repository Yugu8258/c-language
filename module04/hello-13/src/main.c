#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // 租车案例
    // age >= 21, 驾驶经验一年或一年以上

    uint8_t age = 23;
    uint8_t driving_exp_years = 2;

    // 卫语句

    if (age < 21)
    {
        puts("不满足条件: 年龄未大于23周岁!");
        return -1;
    }

    if (driving_exp_years < 1)
    {
        puts("不满足条件: 驾驶年龄不满足1及其以上!");
        return -1;
    }

    // 满足所有的条件
    puts("满足租车条件!");

    return 0;
}

