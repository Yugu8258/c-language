#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t number = 99;

    // if 语句
    if (number >= 100)
    {
        printf("这个树大于等于100\n");
    }

    // if-else
    if (number > 10)
    {
        printf("这个数大于10\n");
    } else
    {
        printf("这个树不大于10\n");
    }


    return 0;
}

