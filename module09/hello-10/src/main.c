#include "game_structs.h"
#include "game_functions.h"

#include <stdio.h>

// 库函数

int main(void)
{
    puts("Welcome to the Text RPG Game!\n");

    Player player;

    create_player(&player, "Hero", Warrior);

    print_player_info(&player);

    // 开始游戏
    // 游戏运行
    // 游戏结束

    return 0;
}

