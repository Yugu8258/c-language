#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>

int main(void)
{
    /**
     * 案例: 进度条
     */

    const uint32_t total_steps = 100; // 总步长数, 进度条长度

    puts("处理中, 请稍后:");

    for (uint32_t i = 0; i <= total_steps; i++)
    {
        printf("\r[");

        // 打印进度条的完整部分
        for (uint32_t j = 0; j < i; j++)
        {
            printf("#");
        }

        for (uint32_t j = i; j < total_steps; j++)
        {
            printf(" ");
        }

        // (已经传输的数据量 / 文件总大小) * 100%
        printf("] %" PRIu32 "%%", (i * 100U) / total_steps);

        // 行缓冲, 强制刷出
        fflush(stdout); // 确保进度条及时显示

        // 模拟加载
        sleep(1);
    }

    putchar('\n'); // 换行, 把光标挪到下一行
    puts("任务完成!");

    return 0;
}

