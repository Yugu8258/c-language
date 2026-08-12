#include <stdio.h>
#include <stdlib.h>

// 1. 定义事件类型和事件处理函数签名: 首先我们定义游戏中可能发生的事件类型, 以及处理这些函数的签名
// 2. 实现事件注册和分发机制: 实现一个机制, 允许为不同的类型的事件注册处理函数, 并且在相应的事件发生时调用这些函数
// 3. 定义事件处理函数: 现在我们为游戏中的每一种事件类型定义具体的事件处理函数
// 4. 在游戏中使用事件处理系统: main中注册事件处理函数, 并且模拟事件的发生来演示系统的工作流程

typedef enum
{
    PLAYER_ATTACK,
    PLAYER_MOVE,
    EVENT_COUNT // 记录事件的总数
} GameEventType;

typedef void (*event_handler)(const char *player_name);

event_handler event_handlers[EVENT_COUNT]; // 事件处理函数的数组
// 声明了一个数组, 这个数组的每一个元素都是event_handler类型的函数指针, 意味着每个数组元素都可以存储一个指向函数的指针, 这个函数复合event_handler的签名, 它接受一个cont char* 参数类型并且返回void

// 注册事件处理函数
void register_event_handler(GameEventType event_type, event_handler handler);

// 分发事件
void dispatch_event(GameEventType event_type, const char *player_name);

// 事件
void handler_player_attack(const char *player_name);
void handler_player_move(const char *player_name);

int main(void)
{
    // 注册事件处理函数
    register_event_handler(PLAYER_ATTACK, handler_player_attack);
    register_event_handler(PLAYER_MOVE, handler_player_move);

    printf("===== 模拟事件触发 =====\n");
    dispatch_event(PLAYER_ATTACK, "Warrior");
    dispatch_event(PLAYER_MOVE, "Archer");

    return EXIT_SUCCESS;
}

void register_event_handler(GameEventType event_type, event_handler handler)
{
    if (event_type >= 0 && event_type < EVENT_COUNT)
    {
        event_handlers[event_type] = handler;
    }
}

void dispatch_event(GameEventType event_type, const char *player_name)
{
    if (event_type >= 0 && event_type < EVENT_COUNT && event_handlers[event_type] != NULL)
    {
        event_handlers[event_type](player_name);
    }
}

void handler_player_attack(const char *player_name)
{
    printf("%s attacks!\n", player_name);
}

void handler_player_move(const char *player_name)
{
    printf("%s moves!\n", player_name);
}

