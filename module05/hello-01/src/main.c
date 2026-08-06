#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // while

    const uint32_t TOTAL_LAPS = 10; // 总圈数

    uint32_t current_lap = 0; // 当前跑的圈数

    puts("开始罚跑!");

    // 循环条件
    while (current_lap < TOTAL_LAPS)
    {
        // 计次
        current_lap++;
        printf("跑步的人完成第 %-2" PRIu32 " 圈\n", current_lap);
    }

    return 0;
}

