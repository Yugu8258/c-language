#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/* 跨平台休眠宏, 单位: s */
#ifdef _WIN32
#define SLEEP_SEC(s) Sleep((s) * 1000)
#else
#define SLEEP_SEC(s) sleep((s))
#endif

/* 农场单元格状态, enum语义优于#define */
typedef enum
{
    EMPTY    = 0,       // 空地
    PLANTED  = 1,       // 已种植未成熟
    MATURED  = 2,       // 成熟作物
    STONE    = 3        // 石头障碍物
} FarmCell;

#define ROWS           10       // 农场的行
#define COLS           10       // 农场的列
#define SIM_LOOP_CNT   5        // 模拟迭代轮数
#define MATURE_RATE    3        // 3/10概率成熟
#define STONE_RATE     2        // 2/10概率生成石头

void print_farm(FarmCell farm[ROWS][COLS]);

void clear_screen(void);

int main(void)
{
    FarmCell farm[ROWS][COLS];

    // 随机数种子
    srand((unsigned int)time(NULL));

    // 初始化农场: 空地 / 已种植 / 石头
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            int r = rand() % 10;
            if (r < STONE_RATE)
            {
                farm[i][j] = STONE;
            }
            else if (r < 5)
            {
                farm[i][j] = PLANTED;
            }
            else
            {
                farm[i][j] = EMPTY;
            }
        }
    }

    print_farm(farm);

    SLEEP_SEC(1);

    // 模拟作物生长
    for (size_t step = 0; step < SIM_LOOP_CNT; step++)
    {
        clear_screen();

        // 更新作物状态: PLANTED有概率变成MATURED
        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++)
            {
                if (farm[i][j] == PLANTED)
                {
                    if ((rand() % 10) < MATURE_RATE)
                    {
                        farm[i][j] = MATURED;
                    }
                }
            }
        }

        print_farm(farm);
        SLEEP_SEC(1);
    }

    return 0;
}

/**
 * @brief 打印农场地图
 */
void print_farm(FarmCell farm[ROWS][COLS])
{
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            switch (farm[i][j])
            {
                case EMPTY:     printf(". "); break;    // 空地
                case PLANTED:   printf("* "); break;    // 已种植未成熟
                case MATURED:   printf("# "); break;    // 已成熟
                case STONE:     printf("! "); break;    // 石头
                defaule:        printf("? "); break;    // ???
            }
        }

        printf("\n");
    }
}

/**
 * @brief 跨平台清屏
 */
void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    // 标准ANSI清屏, 绝大多数Linux/Maxos终端支持
    printf("\033[2J\033[1;1H");
#endif
}

