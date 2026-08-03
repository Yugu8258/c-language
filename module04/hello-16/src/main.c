#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    // 状态机
    // 管理复杂状态的转换, 使用switch-case

    // 0-> 红灯; 1-> 绿灯; 2-> 黄灯;

    uint8_t traffic_ligt_state = 0; // 初始状态: 红灯

    switch (traffic_ligt_state)
    {
        case 0:
            puts("红灯");
            traffic_ligt_state = 1;
            break;
        case 1:
            puts("绿灯");
            traffic_ligt_state = 2;
            break;
        case 2:
            puts("黄灯");
            traffic_ligt_state = 0;
            break;
        default:
            puts("???");
            break;
    }

    return 0;
}

