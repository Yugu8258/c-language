#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 二维数组
    uint32_t numbers_arr[5][5] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7},
        {4, 5, 6, 7, 8},
        {5, 6, 7, 8, 9},
    };

    // 遍历
    for (uint32_t i = 0; i < 5; i++)
    {
        for (uint32_t j = 0; j < 5; j++)
        {
            printf("%" PRIu32 " ", numbers_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

