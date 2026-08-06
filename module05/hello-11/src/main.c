#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <termios.h>
#include <unistd.h>

int main(void)
{
    /**
     * 目的:
     *  计算从1到N(N是用户输入)的所有整数的平方和
     */

    uint32_t number; // 用户要输入的整数N

    uint64_t sum_of_squares = 0; // 平方求和的初始化

    puts("请输入一个整数N, 我们将计算从1到N的所有整数的平方和!");

    uint8_t ret;

    ret = scanf("%" PRIu32, &number);
    if (ret != 1)
    {
        fprintf(stderr, "输入不合法, 请输入正整数!\n");
        // 丢弃终端输入缓冲区
        // tcflush：清空终端内核缓冲区
        tcflush(STDIN_FILENO, TCIFLUSH);
    }

    // 用来计次的变量, 我们这个程序后续不会用到, 因此可以直接在for中的第一条语句定义初始化

    for (uint64_t index = 1U; index <= number; index++)
    {
        sum_of_squares += index * index; // 加上当前数的平方
    }

    printf("所有整数的平方和为: %" PRIu64 "\n", sum_of_squares);

    return 0;
}

