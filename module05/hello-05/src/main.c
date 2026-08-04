#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

int main(void)
{
    uint32_t total_laps = 10; // 总圈数
    uint32_t current_lap = 0; // 当前跑跑的圈数

    puts("开始跑步");

    // while先判断条件, 检查条件是不是true来执行, 如果不满足, 就不执行
    // do-while 先执行, 在检查是不是true, 如果不满足, 就不执行

    do {
        current_lap++;
        printf("跑步者完成第%-2" PRIu32 "圈\n", current_lap);
    } while (current_lap < total_laps);

    puts("跑步完成");

    return 0;
}

