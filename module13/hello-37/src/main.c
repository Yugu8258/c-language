#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define EXP_PER_LEVEL   100     // 每个等级需要的经验值
#define MAX_LEVEL       10      // 假设最高等级10
#define MAX_HINTS_COUNT 10      // 宝藏提示数量
#define MAX_LISTENERS   10      // 最大监听器数量

typedef struct
{
    int32_t exp;
    int32_t level;
} Player;

typedef void (*LevelUpListener)(Player *);

typedef struct
{
    LevelUpListener listeners[MAX_LISTENERS];
    uint32_t listenerCount;
} EventSystem;

EventSystem eventSystem = { 0 };

// 用于注册新的监听器
void addLevelUpListener(LevelUpListener listener);

// 函数用于在玩家升级时候所触发的所有注册的监听器
void triggerLevelUpEvent(Player *player);

void increase_exp(Player *player, int32_t amount);

// 升级一次提供宝藏提示
void treasureHintProvider(Player *player);

// 升级监听器, 如果升级的话给个提示
void levelUpAnnouncer(Player *player);

void unlockNewAbility(Player *player);

int main(void)
{
    // 事件系统
    // 监听器
    // 触发器

    Player player = { 0, 1 }; // 初始经验为0, 等级1

    // 添加升级事件监听器
    addLevelUpListener(treasureHintProvider);
    addLevelUpListener(levelUpAnnouncer);
    addLevelUpListener(unlockNewAbility);

    // 模拟游戏过程获得经验

    increase_exp(&player, 50);
    increase_exp(&player, 75);
    increase_exp(&player, 200);

    printf("最终等级: %" PRId32 ", 剩余经验: %" PRId32 "\n", player.level, player.exp);

    return EXIT_SUCCESS;
}

void addLevelUpListener(LevelUpListener listener)
{
    if (eventSystem.listenerCount < MAX_LISTENERS)
    {
        eventSystem.listeners[eventSystem.listenerCount++] = listener;
    }
}

void triggerLevelUpEvent(Player *player)
{
    for (size_t i = 0; i < eventSystem.listenerCount; ++i)
    {
        eventSystem.listeners[i](player);
    }
}

void increase_exp(Player *player, int32_t amount)
{
    player->exp += amount;
    printf("获得 %" PRId32 " 点经验, 当前经验值是: %" PRId32 "\n", amount, player->exp);

    while (player->exp >= EXP_PER_LEVEL && player->level < MAX_LEVEL)
    {
        player->exp -= EXP_PER_LEVEL;
        player->level++;
        triggerLevelUpEvent(player);
    }

}

void treasureHintProvider(Player *player)
{
    static const char *hints[MAX_LEVEL] = {
        "提示1: 宝藏硬藏在古老的瀑布后面",
        "提示2: 寻找被遗忘的失落之剑",
        "提示3: 探索神秘的地下洞穴",
        "提示4: 解开远古神庙的谜题",
        "提示5: 寻找沙漠中的绿洲",
        "提示6: 攀登雪山寻找隐藏的山洞",
        "提示7: 深入海底探索沉船",
        "提示8: 穿越时空裂缝",
        "提示9: 收集七颗龙珠",
        "提示10: 挑战最终BOSS"
    };

    if (player->level > 0 && player->level <= MAX_LEVEL)
    {
        printf("%s\n", hints[player->level - 1]);
    }
}

void levelUpAnnouncer(Player *player)
{
    printf("恭喜你升级到了 %" PRId32 " 级!\n", player->level);
}

void unlockNewAbility(Player *player)
{
    printf("解锁了新的能力:");
    switch (player->level)
    {
        case  3:    printf("二段跳!\n");    break;
        case  5:    printf("水下呼吸!\n");  break;
        case  7:    printf("隐身五秒!\n");  break;
        case  9:    printf("解锁法宝!\n");  break;
        default:    printf("没有新能力\n"); break;
    }
}

