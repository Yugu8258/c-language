#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct player
{
    uint32_t id;
    char name[50];
} player_t;

void update_player_list(player_t **players, uint32_t *current_size, uint32_t new_size, player_t new_player);

void print_players(player_t *players, uint32_t size);

int main(void)
{
    // realloc()
    // 游戏服务器动态玩家列表管理

    player_t *players = NULL;     // 玩家列表初始化为空
    uint32_t current_size = 0;  // 当前玩家数量

    // 初始化了三个结构体, 模拟玩家进入
    player_t new_player_1 = { 1, "player_one" };

    update_player_list(&players, &current_size, current_size + 1, new_player_1);

    player_t new_player_2 = { 2, "player_two" };
    
    update_player_list(&players, &current_size, current_size + 1, new_player_2);

    player_t new_player_3 = { 3, "player_three" };

    update_player_list(&players, &current_size, current_size + 1, new_player_3);
    
    // 只不过, 整个players指向的一个数组, 再也不是我们所固定的静态数组, 而是一个malloc函数生成的动态数组

    print_players(players, current_size);

    free(players);

    return EXIT_SUCCESS;
}

void update_player_list(player_t **players, uint32_t *current_size, uint32_t new_size, player_t new_player)
{
    // 防止减少数组大小的时候数据丢失
    if (new_size < *current_size)
    {
        printf("Error: new_size is smaller than current_size.\n");
        return;
    }

    // 当增加玩家时, 确保new_size大小小于current_size
    if (new_size == *current_size)
    {
        printf("No resizing needed. The new_size must be greater than current_size to add a new player.\n");
        return;
    }

    player_t *temp = realloc(*players, new_size * sizeof(player_t));

    if (temp == NULL)
    {
        // 在重新分配失败时候, 保持原始列表不变, 避免数据丢失
        printf("Error reallocating memory!\n");
        // TODO: 考虑添加日志记录或者错误逻辑处理
    }
    else
    {
        *players = temp;
        // 如果是扩容, 则添加新玩家到列表
        if (new_size > *current_size)
        {
            (*players)[*current_size] = new_player; // 添加新玩家
        }
        *current_size = new_size; // 更新当前大小
    }
}

void print_players(player_t *players, uint32_t size)
{
    printf("Current Players:\n");
    for (size_t i = 0; i < size; ++i)
    {
        printf("ID: %" PRIu32 ", Name: %s\n", players[i].id, players[i].name);
    }
}

