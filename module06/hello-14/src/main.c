#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define BOARD_SIZE 15
#define DOT_MARK 0x00B7
#define PLAYER1 0x25CF
#define PLAYER2 0x25CB

// 方向数组: 右, 下, 右下, 左下, 四个方向检查五子连珠
static const int dirs[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };

int check_win(wchar_t board[BOARD_SIZE][BOARD_SIZE], uint8_t y, uint8_t x, wchar_t player);

int is_board_full(wchar_t board[BOARD_SIZE][BOARD_SIZE]);

static void flush_wbuf(void);

int main(void)
{
#ifdef _WIN32
    // 仅Windows执行
    // 设置控制台代码页为 UTF-8
    SetConsoleOutputCP(65001);
#endif

    // 设置区域为当前系统默认
    setlocale(LC_ALL, "en_US.UTF-8");

    wchar_t board[BOARD_SIZE][BOARD_SIZE];
    uint8_t x, y;

    // 状态
    wchar_t current_player = PLAYER1;

    // 始化棋盘
    for (uint32_t i = 0; i < BOARD_SIZE; i++)
    {
        for (uint32_t j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = DOT_MARK;
        }
    }

    wchar_t control = L'y';

    int game_over = 0;

    while ((control == L'y' || control == L'Y') && !game_over)
    {
        // 清屏
#ifdef _WIN32
        system("cls");
#else
        wprintf(L"\033[2J\033[1;1H");
#endif
        // 渲染棋盘
        for (uint32_t i = 0; i < BOARD_SIZE; i++)
        {
            for (uint32_t j = 0; j < BOARD_SIZE; j++)
            {
                wprintf(L"%lc", board[i][j]);
            }
            wprintf(L"\n");
        }

        wprintf(L"玩家 %lc 请输入坐标 (0 - %d), 中间用空格隔开:\n", current_player, BOARD_SIZE - 1);

        // 全部宽字符IO
        if (wscanf(L" %" SCNu8 " %" SCNu8, &x, &y) != 2)
        {
            flush_wbuf();
            wprintf(L"无效输入, 请重新输入.\n");
#ifdef _WIN32
            system("pause");
#else
            wprintf(L"\n按回车继续...");
            wscanf(L" %*lc");
#endif
            continue;
        }

        // 边界, 空位校验 board[x][y] 行y, 列x
        if (x < BOARD_SIZE && y < BOARD_SIZE && board[y][x] == DOT_MARK)
        {
            board[y][x] = current_player;

            // 判断胜利
            if (check_win(board, y, x, current_player))
            {
#ifdef _WIN32
                system("cls");
#else
                wprintf(L"\033[2J\033[1;1H");
#endif
                // 渲染胜利局面
                for (uint32_t i = 0; i < BOARD_SIZE; i++)
                {
                    for (uint32_t j = 0; j < BOARD_SIZE; j++)
                    {
                        wprintf(L"%lc", board[i][j]);
                    }
                    wprintf(L"\n");
                }
                wprintf(L"玩家 %lc 获得胜利! 游戏结束!\n", current_player);
                game_over = 1;
                break;
            }

            // 判断和棋
            if (is_board_full(board))
            {
                wprintf(L"棋盘已满, 双方和棋!\n");
                game_over = 1;
                break;
            }
            // 切换玩家
            current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
        }
        else
        {
            wprintf(L"无效的落子, 请重试!\n");
#ifdef _WIN32
            system("pause");
#else
            wprintf(L"\n按回车继续...\n");
#endif
            continue;
        }

        wprintf(L"是否继续? (y/n)");
        flush_wbuf();
        wscanf(L" %lc", &control);
    }

    wprintf(L"游戏结束!\n");

#ifdef _WIN32
            system("pause");
#else
            wprintf(L"\n按回车继续...\n");
#endif

    return EXIT_SUCCESS;
}

/**
 * @brief 胜负判断, 落子(y, x)位置, 判断该玩家是否五连
 *
 * @param board 棋盘
 * @param y 行
 * @param x 列
 * @param player 当前气质
 * @return 1胜利, 0未胜利
 */
int check_win(wchar_t board[BOARD_SIZE][BOARD_SIZE], uint8_t y, uint8_t x, wchar_t player)
{
    for (int d = 0; d < 4; d++)
    {
        int cnt = 1;
        int dy = dirs[d][0];
        int dx = dirs[d][1];

        // 正向延伸
        for (int k = 1; k < 5; k++)
        {
            int ny = y + dy * k;
            int nx = x + dx * k;
            if (ny >= 0 && ny < BOARD_SIZE && nx >= 0 && nx < BOARD_SIZE && board[ny][nx] == player)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        // 反向延伸
        for (int k = 1; k < 5; k++)
        {
            int ny = y - dy * k;
            int nx = x - dx * k;
            if (ny >= 0 && ny < BOARD_SIZE && nx >= 0 && nx < BOARD_SIZE && board[ny][nx] == player)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        if (cnt >= 5)
        {
            return 1;
        }
    }

    return 0;
}

/**
 *  @brief 判断棋盘是否已满, 和棋
 */
int is_board_full(wchar_t board[BOARD_SIZE][BOARD_SIZE])
{
    for (uint32_t i = 0; i < BOARD_SIZE; i++)
    {
        for (uint32_t j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == DOT_MARK)
            {
                return 0;
            }
        }
    }
    return 1;
}

// 宽字符清空输入缓冲区
static void flush_wbuf(void)
{
    wint_t ch;
    while ((ch = getwchar()) != L'\n' && ch != WEOF);
}

