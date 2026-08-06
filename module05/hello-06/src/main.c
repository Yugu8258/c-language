#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

int main(void)
{
    uint32_t choice;
    uint32_t ret;

    do
    {
        // 显示菜单
        puts("***主菜单***");
        puts("1. 新游戏");
        puts("2. 载入游戏");
        puts("3. 退出");
        puts("请选择一个选项:");

        ret = scanf("%" PRIu32, &choice);
        // 读取失败, 清空缓冲区垃圾字符
        if (ret != 1)
        {
            // 清理所有无效字符
            while (getchar() != '\n');
            puts("非法输入!请输入正整数!");
            continue;
        }

        // 处理用户选择
        switch (choice)
        {
            case 1:
                puts("新游戏已经启动...");
                // TODO: 新游戏逻辑
                break;
            case 2:
                puts("载入存档中...");
                puts("存档已经载入...");
                // TODO: 载入存档后的游戏逻辑
                break;
            case 3:
                puts("游戏已退出...");
                // TODO: 退出逻辑
                break;
            default:
                puts("无效选择, 请重新输入!");
                break;
        }
        break;
    } while (true);

    return 0;
}

