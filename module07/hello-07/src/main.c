#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

// 游戏选项
#define ROCK        1   // 石头
#define PARER       2   // 布
#define SCISSORS    3   // 剪刀

// 函数声明
void print_instructions(void);
uint32_t get_player_move(void);
uint32_t get_computer_move(void);
void print_choice(uint32_t choice);
void determine_winner(uint32_t player_move, uint32_t computer_move);

int main(void)
{
    /**
     * 游戏案例: 石头剪刀布
     */

    // 初始化随机数生成器
    srand(time(NULL));

    // 打印游戏说明
    print_instructions();

    // 获取玩家和计算机的选择
    uint32_t player_move = get_player_move();
    uint32_t computer_move = get_computer_move();

    // 展示玩家和计算机的选择
    puts("你选择了:");
    print_choice(player_move);
    puts("计算机选择了:");
    print_choice(computer_move);

    // 判断确定赢家, 并且展示
    determine_winner(player_move, computer_move);

    return 0;
}

// 打印游戏说明
void print_instructions(void)
{
    puts("石头, 剪刀, 布. 游戏开始!");
    puts("规则: 输入数字, 确定猜拳. 1是石头, 2布, 3是剪刀\n");
    puts("=================================================");
}

uint32_t get_player_move(void)
{
    uint32_t choice;
    printf("请选择1石头, 2布, 3剪刀:\n");
    scanf("%" SCNu32, &choice);

    while (choice < ROCK || choice > SCISSORS)
    {
        printf("无效选择! 请重新选择: 1石头, 2布, 3剪刀:\n");
        scanf("%" SCNu32, &choice);
    }

    return choice;
}

uint32_t get_computer_move(void)
{
    return (rand() % (SCISSORS - ROCK + 1)) + ROCK;
}

void print_choice(uint32_t choice)
{
    switch (choice)
    {
        case ROCK:      puts("石头");   break;
        case PARER:     puts("布");     break;
        case SCISSORS:  puts("剪刀");   break;
        default:                        break;
    }
}

void determine_winner(uint32_t player_move, uint32_t computer_move)
{
    // 规则映射

    if (player_move == computer_move)
    {
        puts("平局");
        return;
    }

    // 定义一个胜利的规则映射, 其中键是玩家的移动, 值是玩家移动可以打败计算机的移动
    uint32_t winning_moves[4] = { 0, SCISSORS, ROCK, PARER }; // 0是占位符

    // winning_moves[1] SCISSORS
    // ROCK == 1

    printf("%s\n", computer_move == winning_moves[player_move] ? "你赢了" : "你输了");
}

