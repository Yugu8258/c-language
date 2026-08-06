#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // for
    const uint32_t total_laps = 10;

    puts("跑步者开始跑步");

    for (size_t i = 1; i <= total_laps; i++)
    {
        printf("跑步者完成第%-2" PRIuPTR "圈.\n", i);
    }

    puts("跑步者跑步完成!");

    return 0;
}

