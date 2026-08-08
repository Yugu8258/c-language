#include <stdio.h>
#include <inttypes.h>

#define MAX_ACHIEVEMENTS 10

const char *achievements[MAX_ACHIEVEMENTS];

size_t achievements_count = 0;

void add_achievement(const char *new_achievement);

void print_achievements(void);

int main(void)
{
    add_achievement("完成第一个挑战奖杯");
    add_achievement("找到了所有的隐藏宝箱");

    print_achievements();

    return 0;
}

void add_achievement(const char *new_achievement)
{
    if (achievements_count < MAX_ACHIEVEMENTS)
    {
        achievements[achievements_count++] = new_achievement;
        printf("添加成就: %s\n", new_achievement);
    }
    else
    {
        printf("成就数组已满, 无法添加新的成就!\n");
    }
}

void print_achievements(void)
{
    printf("玩家成就列表:\n");
    for (size_t i = 0; i < achievements_count; ++i)
    {
        printf("%zu: %s\n", i + 1, achievements[i]);
    }
}

