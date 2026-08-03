#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    /**
     * 玩家可以选择进入不同的房间, 每一个房间都有不同的进入条件.
     *
     * 房间A: 玩家需要VIP身份
     * 房间B: 玩家需要至少有10个金币, 或者是一个特殊道具
     * 房间C: 玩家需要有VIP身份, 并且金币数量不得少于20
     * 房间D: 晚间需要有VIP身份或者特殊道具, 并且金币数量不少于5
     */

    // 玩家属性 (在真实程序中可能来自于用户输入或者是游戏逻辑)

    bool is_vip = true;             // 是否是vip
    uint32_t coins = 15;            // 玩家金币数量
    bool has_speacil_item = false;  // 玩家是否有特殊道具

    // 检查房间A的条件
    if (is_vip)
    {
        puts("玩家可以进入房间A.");
    }
    else
    {
        puts("玩家不能进入房间, 因为房间A需要VIP身份.");
    }

    // 检查房间B的条件
    if (coins >= 10 || has_speacil_item)
    {
        puts("玩家可以进入房间B.");
    }
    else
    {
        puts("玩家不能进入房间B, 因为需要至少10个金币或者一个特殊道具.");
    }

    // 检查房间C的条件
    if (is_vip && coins >= 20)
    {
        puts("玩家可以进入房间C.");
    }
    else
    {
        puts("玩家不能进入房间C, 因为需要VIP身份并且至少应该有20个金币.");
    }

    // 检查房间D的条件
    if ((is_vip || has_speacil_item) && coins >= 5)
    {
        puts("玩家可以进入房间D.");
    }
    else
    {
        puts("玩家不能进入房间D, 因为需要VIP身份或者特殊道具, 并且满足不得少于5金币的条件.");
    }

    return 0;
}

