#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // boolean -> 占用一个字节
    // bool 布尔(true, falsE)(真, 假)

    bool is_game_over = false;
    bool is_game_won = true;

    printf("is_game_over: %d\n", (int)is_game_over);
    printf("is_game_won: %d\n", (int)is_game_won);

    return 0;
}

