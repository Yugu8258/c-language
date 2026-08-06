#include <stdio.h>

int main(void)
{
    const int NUM_TABLES = 3;       // 假如餐厅有3张桌子

    const int SEATS_PER_TABLE = 4;  // 假如每张桌子有四个座位

    // 外层循环遍历 每张桌子
    for (int table_num = 1; table_num <= NUM_TABLES; table_num++)
    {
        printf("桌子编号: %d\n", table_num);

        // 内层循环遍历 当前桌子的每个位置
        for (int seat_num = 1; seat_num <= SEATS_PER_TABLE; seat_num++)
        {
            printf("\t座位编号: %d\n", seat_num);
        }
    }

    return 0;
}

