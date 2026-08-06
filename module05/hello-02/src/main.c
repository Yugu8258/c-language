#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    /**
     * 自动贩卖机
     *
     * 这个机器只支持硬币, 假设只买一种饮料, 每瓶的价格是5$.
     *
     * 怎样才能给用户饮料?
     *
     * 用户需要一直投币, 知道金额足够, 这样机器才可以提供饮料
     *
     * 增加条件(只接受1$,2$,5$的硬币)
     */

    // 1. 初始化

    const uint32_t PRICE = 5; // 饮料的价格(常量)

    uint32_t balance = 0; // 用户当前投入的金额(整数) -> 迭代

    uint32_t coin; // 每次投入的金额

    // 提示语
    puts("欢迎使用自动贩卖机(本机器只提供一种饮料), 价格为5$.");
    puts("只接受1$, 2$, 5$的硬币");

    // 2. 处理循环条件
    while (balance < PRICE)
    {
        // 模拟投币
        scanf("%" PRIu32, &coin);
        
        // 检查每次投币是否有效
        if (coin == 1 || coin == 2 || coin == 5)
        {
            balance += coin; // balance = balance + coin;
            printf("您已经投入了%" PRIu32 "$.\n", balance);
        }
        else
        {
            printf("无效投入, 请重新投入!\n");
        }

        puts("钱不够, 请继续投币.");
    }

    // 找零
    if (balance > PRICE)
    {
        printf("请收好你的硬币 %" PRIu32 "$\n", balance - PRICE);
    }

    puts("请取走你的饮料!");

    return 0;
}

