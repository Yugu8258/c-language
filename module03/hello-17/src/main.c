#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t num);

int main(void)
{
    uint8_t status = 0b00001100; // 初始状态

    printf("Initial status: 0b");
    print_binary(status);
    printf("\t(Binary)\n");

    status = status & 0b11111011;

    printf("关闭低电量灯: 0b");
    print_binary(status);
    printf("\t(Binary)\n");

    status = status ^ 0b00001011;
    printf("一切正常: 0b");
    print_binary(status);
    printf("\t(Binary)\n");

    return 0;
}

void print_binary(uint8_t num)
{
    for (int index = 7; index >= 0; index--)
    {
        printf("%d", (num >> index) & 1);
    }
}

