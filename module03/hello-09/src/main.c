#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 设置配置寄存器的初始状态(所有选项都未设置)
    uint32_t device_config = 0;

    // 定义每个选项的掩码
    const uint32_t option1_mask = 1 << 0;
    const uint32_t option2_mask = 1 << 1;
    const uint32_t option3_mask = 1 << 2;

    // 位或: 开启 option1, option3
    device_config |= option1_mask | option3_mask;

    // 读取option2状态
    uint32_t option2_status = (device_config & option2_mask) >> 1;

    // 关闭option1
    device_config &= ~option1_mask;

    // 打印调试
    printf("config: 0x%" PRIx32 "\n", device_config);
    printf("option2 status: %" PRIu32 "\n", option2_status);

    return 0;
}

