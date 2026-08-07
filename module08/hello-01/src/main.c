#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t building_floors[5] = { 101, 102, 103, 104, 105 };

    uint32_t target_floor = 102; // 快递员需要找的目标住户

    uint32_t found = 0; // 标记是否找到住户

    printf("快递员开始在大楼中寻找 %" PRIu32 "...\n", target_floor);

    for (size_t i = 0; i < 5; i++)
    {
        if (building_floors[i] == target_floor)
        {
            printf("快递员找到了住户 %" PRIu32 "的地址: %p\n", target_floor, (void*)&building_floors[i]);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("快递员没有找到用户%" PRIu32 "\n", target_floor);
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("住户 %" PRIu32 " 的地址: %p\n", building_floors[i], (void *)&building_floors[i]);
    }

    return 0;
}

