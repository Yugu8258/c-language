#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>

#define EXP_PER_LEVEL   100     // 每个等级所需要的经验值
#define MAX_LEVEL       10      // 最高等价假设为10  
#define HINTS_COUNT     10      // 宝藏提示的数量10

// 增加经验值
void increase_exp(int32_t *exp, int32_t amount);

// 检查升级, 支持连续升级: 放回true代表发生过升级
bool check_level_up(int32_t *exp, int32_t *level);

// 根据等级获取宝藏提示
const char *get_treasure_hint(int32_t level);

// 打印玩家的状态
void print_player_status(int32_t exp, int32_t level);

int main(void)
{
    /**
     * 游戏案例
     *
     * 玩家属性: exp, level.
     *
     * 解谜:
     *
     * 等级提升:
     *
     * 游戏的目标:
     * 
     */

    int32_t player_exp = 0;

    int32_t player_level = 1;

    int32_t input_exp;

    puts("===== 寻宝游戏 =====");

    print_player_status(player_exp, player_level);

    // 模拟回合交互
    while (true)
    {
        printf("\n请输入本次获得的经验(输入负数退出):");
        if (scanf("%" PRId32, &input_exp) != 1)
        {
            // 清除输入缓冲去
            while (getchar() != '\n');
            printf("输入无效, 请输入数字!\n");
            continue;
        }

        if (input_exp < 0)
        {
            printf("游戏结束!\n");
            break;
        }

        increase_exp(&player_exp, input_exp);
        print_player_status(player_exp, player_level);

        if (check_level_up(&player_exp, &player_level))
        {
            printf("获得宝藏线索: %s\n", get_treasure_hint(player_level));
        }
        else
        {
            if (player_level < MAX_LEVEL)
            {
                printf("还需要更多的经验才能升级!\n");
            }
            else
            {
                printf("已经达到最高等级, 无法继续升级!\n");
            }
        }
    
    }

    return 0;
}

void increase_exp(int32_t *exp, int32_t amount)
{
    if (exp == NULL) { return; }

    *exp += amount;
}

bool check_level_up(int32_t *exp, int32_t *level)
{
    if (exp == NULL || level == NULL) { return false; }

    bool has_level_up = false;

    // 支持连续升级, 知道经验不足或者达到满级
    while ((*exp >= EXP_PER_LEVEL) && (*level < MAX_LEVEL))
    {
        *exp -= EXP_PER_LEVEL;
        (*level)++;
        printf("恭喜你升级到了%" PRId32 "级!\n", *level);
        has_level_up = true;
    }

    return has_level_up;
}

const char *get_treasure_hint(int32_t level)
{
    static const char *hints[HINTS_COUNT] = {
        "提示 1  : 宝藏在古老的大树附近",
        "提示 2  : 向着日落的方向前进",
        "提示 3  : 寻找一块刻有花纹的岩石",
        "提示 4  : 水流会指引你的道路",
        "提示 5  : 小心脚下的藤蔓陷阱",
        "提示 6  : 高出可以看见遗迹轮廓",
        "提示 7  : 石碑文字记录着秘密",
        "提示 8  : 月光降临之时显示线索",
        "提示 9  : 要过沼泽不要直接穿过",
        "提示 10 : 你找到最后的宝藏!",
    };

    if (level > 0 && (size_t)level <= HINTS_COUNT)
    {
        return hints[(size_t)level - 1];
    }

    return "未知提示: 没有对应的线索";
}

void print_player_status(int32_t exp, int32_t level)
{
    printf("\n----- 玩家状态 -----\n");
    printf("等级: %" PRId32 "\n", level);
    printf("当前经验: %" PRId32 "/%d\n", exp, EXP_PER_LEVEL);
    printf("---------------------\n");
}

